/*
 * display.c - Display routines
 * Copyright (C) 2020 Dmitri Sytov <dmitrins@gmail.com>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#include <avr/io.h>
#include <util/delay.h>
#include "display.h"
#include "font.h"

#define  HORIZONTAL_OFFSET    3 

#define RST     PB0
#define A0      PB1
#define WR      PB2
#define MOSI    PB3
#define MISO    PB4
#define SCK     PB5

#define LOAD    PD5
#define BL      PD6
#define CS      PD7

volatile static uint8_t text_mem[8][24] = {
	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
};

/* Get cursor position */
uint8_t get_cursor(void) {
	uint8_t i;
	
	for (i = 0; i < 8; i++)
		if (text_mem[i][0] == 0xEE)
			return i;
	return 0;
}

inline void spi_master_init(void) {
	DDRB  |= _(A0) | _(RST) | _(WR) | _(MOSI) | _(SCK);
	PORTB |= _(A0) | _(RST) | _(WR) | _(MOSI) | _(SCK);

	DDRD  |= _(CS)| _(LOAD);
	PORTD |= _(CS);

	SPCR  = _(SPE) | _(MSTR) | _(SPI2X);
	SPCR  &= _N(CPHA) & _N(CPOL);
}

#ifdef DISP_HC595 /* HC595 / Parallel PS=1 C86=0 */
void spi_write(uint8_t data) {
	PORTD &= _N(CS);
	SPDR = data;
	while(!(SPSR & _(SPIF)));
	PORTD |= _(LOAD);
	_delay_us(1);
	PORTB &= _N(WR); 
	_delay_us(1);
	PORTD &= _N(LOAD); 
	PORTB |= _(WR);
	PORTD |= _(CS);
}

#else /* SPI / Serial  PS=0 */
void spi_write(uint8_t data) {
	PORTD &= _N(CS);
	_delay_us(1);
	SPDR = data;
	while(!(SPSR & _(SPIF)));
	_delay_us(1);
	PORTD |= _(CS);
}
#endif

inline void bl_init(void) {
	DDRD   |= _(BL);
	OCR0A  = 128;
	TCCR0A |= _(COM0A1) | _(WGM01) | _(WGM00);
	TCCR0B |= _(CS01);
}

inline void display_reset(void){
	PORTB &= _N(RST); 
	_delay_ms(15);
	PORTB |= _(RST);
	_delay_ms(15);
}

void display_command(uint8_t data){
	PORTB &= _N(A0);
	spi_write(data);
}

void display_data(uint8_t data){
	PORTB |= _(A0);
	spi_write(data);
}

inline void display_init(void){
	display_reset();

	display_command(0xAE); // Display Off

	display_command(0xAD); // Master Configuration
	display_command(0x8E); // Select external VCC supply

	display_command(0xA8); // Select Multiplex Ratio
	display_command(0x3F); // Default => 0x3F (1/64 Duty) 0x1F(1/32 Duty)

	display_command(0xD3); //Setting Display Offset
	display_command(0x00); //00H Reset

	display_command(0x10); //Set Column Address MSB
	display_command(0x00); //Set Column Address LSB

	display_command(0x40); //Set Display Start Line
	display_command(0x00); //;Set Memory Addressing Mode Default => 0x02
			   //0x00 => Horizontal Addressing Mode

	display_command(0xA6); //Set Normal Display
//	display_command(0xA7); //Set Inverse Display

	display_command(0xDB); //Set Deselect Vcomh level
	display_command(0x3C); //~0.83xVCC

	display_command(0xA4); //Entire Display ON
	
	display_command(0x81); //Set Contrast Control for Bank 0
	display_command(0x6F);

	display_command(0xD5); //SET DISPLAY CLOCK
	display_command(0xF0); //105HZ

	display_command(0xD8); //Select Area color ON/OFF
	display_command(0x05); //MONO Mode and Low Power display Mode

	display_command(0xDA); //Set COM Hardware Configuration
	display_command(0x12); //Alternative COM Pin

	display_command(0xD9); //Set Pre-Charge period
	display_command(0xF2); //Refer to SPEC 34PAGE
	display_command(0xFF); //

	display_command(0xAF); // Display ON
	display_command(0xC8);
	display_command(0xA0);
	//0xC8 (0x08) => Scan from COM63 to 0
	//0xA1 (0x01) => Column Address 0 Mapped to SEG131
}

void display_contrast(uint8_t val){
	display_command(OLED_VOLUME);
	display_command(val);
	display_command(OLED_STARTLINESET | 0);	
}

void display_brightness(uint8_t val){
	OCR0A = val;
}

void display_clear(void){
	uint8_t x, y; 
	for(y = 0; y < 8; ++y){
		display_command(OLED_PAGEADDRSET | y);
		display_command(OLED_COLUMNADDRSETH | 0);
		display_command(OLED_COLUMNADDRSETL | 0);
		for(x = 0; x < 128; ++x){
			display_data(0);
		}
	}
}

void display_char(uint8_t row, uint8_t col, uint8_t data){
	uint8_t col1 = col >> 1;
	uint8_t column = (col >> 1) & _(6)? col1 : col1 + 16; 	/* remove column address gap in the middle */
	column += HORIZONTAL_OFFSET;

	display_command(OLED_PAGEADDRSET | (7-row));
	display_command(OLED_COLUMNADDRSETH | ((column >> 4) & 0x0F));
	display_command(OLED_COLUMNADDRSETL | (column & 0x0F));

	uint8_t x;
	for (x = 0; x < 6; x++){
		display_data(pgm_read_byte_near(&(font[data][x])));
	}
	text_mem[row][col/12] = data;
	display_command(OLED_STARTLINESET | 0);
}

void display_new(uint8_t row, uint8_t col, volatile uint8_t* data, uint8_t len){
	uint8_t col1 = col >> 1;
	uint8_t column = col1 & _(6)? col1 : col1 + 16;
	column += HORIZONTAL_OFFSET;

	display_command(OLED_PAGEADDRSET | (7-row));
	display_command(OLED_COLUMNADDRSETH | ((column >> 4) & 0x0F));
	display_command(OLED_COLUMNADDRSETL | (column & 0x0F));

	uint8_t x;
	for (x = 0; x < len; x++)
		display_data(data[x*2 + 1] | (data[x*2] << 4));
}

void display_xor(uint8_t row, uint8_t col, volatile uint8_t* data, uint8_t len){
	uint8_t col1 = col >> 1;
	uint8_t column = col1 & _(6)? col1 : col1 + 16;
	column += HORIZONTAL_OFFSET;

	display_command(OLED_PAGEADDRSET | (7-row));
	display_command(OLED_COLUMNADDRSETH | ((column >> 4) & 0x0F));
	display_command(OLED_COLUMNADDRSETL | (column & 0x0F));
	uint8_t ch = text_mem[row][col/12];

	uint8_t x;
	for (x = 0; x < 6; x++){
		display_data(pgm_read_byte_near(&(font[ch][x])) ^ (data[x*2 + 1] | (data[x*2] << 4)));
	}
}
