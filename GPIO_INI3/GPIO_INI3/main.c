/*
 * GPIO_INI3.c
 *
 * Created: 10/10/2022 11:21:55
 * Author : Fabrício Ribeiro
 */ 

#include <avr/io.h>
#include "gpio.h"

int main(void)
{
    pinMode(_PC6, INPUT);
    pinMode(_PB5, OUTPUT);
    
	while (1) 
    {
		if(digitalRead(_PC6))
			digitalWrite(_PB5, HIGH);
		else
			digitalWrite(_PB5, LOW);		
    }
}

