/*
 * test_lib1.cpp
 *
 * Created: 04/10/2022 16:31:02
 * Author : Desenvolvimento
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

#include "bits.h"

bits bit;

int main(void)
{
    /* Replace with your application code */
    while (1) 
    {
		bit.set();
		_delay_ms(1000);
		bit.clear();
		_delay_ms(1000);
    }
}

