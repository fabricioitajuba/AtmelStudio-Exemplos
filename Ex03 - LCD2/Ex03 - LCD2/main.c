/*
 * Ex03 - LCD2.c
 *
 * Created: 27/09/2022 09:27:06
 * Author : Desenvolvimento
 */ 

#define  F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

#include "LCD16x2_4b.h"

int main(void)
{
    /* Replace with your application code */
	Lcd4_Init();
			
    while (1) 
    {
		Lcd4_Set_Cursor(1,0);
		Lcd4_Write_String("Zilocchi        ");
		Lcd4_Set_Cursor(2,0);
		Lcd4_Write_String("      Eletronica");
		_delay_ms(2000);
		Lcd4_Clear();
		
		Lcd4_Set_Cursor(1,0);
		Lcd4_Write_String("Teste           ");
		Lcd4_Set_Cursor(2,0);
		Lcd4_Write_String("         Display");
		_delay_ms(2000);
		Lcd4_Clear();
    }
}

