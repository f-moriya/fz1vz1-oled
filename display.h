/*
 * display.h - Display routines
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

#include <inttypes.h>

#define   COM_NORMAL    0x00 
#define   COM_REVERSE   0x08 

#define   ON     		1 
#define   OFF    		0 
#define   OLED_VOLUME 			    0x81	/* The Electronic Volume Mode Set. Followed by register value byte 		 */

#define   OLED_STARTLINESET 		0x40	/* Set start line address (OR with line number). 		 */
#define   OLED_PAGEADDRSET		    0xB0 	/* Set page address to write to (OR with page number). 	 */
#define   OLED_COLUMNADDRSETH		0x10 	/* Set column address high nibble (OR with high nibble). */
#define   OLED_COLUMNADDRSETL		0x00 	/* Set column address low nibble (OR with low nibble). 	 */
#define   OLED_COLUMNREVERSE	    0xA0    /* Reverse column scan direction (OR with ON or OFF). 	 */
#define   OLED_COMMONREVERSE	    0xC0    /* Reverse omon scan direction (OR with COM_NORMAL or COM_REVERSE). */

#define   OLED_DISPLAYINVERSE		0xA6    /* Inverse all display points (OR with ON or OFF). */
#define   OLED_SETALLPOINTS	    	0xA4    /* Set all points ignoring data and inversion (OR with ON or OFF). */

#define _(bit) (1 << (bit))
#define _N(bit) ~(1 << (bit))

uint8_t get_cursor(void);

void spi_master_init(void);
void spi_write(uint8_t data);

void bl_init(void);

void display_reset(void);
void display_command(uint8_t data);
void display_data(uint8_t data);

void display_init(void);
void display_contrast(uint8_t val);
void display_brightness(uint8_t val);
void display_clear(void);

void display_char(uint8_t row, uint8_t col, uint8_t data);
void display_new(uint8_t row, uint8_t col, volatile uint8_t* data, uint8_t len);
void display_xor(uint8_t row, uint8_t col, volatile uint8_t* data, uint8_t len);
