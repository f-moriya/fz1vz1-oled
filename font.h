/*
 * font.h - FZ-1 6x8 LCD font
 */

#ifndef FONT_H
#define FONT_H

#include <inttypes.h>
#include <avr/pgmspace.h>

const uint8_t font[256][6] PROGMEM = 
{
{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },  /* 00 */
{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },  /* 01 */
{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },  /* 02 */
{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },  /* 03 */
{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },  /* 04 */
{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },  /* 05 */
{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },  /* 06 */
{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },  /* 07 */
{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },  /* 08 */
{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },  /* 09 */
{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },  /* 0A */
{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },  /* 0B */
{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },  /* 0C */
{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },  /* 0D */
{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },  /* 0E */
{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },  /* 0F */
{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },  /* 10 */
{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },  /* 11 */
{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },  /* 12 */
{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },  /* 13 */
{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },  /* 14 */
{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },  /* 15 */
{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },  /* 16 */
{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },  /* 17 */
{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },  /* 18 */
{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },  /* 19 */
{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },  /* 1A */
{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },  /* 1B */
{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },  /* 1C */
{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },  /* 1D */
{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },  /* 1E */
{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },  /* 1F */
{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },  /* 20 */
{ 0x00, 0x00, 0xf2, 0x00, 0x00, 0x00 },  /* 21 */
{ 0x00, 0xe0, 0x00, 0xe0, 0x00, 0x00 },  /* 22 */
{ 0x28, 0xfe, 0x28, 0xfe, 0x28, 0x00 },  /* 23 */
{ 0x24, 0x54, 0xfe, 0x54, 0x48, 0x00 },  /* 24 */
{ 0xc4, 0xc8, 0x10, 0x26, 0x46, 0x00 },  /* 25 */
{ 0x6c, 0x92, 0x6a, 0x04, 0x1a, 0x00 },  /* 26 */
{ 0x00, 0xa0, 0xc0, 0x00, 0x00, 0x00 },  /* 27 */
{ 0x00, 0x38, 0x44, 0x82, 0x00, 0x00 },  /* 28 */
{ 0x00, 0x82, 0x44, 0x38, 0x00, 0x00 },  /* 29 */
{ 0x28, 0x10, 0x7c, 0x10, 0x28, 0x00 },  /* 2A */
{ 0x10, 0x10, 0x7c, 0x10, 0x10, 0x00 },  /* 2B */
{ 0x00, 0x05, 0x06, 0x00, 0x00, 0x00 },  /* 2C */
{ 0x10, 0x10, 0x10, 0x10, 0x10, 0x00 },  /* 2D */
{ 0x00, 0x06, 0x06, 0x00, 0x00, 0x00 },  /* 2E */
{ 0x04, 0x08, 0x10, 0x20, 0x40, 0x00 },  /* 2F */
{ 0x7c, 0x8a, 0x92, 0xa2, 0x7c, 0x00 },  /* 30 */
{ 0x00, 0x42, 0xfe, 0x02, 0x00, 0x00 },  /* 31 */
{ 0x42, 0x86, 0x8a, 0x92, 0x62, 0x00 },  /* 32 */
{ 0x84, 0x82, 0xa2, 0xd2, 0x8c, 0x00 },  /* 33 */
{ 0x18, 0x28, 0x48, 0xfe, 0x08, 0x00 },  /* 34 */
{ 0xe4, 0xa2, 0xa2, 0xa2, 0x9c, 0x00 },  /* 35 */
{ 0x3c, 0x52, 0x92, 0x92, 0x0c, 0x00 },  /* 36 */
{ 0x80, 0x8e, 0x90, 0xa0, 0xc0, 0x00 },  /* 37 */
{ 0x6c, 0x92, 0x92, 0x92, 0x6c, 0x00 },  /* 38 */
{ 0x60, 0x92, 0x92, 0x94, 0x78, 0x00 },  /* 39 */
{ 0x00, 0x6c, 0x6c, 0x00, 0x00, 0x00 },  /* 3A */
{ 0x00, 0x6a, 0x6c, 0x00, 0x00, 0x00 },  /* 3B */
{ 0x10, 0x28, 0x44, 0x82, 0x00, 0x00 },  /* 3C */
{ 0x28, 0x28, 0x28, 0x28, 0x28, 0x00 },  /* 3D */
{ 0x00, 0x82, 0x44, 0x28, 0x10, 0x00 },  /* 3E */
{ 0x40, 0x80, 0x8a, 0x90, 0x60, 0x00 },  /* 3F */
{ 0x4c, 0x92, 0x9e, 0x82, 0x7c, 0x00 },  /* 40 */
{ 0x7e, 0x90, 0x90, 0x90, 0x7e, 0x00 },  /* 41 */
{ 0xfe, 0x92, 0x92, 0x92, 0x6c, 0x00 },  /* 42 */
{ 0x7c, 0x82, 0x82, 0x82, 0x44, 0x00 },  /* 43 */
{ 0xfe, 0x82, 0x82, 0x44, 0x38, 0x00 },  /* 44 */
{ 0xfe, 0x92, 0x92, 0x92, 0x82, 0x00 },  /* 45 */
{ 0xfe, 0x90, 0x90, 0x90, 0x80, 0x00 },  /* 46 */
{ 0x7c, 0x82, 0x92, 0x92, 0x5e, 0x00 },  /* 47 */
{ 0xfe, 0x10, 0x10, 0x10, 0xfe, 0x00 },  /* 48 */
{ 0x00, 0x82, 0xfe, 0x82, 0x00, 0x00 },  /* 49 */
{ 0x04, 0x02, 0x82, 0xfc, 0x80, 0x00 },  /* 4A */
{ 0xfe, 0x10, 0x28, 0x44, 0x82, 0x00 },  /* 4B */
{ 0xfe, 0x02, 0x02, 0x02, 0x02, 0x00 },  /* 4C */
{ 0xfe, 0x40, 0x30, 0x40, 0xfe, 0x00 },  /* 4D */
{ 0xfe, 0x20, 0x10, 0x08, 0xfe, 0x00 },  /* 4E */
{ 0x7c, 0x82, 0x82, 0x82, 0x7c, 0x00 },  /* 4F */
{ 0xfe, 0x90, 0x90, 0x90, 0x60, 0x00 },  /* 50 */
{ 0x7c, 0x82, 0x8a, 0x84, 0x7a, 0x00 },  /* 51 */
{ 0xfe, 0x90, 0x98, 0x94, 0x62, 0x00 },  /* 52 */
{ 0x64, 0x92, 0x92, 0x92, 0x4c, 0x00 },  /* 53 */
{ 0x80, 0x80, 0xfe, 0x80, 0x80, 0x00 },  /* 54 */
{ 0xfc, 0x02, 0x02, 0x02, 0xfc, 0x00 },  /* 55 */
{ 0xf8, 0x04, 0x02, 0x04, 0xf8, 0x00 },  /* 56 */
{ 0xfc, 0x02, 0x1c, 0x02, 0xfc, 0x00 },  /* 57 */
{ 0xc6, 0x28, 0x10, 0x28, 0xc6, 0x00 },  /* 58 */
{ 0xe0, 0x10, 0x0e, 0x10, 0xe0, 0x00 },  /* 59 */
{ 0x86, 0x8a, 0x92, 0xa2, 0xc2, 0x00 },  /* 5A */
{ 0x00, 0xfe, 0x82, 0x82, 0x00, 0x00 },  /* 5B */
{ 0xa8, 0x68, 0x3e, 0x68, 0xa8, 0x00 },  /* 5C */
{ 0x00, 0x82, 0x82, 0xfe, 0x00, 0x00 },  /* 5D */
{ 0x20, 0x40, 0x80, 0x40, 0x20, 0x00 },  /* 5E */
{ 0x02, 0x02, 0x02, 0x02, 0x02, 0x00 },  /* 5F */
{ 0x00, 0xc0, 0xa0, 0x00, 0x00, 0x00 },  /* 60 */
{ 0x04, 0x2a, 0x2a, 0x2a, 0x1c, 0x02 },  /* 61 */
{ 0xfe, 0x12, 0x22, 0x22, 0x1c, 0x00 },  /* 62 */
{ 0x1c, 0x22, 0x22, 0x22, 0x04, 0x00 },  /* 63 */
{ 0x1c, 0x22, 0x22, 0x12, 0xfe, 0x00 },  /* 64 */
{ 0x1c, 0x2a, 0x2a, 0x2a, 0x18, 0x00 },  /* 65 */
{ 0x00, 0x20, 0x7e, 0xa0, 0x80, 0x00 },  /* 66 */
{ 0x18, 0x25, 0x25, 0x25, 0x3e, 0x00 },  /* 67 */
{ 0xfe, 0x10, 0x20, 0x20, 0x1e, 0x00 },  /* 68 */
{ 0x00, 0x22, 0xbe, 0x02, 0x00, 0x00 },  /* 69 */
{ 0x02, 0x01, 0x21, 0xbe, 0x00, 0x00 },  /* 6A */
{ 0x00, 0xfe, 0x08, 0x14, 0x22, 0x00 },  /* 6B */
{ 0x00, 0x82, 0xfe, 0x02, 0x00, 0x00 },  /* 6C */
{ 0x3e, 0x20, 0x1e, 0x20, 0x1e, 0x00 },  /* 6D */
{ 0x3e, 0x10, 0x20, 0x20, 0x1e, 0x00 },  /* 6E */
{ 0x1c, 0x22, 0x22, 0x22, 0x1c, 0x00 },  /* 6F */
{ 0x3f, 0x24, 0x24, 0x24, 0x18, 0x00 },  /* 70 */
{ 0x18, 0x24, 0x24, 0x24, 0x3f, 0x00 },  /* 71 */
{ 0x3e, 0x10, 0x20, 0x20, 0x10, 0x00 },  /* 72 */
{ 0x12, 0x2a, 0x2a, 0x2a, 0x24, 0x00 },  /* 73 */
{ 0x20, 0x7c, 0x22, 0x02, 0x04, 0x00 },  /* 74 */
{ 0x3c, 0x02, 0x02, 0x04, 0x3e, 0x00 },  /* 75 */
{ 0x30, 0x0c, 0x02, 0x0c, 0x30, 0x00 },  /* 76 */
{ 0x3c, 0x02, 0x0c, 0x02, 0x3c, 0x00 },  /* 77 */
{ 0x22, 0x24, 0x1c, 0x12, 0x22, 0x00 },  /* 78 */
{ 0x21, 0x11, 0x0a, 0x0c, 0x30, 0x00 },  /* 79 */
{ 0x22, 0x26, 0x2a, 0x32, 0x22, 0x00 },  /* 7A */
{ 0x10, 0x6c, 0x82, 0x00, 0x00, 0x00 },  /* 7B */
{ 0x00, 0x00, 0xee, 0x00, 0x00, 0x00 },  /* 7C */
{ 0x00, 0x00, 0x82, 0x6c, 0x10, 0x00 },  /* 7D */
{ 0x40, 0x80, 0x40, 0x20, 0x40, 0x00 },  /* 7E */
{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },  /* 7F */
{ 0x01, 0x01, 0x01, 0x01, 0x01, 0x01 },  /* 80 */
{ 0x03, 0x03, 0x03, 0x03, 0x03, 0x03 },  /* 81 */
{ 0x07, 0x07, 0x07, 0x07, 0x07, 0x07 },  /* 82 */
{ 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f },  /* 83 */
{ 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f },  /* 84 */
{ 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f },  /* 85 */
{ 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f },  /* 86 */
{ 0xff, 0xff, 0xff, 0xff, 0xff, 0xff },  /* 87 */
{ 0xff, 0x00, 0x00, 0x00, 0x00, 0x00 },  /* 88 */
{ 0xff, 0x00, 0x00, 0x00, 0x00, 0x00 },  /* 89 */
{ 0xff, 0x00, 0x00, 0x00, 0x00, 0x00 },  /* 8A */
{ 0xff, 0xff, 0x00, 0x00, 0x00, 0x00 },  /* 8B */
{ 0xff, 0xff, 0xff, 0x00, 0x00, 0x00 },  /* 8C */
{ 0xff, 0xff, 0xff, 0xff, 0x00, 0x00 },  /* 8D */
{ 0xff, 0xff, 0xff, 0xff, 0xff, 0x00 },  /* 8E */
{ 0x10, 0x10, 0x10, 0xff, 0x10, 0x10 },  /* 8F */
{ 0x10, 0x10, 0x10, 0xf0, 0x10, 0x10 },  /* 90 */
{ 0x10, 0x10, 0x10, 0x1f, 0x10, 0x10 },  /* 91 */
{ 0x10, 0x10, 0x10, 0xff, 0x00, 0x00 },  /* 92 */
{ 0x00, 0x00, 0x00, 0xff, 0x10, 0x10 },  /* 93 */
{ 0x80, 0x80, 0x80, 0x80, 0x80, 0x80 },  /* 94 */
{ 0x10, 0x10, 0x10, 0x10, 0x10, 0x10 },  /* 95 */
{ 0x00, 0x00, 0x00, 0xff, 0x00, 0x00 },  /* 96 */
{ 0x00, 0x00, 0x00, 0x00, 0x00, 0xff },  /* 97 */
{ 0x00, 0x00, 0x00, 0x1f, 0x10, 0x10 },  /* 98 */
{ 0x10, 0x10, 0x10, 0x1f, 0x00, 0x00 },  /* 99 */
{ 0x00, 0x00, 0x00, 0xf0, 0x10, 0x10 },  /* 9A */
{ 0x10, 0x10, 0x10, 0xf0, 0x00, 0x00 },  /* 9B */
{ 0x00, 0x00, 0x00, 0x07, 0x08, 0x10 },  /* 9C */
{ 0x10, 0x10, 0x08, 0x07, 0x00, 0x00 },  /* 9D */
{ 0x00, 0x00, 0x00, 0xc0, 0x20, 0x10 },  /* 9E */
{ 0x10, 0x10, 0x20, 0xc0, 0x00, 0x00 },  /* 9F */
{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },  /* A0 */
{ 0x0e, 0x0a, 0x0e, 0x00, 0x00, 0x00 },  /* A1 */
{ 0x00, 0x00, 0xf0, 0x80, 0x80, 0x00 },  /* A2 */
{ 0x02, 0x02, 0x1e, 0x00, 0x00, 0x00 },  /* A3 */
{ 0x08, 0x04, 0x02, 0x00, 0x00, 0x00 },  /* A4 */
{ 0x00, 0x00, 0x18, 0x18, 0x00, 0x00 },  /* A5 */
{ 0x50, 0x50, 0x52, 0x54, 0x78, 0x00 },  /* A6 */
{ 0x20, 0x22, 0x2c, 0x28, 0x30, 0x00 },  /* A7 */
{ 0x04, 0x08, 0x1e, 0x20, 0x00, 0x00 },  /* A8 */
{ 0x18, 0x10, 0x32, 0x12, 0x1c, 0x00 },  /* A9 */
{ 0x12, 0x12, 0x1e, 0x12, 0x12, 0x00 },  /* AA */
{ 0x12, 0x14, 0x18, 0x3e, 0x10, 0x00 },  /* AB */
{ 0x10, 0x3e, 0x10, 0x14, 0x18, 0x00 },  /* AC */
{ 0x02, 0x12, 0x12, 0x1e, 0x02, 0x00 },  /* AD */
{ 0x2a, 0x2a, 0x2a, 0x3e, 0x00, 0x00 },  /* AE */
{ 0x18, 0x00, 0x1a, 0x02, 0x1c, 0x00 },  /* AF */
{ 0x10, 0x10, 0x10, 0x10, 0x10, 0x00 },  /* B0 */
{ 0x80, 0x82, 0xbc, 0x90, 0xe0, 0x00 },  /* B1 */
{ 0x08, 0x10, 0x3e, 0x40, 0x80, 0x00 },  /* B2 */
{ 0x70, 0x40, 0xc2, 0x44, 0x78, 0x00 },  /* B3 */
{ 0x42, 0x42, 0x7e, 0x42, 0x42, 0x00 },  /* B4 */
{ 0x44, 0x48, 0x50, 0xfe, 0x40, 0x00 },  /* B5 */
{ 0x42, 0xfc, 0x40, 0x42, 0x7c, 0x00 },  /* B6 */
{ 0x50, 0x50, 0xfe, 0x50, 0x50, 0x00 },  /* B7 */
{ 0x10, 0x62, 0x42, 0x44, 0x78, 0x00 },  /* B8 */
{ 0x10, 0xe0, 0x42, 0x7c, 0x40, 0x00 },  /* B9 */
{ 0x42, 0x42, 0x42, 0x42, 0x7e, 0x00 },  /* BA */
{ 0x40, 0xf2, 0x44, 0xf8, 0x40, 0x00 },  /* BB */
{ 0x52, 0x52, 0x02, 0x04, 0x38, 0x00 },  /* BC */
{ 0x42, 0x44, 0x48, 0x54, 0x62, 0x00 },  /* BD */
{ 0x40, 0xfc, 0x42, 0x52, 0x62, 0x00 },  /* BE */
{ 0x60, 0x12, 0x02, 0x04, 0x78, 0x00 },  /* BF */
{ 0x10, 0x62, 0x52, 0x4c, 0x78, 0x00 },  /* C0 */
{ 0x50, 0x52, 0x7c, 0x90, 0x10, 0x00 },  /* C1 */
{ 0x70, 0x00, 0x72, 0x04, 0x78, 0x00 },  /* C2 */
{ 0x20, 0xa2, 0xbc, 0xa0, 0x20, 0x00 },  /* C3 */
{ 0x00, 0xfe, 0x10, 0x08, 0x00, 0x00 },  /* C4 */
{ 0x22, 0x24, 0xf8, 0x20, 0x20, 0x00 },  /* C5 */
{ 0x02, 0x42, 0x42, 0x42, 0x02, 0x00 },  /* C6 */
{ 0x42, 0x54, 0x48, 0x54, 0x60, 0x00 },  /* C7 */
{ 0x44, 0x48, 0xde, 0x68, 0x44, 0x00 },  /* C8 */
{ 0x00, 0x02, 0x04, 0xf8, 0x00, 0x00 },  /* C9 */
{ 0x1e, 0x00, 0x40, 0x20, 0x1e, 0x00 },  /* CA */
{ 0xfc, 0x22, 0x22, 0x22, 0x22, 0x00 },  /* CB */
{ 0x40, 0x42, 0x42, 0x44, 0x78, 0x00 },  /* CC */
{ 0x20, 0x40, 0x20, 0x10, 0x0c, 0x00 },  /* CD */
{ 0x4c, 0x40, 0xfe, 0x40, 0x4c, 0x00 },  /* CE */
{ 0x40, 0x48, 0x44, 0x4a, 0x70, 0x00 },  /* CF */
{ 0x04, 0x54, 0x54, 0x54, 0x02, 0x00 },  /* D0 */
{ 0x1c, 0x24, 0x44, 0x04, 0x0e, 0x00 },  /* D1 */
{ 0x02, 0x14, 0x08, 0x14, 0x60, 0x00 },  /* D2 */
{ 0x50, 0x7c, 0x52, 0x52, 0x52, 0x00 },  /* D3 */
{ 0x20, 0xfe, 0x20, 0x28, 0x30, 0x00 },  /* D4 */
{ 0x02, 0x42, 0x42, 0x7e, 0x02, 0x00 },  /* D5 */
{ 0x52, 0x52, 0x52, 0x52, 0x7e, 0x00 },  /* D6 */
{ 0x20, 0xa0, 0xa2, 0xa4, 0x38, 0x00 },  /* D7 */
{ 0xf0, 0x02, 0x04, 0xf8, 0x00, 0x00 },  /* D8 */
{ 0x3e, 0x00, 0x7e, 0x02, 0x1c, 0x00 },  /* D9 */
{ 0x7e, 0x02, 0x04, 0x08, 0x10, 0x00 },  /* DA */
{ 0x7e, 0x42, 0x42, 0x42, 0x7e, 0x00 },  /* DB */
{ 0x70, 0x40, 0x42, 0x44, 0x78, 0x00 },  /* DC */
{ 0x42, 0x42, 0x02, 0x04, 0x18, 0x00 },  /* DD */
{ 0x40, 0x20, 0x80, 0x40, 0x00, 0x00 },  /* DE */
{ 0xe0, 0xa0, 0xe0, 0x00, 0x00, 0x00 },  /* DF */
{ 0x28, 0x28, 0x28, 0x28, 0x28, 0x28 },  /* E0 */
{ 0x00, 0x00, 0x00, 0xff, 0x28, 0x28 },  /* E1 */
{ 0x28, 0x28, 0x28, 0xff, 0x28, 0x28 },  /* E2 */
{ 0x28, 0x28, 0x28, 0xff, 0x00, 0x00 },  /* E3 */
{ 0x01, 0x03, 0x07, 0x0f, 0x1f, 0x3f },  /* E4 */
{ 0x3f, 0x1f, 0x0f, 0x07, 0x03, 0x01 },  /* E5 */
{ 0x80, 0xc0, 0xe0, 0xf0, 0xf8, 0xfc },  /* E6 */
{ 0xfc, 0xf8, 0xf0, 0xe0, 0xc0, 0x80 },  /* E7 */
{ 0x18, 0x3a, 0x7e, 0x3a, 0x18, 0x00 },  /* E8 */
{ 0x38, 0x7c, 0x3e, 0x7c, 0x38, 0x00 },  /* E9 */
{ 0x18, 0x3c, 0x7e, 0x3c, 0x18, 0x00 },  /* EA */
{ 0x18, 0x7a, 0x7e, 0x7a, 0x18, 0x00 },  /* EB */
{ 0x38, 0x7c, 0x7c, 0x7c, 0x38, 0x00 },  /* EC */
{ 0x38, 0x44, 0x44, 0x44, 0x38, 0x00 },  /* ED */
{ 0x00, 0x28, 0xAA, 0x6C, 0x28, 0x10 },  /* EE - */
{ 0xc0, 0x20, 0x10, 0x08, 0x04, 0x03 },  /* EF */
{ 0xc3, 0x24, 0x18, 0x18, 0x24, 0xc3 },  /* F0 */
{ 0xfe, 0x90, 0xf0, 0x92, 0xfe, 0x00 },  /* F1 */
{ 0x24, 0xdc, 0x54, 0x7f, 0x54, 0x04 },  /* F2 */
{ 0x02, 0xfc, 0xa8, 0xaa, 0xfe, 0x00 },  /* F3 */
{ 0xfe, 0x92, 0x92, 0x92, 0xfe, 0x00 },  /* F4 */
{ 0x7c, 0x54, 0x7c, 0xaa, 0xff, 0xa8 },  /* F5 */
{ 0x21, 0x52, 0x9c, 0x91, 0x5e, 0x20 },  /* F6 */
{ 0xa8, 0xff, 0xa8, 0x11, 0xfe, 0x1c },  /* F7 */
{ 0x20, 0xa0, 0xbe, 0xa0, 0x20, 0x00 },  /* F8 */
{ 0x5e, 0x50, 0xff, 0x50, 0x5e, 0x00 },  /* F9 */
{ 0xfe, 0x86, 0xaa, 0x92, 0xaa, 0xc2 },  /* FA */
{ 0xf8, 0xf8, 0xf8, 0x41, 0x7f, 0x40 },  /* FB */
{ 0x58, 0xff, 0x50, 0x2c, 0x21, 0xff },  /* FC */
{ 0x02, 0x0c, 0xf0, 0x0c, 0x02, 0x00 },  /* FD */
{ 0xaa, 0x55, 0xaa, 0x55, 0xaa, 0x55 },  /* FE */
{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }   /* FF */
};

#endif				/* FONT_H */

