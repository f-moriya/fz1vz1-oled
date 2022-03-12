/*
 * fzlcd - Display controller for Casio FZ/VZ
 * Copyright (C) 2020 Dmitri Sytov <dmitrins@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include <util/delay.h>
#include <avr/io.h>
#include "main.h"
#include "display.h"

#define _(bit)   (1 << (bit))
#define _N(bit) ~(1 << (bit))

#define DATA_MASK ( _(PC0)|_(PC1)|_(PC2)|_(PC3) )
#define OP_MASK _(PD4)

#define DATA  nibbleflip[(~PINC) & DATA_MASK]
#define OP 	  !(PIND & OP_MASK)
#define CE 	  !(PIND & _(PD2))

/* eeprom addresses for the settings */
#define EEPROM_CONTRAST		(uint8_t *) 0x10
#define EEPROM_BRIGHTNESS	(uint8_t *) 0x20

volatile static uint8_t cmd_buf[64];
volatile static uint8_t cmd_state = CMD_IDLE;
volatile static uint8_t data_count = 0;
volatile static uint8_t cursor = 0;
volatile static uint8_t contrast;

static uint8_t colbyte, rowbyte, charbyte, data_len, operation;

static const uint8_t contrast_curve[16] = {0,1,2,3,4,5,5,6,6,7,7,7,8,8,8,8}; 
static const uint8_t brightness_curve[32] =  {0, 1,  2,  4,  6,  8, 10, 12, 14, 16, 20, 24, 28, 36, 44, 52, 60,
    70, 80, 90, 100, 110, 120, 130, 140, 165, 190, 215, 240, 255, 255};

static const uint8_t nibbleflip[16] = 
{0x00, 0x08, 0x04, 0x0C, 0x02, 0x0A, 0x06, 0x0E, 
    0x01, 0x09, 0x05, 0x0D, 0x03, 0x0B, 0x07, 0x0F};

int main(void) {
    DDRB = 0x00;
    PORTB = 0x00;

    DDRC = 0x00;
    PORTC = 0xFF;

    DDRD  = _(PD6); 
    PORTD = 0x00;

    EICRA |= _(ISC00); 		/* INT0 CE Change */
    EICRA |= _(ISC11) | _(ISC10);    /* INT1 CLK Rise */
    EIMSK |= _(INT0) | _(INT1);     /* Turns on INT0, INT1 */

    _delay_ms(60);

    spi_master_init();
    bl_init();
    display_init();
    display_clear();

    _delay_ms(10);

    uint8_t val;
    /* Recall last settings */ 
    val = eeprom_read_byte(EEPROM_BRIGHTNESS);
    display_contrast(brightness_curve[val]);

    _delay_ms(10);

    sei();

    while(1){
	if (cmd_state == CMD_READY){
	    /* Convert contrast command value from log to linear scale */
	    if(cmd_buf[CMD_CODE] == FZ_CONTRAST){
		contrast = contrast_curve[cmd_buf[CMD_ROWH]];
		if (contrast) {contrast = contrast + 24; goto set;}
		contrast = contrast_curve[cmd_buf[CMD_ROWL]];
		if (contrast) {contrast = contrast + 16; goto set;}
		contrast = contrast_curve[cmd_buf[CMD_COLH]];
		if (contrast) {contrast = contrast + 8;  goto set;}
		contrast = contrast_curve[cmd_buf[CMD_COLL]];
	    set: 
		/* The cursor position is used to choose parameters (e.g. Brightness or contrast for LCD) 
		   OLED has only brightness */
		cursor = get_cursor();
		if (cursor){
			display_contrast(brightness_curve[contrast]);
			eeprom_write_byte(EEPROM_BRIGHTNESS, contrast);
			eeprom_busy_wait();			
		}
		cmd_state = CMD_IDLE;
	    }
	}

	if (cmd_state == DATA_READY){
	    switch (cmd_buf[CMD_CODE]) {
		case FZ_GRAPHIC: 
		    data_len = data_count;
		    operation = cmd_buf[CMD_FLAGS] & 0x08;
		    colbyte = cmd_buf[CMD_COLL] & 0x0F;
		    colbyte |= (cmd_buf[CMD_COLH] << 4) & 0xF0;
		    rowbyte = cmd_buf[CMD_ROWL]& 0x0F;
		    rowbyte |= (cmd_buf[CMD_ROWH] << 4) & 0xF0;
		    if((cmd_buf[CMD_FLAGS] & 0x01) && rowbyte < 4)
			rowbyte += 4;
		    if (operation)
			display_new(rowbyte, colbyte, &(cmd_buf[CMD_DATA0]), data_len/2);
		    else
			display_xor(rowbyte, colbyte, &(cmd_buf[CMD_DATA0]), data_len/2);
		    cmd_state = CMD_IDLE;
		    data_count = 0;
		    break;

		case FZ_TEXT: 
		    colbyte = cmd_buf[CMD_COLL] & 0x0F;
		    colbyte |= (cmd_buf[CMD_COLH] << 4) & 0xF0;
		    rowbyte = cmd_buf[CMD_ROWL]& 0x0F;
		    rowbyte |= (cmd_buf[CMD_ROWH] << 4) & 0xF0;
		    charbyte = cmd_buf[CMD_DATA0]& 0x0F;
		    charbyte |= (cmd_buf[CMD_DATA1] << 4) & 0xF0;
		    display_char(rowbyte, colbyte, charbyte);
		    cmd_state = CMD_IDLE;
		    break;
	    }
	}
    }
}


/* CLK on Rise */
ISR (INT1_vect) {
    if (cmd_state == CMD_IDLE)
	return;
    cmd_buf[cmd_state] = DATA;
    cmd_state++;
    data_count++;
}

/* CE on Change*/
ISR (INT0_vect) {
    _delay_us(1);
    if(CE && OP)
	cmd_state = CMD_CODE;
    if(CE && !OP){
	cmd_state = CMD_DATA0;
	data_count = 0;
    }
    if(!CE && !OP){
	if (cmd_state < CMD_CMD)
	    cmd_state = CMD_READY;
	else
	    cmd_state = DATA_READY;
    }
}

