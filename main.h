/* Casio FZ/VZ LCD controller
 *
 * Copyright (C) 2020 Dmitri Sytov
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

#ifndef MAIN_H
#define MAIN_H


#include <inttypes.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <avr/eeprom.h>

#define EN		    1
#define DIS 		0
#define TRUE		1
#define FALSE		0
#define FZ_GRAPHIC	0x02
#define FZ_TEXT 	0x03
#define FZ_CONTRAST	0x0C
#define FZ_RESET	0x0A

enum cmd_state_codes {
	CMD_IDLE   = 0x00,
	CMD_CODE   = 0x01,
	CMD_FLAGS  = 0x02,
	CMD_COLL   = 0x03,
	CMD_COLH   = 0x04,
	CMD_ROWL   = 0x05,
	CMD_ROWH   = 0x06,
	
	CMD_CMD    = 0x08,

	CMD_DATA0  = 0x10,
	CMD_DATA1  = 0x11,
	CMD_DATA2  = 0x12,
	CMD_DATA3  = 0x13,
	CMD_DATA4  = 0x14,
	CMD_DATA5  = 0x15,
	CMD_DATA6  = 0x16,
	CMD_DATA7  = 0x17,
	CMD_DATA8  = 0x18,
	CMD_DATA9  = 0x19,
	CMD_DATA10 = 0x1A,
	CMD_DATA11 = 0x1B,
	CMD_DATA12 = 0x1C,
	CMD_DATA13 = 0x1D,
	CMD_DATA14 = 0x1E,
	CMD_DATA15 = 0x1F,
	CMD_DATA16 = 0x20,
	CMD_DATA17 = 0x21,
	CMD_DATA18 = 0x22,
	CMD_DATA19 = 0x23,
	CMD_DATA20 = 0x24,
	CMD_DATA21 = 0x25,
	CMD_DATA22 = 0x26,
	CMD_DATA23 = 0x27,
	CMD_DATA24 = 0x28,
	
	CMD_MAX    = 0x3F,
	CMD_READY  = 0xFE,
	DATA_READY = 0xFF
};

#endif				/* MAIN_H */

