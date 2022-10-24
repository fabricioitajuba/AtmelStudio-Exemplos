/*
 * teclado_display1.c
 *
 * Created: 24/10/2022 07:40:59
 * Author : Desenvolvimento
 */ 

#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>
#include "bibliotecas/lcd.h"
#include "bibliotecas/mat_kbrd.h"

int main(void)
{
    char key;
	int i;
	
	lcd_init(LCD_DISP_ON);
	kbrd_init();
	lcd_home();
	lcd_puts("Practica");
	_delay_ms(50);
	lcd_clrscr();
	
    while (1)
    {
		key = kbrd_read();
		if(key != 0){
			lcd_gotoxy(i,0);
			lcd_putc(key);
			i++;
		}
    }
}

