# Casio FZ1 Display controller firmware 
# Makefile
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; version 2 of the License.

# Target info
	NAME	= fz1oled
	VERSION = 0.1
	FIRMWARE = $(NAME)
	MCU = atmega88p
	FREQ = 16000000

# Toolchain path
	AVRGCCDIR = /usr/avr  

	CC	= avr-gcc
	AS	= avr-gcc 
	RM	= rm -f
	CP	= cp
	OBJCOPY	= avr-objcopy
	SIZE	= avr-size
	STRIP	= avr-strip
	INCDIR	= .
	LIBDIR	= $(AVRGCCDIR)/lib
	SHELL   = /bin/bash

# Programming tool 
	PRG	    = avrdude -c usbasp -Pusb -B10  
	PRG_FNAME   = $(FIRMWARE).hex
	PRG_MCU	    = $(MCU)
# ATmega88
	LFUSE		= 0xD6
	HFUSE		= 0xD9
	EFUSE		= 0xFC

# Debugger 
	DEBUGGER    = gdbtui 
	SIMULATOR   = simulavr -g -d $(MCU) -c $(FREQ)

# Sources and object files
	ASRC = 
	SRC	= main.c display.c
	OBJ	= $(ASRC:.s=.o) $(SRC:.c=.o)

# Flags
	DEFS = -DF_CPU=$(FREQ)
	DBGCFLAGS = -ggdb
	OPTCFLAGS = -O
	ASFLAGS = -Wa, -gstabs -I$(INCDIR) -I. -mmcu=$(MCU)
	CPFLAGS	= -g $(OPTCFLAGS) -fno-gcse -Wall -Wstrict-prototypes  -Wno-pointer-sign -I$(INCDIR) -I. -Wa,-ahlms=$(<:.c=.lst) -mmcu=$(MCU) $(DEFS)
	LDFLAGS = -Wl,-Map=$(FIRMWARE).map,--cref -mmcu=$(MCU)

# Target rules
all:  clean $(FIRMWARE).hex size prog

debug: OPTCFLAGS = $(DBGCFLAGS)
debug: clean $(FIRMWARE).elf
	$(SIMULATOR)
prog: $(PRG_FNAME)
	$(PRG) -p $(PRG_MCU) -U flash:w:$(PRG_FNAME) -F
fuse: $(PRG_FNAME)
	$(PRG) -p $(PRG_MCU) -U lfuse:w:$(LFUSE):m -U hfuse:w:$(HFUSE):m 
%.o: %.c 
	$(CC) -c $(CPFLAGS) -I$(INCDIR) $< -o $@
%.s: %.c
	$(CC) -S $(CPFLAGS) -I$(INCDIR) $< -o $@
%.o: %.s
	$(AS) -c $(ASFLAGS) -I$(INCDIR) $< -o $@
%.elf: $(OBJ)
	$(CC) $(OBJ) $(LIB) $(LDFLAGS) -o $@
%.obj: %.elf
	$(OBJCOPY) -O avrobj -R .eeprom $< $@
%.hex: %.elf
	$(STRIP) -s $<
	$(OBJCOPY) -O ihex -R .eeprom $< $@
size:
	$(SIZE) $(FIRMWARE).elf

%ok:
	@echo "Done" 
clean:
	$(RM) $(OBJ)
	$(RM) $(SRC:.c=.s)
	$(RM) $(SRC:.c=.lst)
	$(RM) $(FIRMWARE).map
	$(RM) $(FIRMWARE).elf
	$(RM) $(FIRMWARE).obj
	$(RM) $(FIRMWARE).hex
	$(RM) $(FIRMWARE).bin
	$(RM) *.log
	@echo "Done"

