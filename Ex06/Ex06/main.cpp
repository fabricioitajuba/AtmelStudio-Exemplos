/*
 * Ex06.cpp
 *
 * Created: 21/09/2022 09:09:16
 * Author : Desenvolvimento
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

#define SetBit(RES, BIT)(RES |= (1 << BIT))   // Por BIT em n�vel alto
#define ClrBit(RES, BIT)(RES &= ~ (1 << BIT)) // Por BIT em n�vel baixo
#define TstBit(RES, BIT)(RES &  (1 << BIT)) // testar BIT, retorna 0 ou 1
#define CplBit(RES, BIT)(RES ^= (1 << BIT)) // Inverter estado do BIT

int main(void){
	
	SetBit(DDRB, PB5);  //Pino 13 como sa�da.
	while( true ){
		ClrBit(PORTB, PB5); // bit PB5 LOM
		_delay_ms(100);
		SetBit(PORTB, PB5); // bit PB5 HIGH
		_delay_ms(100);
	}
}