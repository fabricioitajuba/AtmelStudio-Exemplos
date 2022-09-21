/*
 * Ex05.cpp
 *
 * Created: 21/09/2022 07:55:38
 * Author : Desenvolvimento
 */ 

#define F_CPU 16000000UL // 16 MHz clock speed

#include <avr/io.h>
#include <util/delay.h>

//PB5 arduino LED

int main(void)
{
	/* Replace with your application code */
	DDRB |= (1 << DDB5);     // set pin 5 of Port B as output
	
	while (1)
	{
		PORTB |= (1 << PB5);     // set pin 5 of Port B high
		_delay_ms(500);
		PORTB &= ~(1 << PB5);    // set pin 5 of Port B low
		_delay_ms(500);
		
		//PORTB |= (1 << PORTB5);  // set pin 5 high again
		//PORTB ^= (1 << PB5);   // toggles the state of the bit
	}
}

