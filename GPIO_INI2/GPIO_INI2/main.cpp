/*
 * GPIO_INI.cpp
 * Configuração simples dos GPIO'S
 * Created: 05/10/2022 09:37:56
 * Author : Fabrício Ribeiro
 * fonte: https://www.youtube.com/watch?v=FgVLt6sXmxI
 *        https://www.youtube.com/watch?v=A-ETcQ_rejU&list=PLaulI0GDfISlMI8n9f-dQWfu4ZIGDBZd1&index=24
 */ 

#define F_CPU 16000000

#include <avr/io.h>
#include <util/delay.h>
#include "gpio.h"


int main(void)
{
	//Configura o pino B5 como saída
    pinMode(&DDRB, DDB5, OUTPUT);
	
    while (1) 
    {

		digitalWrite(&PORTB, PB5, HIGH); //Coloca o pino B5 em HIGH
		_delay_ms(50);
		digitalWrite(&PORTB, PB5, LOW); //Coloca o pino B5 em LOW
		_delay_ms(50);		

		/*
		SET_BIT(PORTB, PB5);
		_delay_ms(500);
		CLEAR_BIT(PORTB, PB5);
		_delay_ms(500);		
		*/
    }
}



