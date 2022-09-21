/*
 * Ex04.cpp
 *
 * Created: 21/09/2022 07:39:20
 * Author : Desenvolvimento
 */ 

#define F_CPU 16000000UL // 16 MHz clock speed

#include <avr/io.h>
#include <util/delay.h>

//PB5 - Led da placa


int main(void)
{
    /* Replace with your application code */
	DDRB = 0b00100000; //Habilita o pino PB5 como saída
    while (1) 
    {
		PORTB = 0b00100000;	//PB5 = 1
		_delay_ms(100);
		PORTB = 0b00000000;	//PB5 = 0
		_delay_ms(100);
    }
}

