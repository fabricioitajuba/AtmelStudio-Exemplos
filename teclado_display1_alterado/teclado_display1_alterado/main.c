/*
 * teclado_display1_alterado.c
 *
 * Created: 24/10/2022 09:28:38
 * Author : Fabrício Ribeiro
 */ 

#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>
#include "bibliotecas/lcd.h"
#include "bibliotecas/mat_kbrd.h"

int main(void)
{
	char key;
	int i=0;
	
	lcd_init(LCD_DISP_ON_CURSOR_BLINK);
	kbrd_init();
	
	lcd_puts("Digite tecla:");
	lcd_gotoxy(0, 1);
	
	while (1)
	{
		key = kbrd_read(LOOP);
		lcd_putc(key);
		
		i++;
		if(i == 16){
			_delay_ms(1000);
			i=0;
			lcd_gotoxy(0, 1);
			lcd_puts("                ");
			lcd_gotoxy(0, 1);
		}
	}
}


