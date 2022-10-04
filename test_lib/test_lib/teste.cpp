/*
 * teste.cpp
 *
 * Created: 04/10/2022 15:11:33
 *  Author: Desenvolvimento
 */ 

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#define __DELAY_BACKWARD_COMPATIBLE__

#include "teste.h"
#include <avr/io.h>
#include <util/delay.h>

teste::teste()
{
	DDRB |= (1 << DDB5);
}

void teste::pisca(int ms)
{
	PORTB |= (1 << PB5);     // set pin 5 of Port B high
	_delay_ms(ms);
	PORTB &= ~(1 << PB5);    // set pin 5 of Port B low
	_delay_ms(ms);
}