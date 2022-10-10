/*
 * gpio.c
 *
 * Created: 10/10/2022 11:23:40
 *  Author: Fabrício Ribeiro
 */ 

#include "gpio.h"
#include <avr/io.h>

void pinMode(int pino, int Mode){

	if(Mode == INPUT){
		if(pino == 0)
			DDRB &= ~(1 << PINB0);
		else if(pino == 1)
			DDRB &= ~(1 << PINB1);
		else if(pino == 2)
			DDRB &= ~(1 << PINB2);
		else if(pino == 3)
			DDRB &= ~(1 << PINB3);
		else if(pino == 4)
			DDRB &= ~(1 << PINB4);
		else if(pino == 5)
			DDRB &= ~(1 << PINB5);
		else if(pino == 6)
			DDRB &= ~(1 << PINB6);
		else if(pino == 7)
			DDRB &= ~(1 << PINB7);
		else if(pino == 8)
			DDRC &= ~(1 << PINC0);
		else if(pino == 9)
			DDRC &= ~(1 << PINC1);
		else if(pino == 10)
			DDRC &= ~(1 << PINC2);
		else if(pino == 11)
			DDRC &= ~(1 << PINC3);
		else if(pino == 12)
			DDRC &= ~(1 << PINC4);
		else if(pino == 13)
			DDRC &= ~(1 << PINC5);
		else if(pino == 14)
			DDRC &= ~(1 << PINC6);
		else if(pino == 15)
			DDRD &= ~(1 << PIND0);
		else if(pino == 16)
			DDRD &= ~(1 << PIND1);
		else if(pino == 17)
			DDRD &= ~(1 << PIND2);
		else if(pino == 18)
			DDRD &= ~(1 << PIND3);
		else if(pino == 19)
			DDRD &= ~(1 << PIND4);
		else if(pino == 20)
			DDRD &= ~(1 << PIND5);
		else if(pino == 21)
			DDRD &= ~(1 << PIND6);
		else if(pino == 22)
			DDRD &= ~(1 << PIND7);
	}
	else if(Mode == OUTPUT){
		if(pino == 0)
			DDRB |= (1 << PINB0);
		else if(pino == 1)
			DDRB |= (1 << PINB1);
		else if(pino == 2)
			DDRB |= (1 << PINB2);
		else if(pino == 3)
			DDRB |= (1 << PINB3);
		else if(pino == 4)
			DDRB |= (1 << PINB4);
		else if(pino == 5)
			DDRB |= (1 << PINB5);
		else if(pino == 6)
			DDRB |= (1 << PINB6);
		else if(pino == 7)
			DDRB |= (1 << PINB7);
		else if(pino == 8)
			DDRC |= (1 << PINC0);
		else if(pino == 9)
			DDRC |= (1 << PINC1);
		else if(pino == 10)
			DDRC |= (1 << PINC2);
		else if(pino == 11)
			DDRC |= (1 << PINC3);
		else if(pino == 12)
			DDRC |= (1 << PINC4);
		else if(pino == 13)
			DDRC |= (1 << PINC5);
		else if(pino == 14)
			DDRC |= (1 << PINC6);
		else if(pino == 15)
			DDRD |= (1 << PIND0);
		else if(pino == 16)
			DDRD |= (1 << PIND1);
		else if(pino == 17)
			DDRD |= (1 << PIND2);
		else if(pino == 18)
			DDRD |= (1 << PIND3);
		else if(pino == 19)
			DDRD |= (1 << PIND4);
		else if(pino == 20)
			DDRD |= (1 << PIND5);
		else if(pino == 21)
			DDRD |= (1 << PIND6);
		else if(pino == 22)
			DDRD |= (1 << PIND7);
	}
}

void digitalWrite(int pino, int state){

	if(state == LOW){
		if(pino == 0)
			PORTB &= ~(1 << PB0);
		else if(pino == 1)
			PORTB &= ~(1 << PB1);
		else if(pino == 2)
			PORTB &= ~(1 << PB2);
		else if(pino == 3)
			PORTB &= ~(1 << PB3);
		else if(pino == 4)
			PORTB &= ~(1 << PB4);
		else if(pino == 5)
			PORTB &= ~(1 << PB5);
		else if(pino == 6)
			PORTB &= ~(1 << PB6);
		else if(pino == 7)
			PORTB &= ~(1 << PB7);
		else if(pino == 8)
			PORTC &= ~(1 << PC0);
		else if(pino == 9)
			PORTC &= ~(1 << PC1);
		else if(pino == 10)
			PORTC &= ~(1 << PC2);
		else if(pino == 11)
			PORTC &= ~(1 << PC3);
		else if(pino == 12)
			PORTC &= ~(1 << PC4);
		else if(pino == 13)
			PORTC &= ~(1 << PC5);
		else if(pino == 14)
			PORTC &= ~(1 << PC6);
		else if(pino == 15)
			PORTD &= ~(1 << PD0);
		else if(pino == 16)
			PORTD &= ~(1 << PD1);
		else if(pino == 17)
			PORTD &= ~(1 << PD2);
		else if(pino == 18)
			PORTD &= ~(1 << PD3);
		else if(pino == 19)
			PORTD &= ~(1 << PD4);
		else if(pino == 20)
			PORTD &= ~(1 << PD5);
		else if(pino == 21)
			PORTD &= ~(1 << PD6);
		else if(pino == 22)
			PORTD &= ~(1 << PD7);
	}
	else if(state == HIGH){
		if(pino == 0)
			PORTB |= (1 << PB0);
		else if(pino == 1)
			PORTB |= (1 << PB1);
		else if(pino == 2)
			PORTB |= (1 << PB2);
		else if(pino == 3)
			PORTB |= (1 << PB3);
		else if(pino == 4)
			PORTB |= (1 << PB4);
		else if(pino == 5)
			PORTB |= (1 << PB5);
		else if(pino == 6)
			PORTB |= (1 << PB6);
		else if(pino == 7)
			PORTB |= (1 << PB7);
		else if(pino == 8)
			PORTC |= (1 << PC0);
		else if(pino == 9)
			PORTC |= (1 << PC1);
		else if(pino == 10)
			PORTC |= (1 << PC2);
		else if(pino == 11)
			PORTC |= (1 << PC3);
		else if(pino == 12)
			PORTC |= (1 << PC4);
		else if(pino == 13)
			PORTC |= (1 << PC5);
		else if(pino == 14)
			PORTC |= (1 << PC6);
		else if(pino == 15)
			PORTD |= (1 << PD0);
		else if(pino == 16)
			PORTD |= (1 << PD1);
		else if(pino == 17)
			PORTD |= (1 << PD2);
		else if(pino == 18)
			PORTD |= (1 << PD3);
		else if(pino == 19)
			PORTD |= (1 << PD4);
		else if(pino == 20)
			PORTD |= (1 << PD5);
		else if(pino == 21)
			PORTD |= (1 << PD6);
		else if(pino == 22)
			PORTD |= (1 << PD7);
	}

}

int digitalRead(int pino){

	if(pino == 0)
		return (PINB & (1 << PINB0));
	else if(pino == 1)
		return (PINB & (1 << PINB1));
	else if(pino == 2)
		return (PINB & (1 << PINB2));
	else if(pino == 3)
		return (PINB & (1 << PINB3));
	else if(pino == 4)
		return (PINB & (1 << PINB4));
	else if(pino == 5)
		return (PINB & (1 << PINB5));
	else if(pino == 6)
		return (PINB & (1 << PINB6));
	else if(pino == 7)
		return (PINB & (1 << PINB7));
	else if(pino == 8)
		return (PINC & (1 << PINC0));
	else if(pino == 9)
		return (PINC & (1 << PINC1));
	else if(pino == 10)
		return (PINC & (1 << PINC2));
	else if(pino == 11)
		return (PINC & (1 << PINC3));
	else if(pino == 12)
		return (PINC & (1 << PINC4));
	else if(pino == 13)
		return (PINC & (1 << PINC5));
	else if(pino == 14)
		return (PINC & (1 << PINC6));
	else if(pino == 15)
		return (PIND & (1 << PIND0));
	else if(pino == 16)
		return (PIND & (1 << PIND1));
	else if(pino == 17)
		return (PIND & (1 << PIND2));
	else if(pino == 18)
		return (PIND & (1 << PIND3));
	else if(pino == 19)
		return (PIND & (1 << PIND4));
	else if(pino == 20)
		return (PIND & (1 << PIND5));
	else if(pino == 21)
		return (PIND & (1 << PIND6));
	else if(pino == 22)
		return (PIND & (1 << PIND7));
}