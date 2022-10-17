/*
 * Ex03 - LCD5 - com recursos - teste.c
 *
 * Created: 17/10/2022 14:54:23
 * Author : Fabrício Ribeiro
 */ 

#define F_CPU 16000000ul
#include <avr/io.h>
#include <stdio.h>
#include "Lcdlbr/lcd.h"

int   outlcd(char c, FILE *stream);
FILE mystdout = FDEV_SETUP_STREAM(outlcd, NULL, _FDEV_SETUP_WRITE);

int outlcd(char c, FILE *stream){
	lcd_putc(c);
	return 0;
}

int main(void)
{
	float n=3.1415;

	lcd_init(LCD_DISP_ON_CURSOR_BLINK);
	stdout = &mystdout;
	
	printf("Hello World!!");
	printf("\nn=%2.2f", n);

	while(1)
	{
		//TODO:: Just sit here forever
	}
}

