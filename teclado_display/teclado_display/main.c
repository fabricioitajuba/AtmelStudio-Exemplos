/*
 * teclado_display.c
 *
 * Created: 10/10/2022 14:00:18
 * Author : Fabrício Ribeiro
 */ 


#define  F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

#include "bibliotecas/gpio.h"
#include "bibliotecas/teclado4x4.h"
#include "bibliotecas/LCD16x2_4b.h"

int main(void)
{
    char tecla;

	teclado4x4_ini(_PC0, _PC1, _PC2, _PC3, _PB0, _PB1, _PB2, _PB3);
	Lcd4_Init(_PD6, _PD7, _PD5, _PD4, _PD3, _PD2);
	
    pinMode(_PC6, INPUT);
    pinMode(_PB5, OUTPUT);
	
    while (1)
    {
		tecla = le_teclado(LOOP);
	
		if(tecla == 0){
			Lcd4_Set_Cursor(2,0);
			Lcd4_Write_String("0");
			digitalWrite(_PB5, LOW);
		}
		else if(tecla == 1){
			Lcd4_Set_Cursor(2,0);
			Lcd4_Write_String("1");
			digitalWrite(_PB5, HIGH);
		}
    }
}

