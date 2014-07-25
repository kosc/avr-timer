all:
	avr-gcc -DF_CPU=8000000UL -mmcu=atmega8 -I. -gdwarf-2 -Os -o main.o main.c
	avr-objcopy -O ihex main.o firmware.hex
	rm main.o
