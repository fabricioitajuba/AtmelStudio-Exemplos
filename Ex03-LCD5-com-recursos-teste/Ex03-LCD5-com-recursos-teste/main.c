/*
 * Ex03 - LCD5 - com recursos - teste.c
 *
 * Created: 17/10/2022 14:54:23
 * Author : Fabrício Ribeiro
 */ 

#define  F_CPU 2000000UL //F_CPU = Fxtal/8 = 16MHz/8 = 2MHz se for usar outro clock, alterar a linha #define XTAL 2000000 em lcd.h
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
	
	printf("Hello World!!");
	lcd_gotoxy(0, 1);
	printf("n=%2.2f", n);

	_delay_ms(1000);

	lcd_clrscr();
	
	printf("teste");
	lcd_gotoxy(0, 1);
	printf("display");
		
	while(1)
	{

	}
}

