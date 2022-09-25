CROSS_COMPILE=arm-linux-gnueabihf-
CC=$(CROSS_COMPILE)gcc
LD=$(CROSS_COMPILE)ld
OBJCOPY=$(CROSS_COMPILE)objcopy
OBJDUMP=$(CROSS_COMPILE)objdump

morse.bin : start.s beep.c clock.c led.c main.c morse.c
	$(CC) -c start.s -o start.o
	$(CC) -c beep.c -o beep.o
	$(CC) -c clock.c -o clock.o
	$(CC) -c led.c -o led.o
	$(CC) -c main.c -o main.o
	$(CC) -c morse.c -o morse.o
	$(LD) -Tmorse.lds start.o beep.o clock.o led.o morse.o main.o -o morse.elf
	$(OBJCOPY) -O binary -S -g morse.elf morse.bin
	$(OBJDUMP) -D morse.elf > morse.dis

clean:
	-rm *.o *.elf *.bin *.dis