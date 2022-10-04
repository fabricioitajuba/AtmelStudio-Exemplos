/*
 * bits.cpp
 *
 * Created: 04/10/2022 16:33:09
 *  Author: Desenvolvimento
 */ 

#include "bits.h"
#include <avr/io.h>

bits::bits()
{
	DDRB |= (1 << DDB5);
}

void bits::clear(void)
{
	PORTB &= ~(1 << PB5);
}

void bits::set(void)
{
	PORTB |= (1 << PB5);
}