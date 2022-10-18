/*
 * Ex03 - LCD6
 *
 * Created: 17/10/2022 14:54:23
 * Author : Fabrício Ribeiro
 */ 

#define  F_CPU 8000000UL
#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
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
		
	while(1)
	{
		printf("Hello World!!");
		printf("\nn=%2.2f", n);
		_delay_ms(1000);
		lcd_clrscr();
		
		printf("teste");
		printf("\ndisplay");
		_delay_ms(1000);
		lcd_clrscr();
	}
}
