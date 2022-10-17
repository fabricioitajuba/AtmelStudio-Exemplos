/*
 * Ex03 - LCD1.c
 *
 * Created: 27/09/2022 09:16:20
 * Author : Desenvolvimento
 */ 

#define F_CPU 16000000

#include <util/delay.h>
#include <avr/io.h>

#include "lcd-routines.h"

int main(void)
{
    /* Replace with your application code */
	lcd_init();
	lcd_setcursor(0,1);
	lcd_string("    Zilocchi    ");
	lcd_setcursor(0,2);
	lcd_string("   Eletronica   ");
    
	while (1) 
    {
    }
}

