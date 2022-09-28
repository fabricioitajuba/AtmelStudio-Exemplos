//Biblioteca para acionar display 16x2 através de 4bits
//Atmega328P
//Autor: Fabrício de Lima Ribeiro
//Data: 26/09/2022

#ifndef LCD16X2_4B_H_
#define LCD16X2_4B_H_

#define F_CPU 16000000UL // 16 MHz clock speed
#include <avr/io.h>
#include <util/delay.h>

//Definição dos pinos do LCD
#define D4 eS_PORTD5				//D4 do display no D5 do microcontrolador
#define set_D4 DDRD |= (1 << DDD5);	//D5 como saída

#define D5 eS_PORTD4				//D5 do display no D4 do microcontrolador
#define set_D5 DDRD |= (1 << DDD4);	//D4 como saída

#define D6 eS_PORTD3				//D6 do display no D3 do microcontrolador
#define set_D6 DDRD |= (1 << DDD3);	//D3 como saída

#define D7 eS_PORTD2				//D7 do display no D2 do microcontrolador
#define set_D7 DDRD |= (1 << DDD2);	//D2 como saída

#define RS eS_PORTD7				//RS do display no D7 do microcontrolador
#define set_RS DDRD |= (1 << DDD7);	//D7 como saída

#define EN eS_PORTD6				//EN do display no D6 do microcontrolador
#define set_EN DDRD |= (1 << DDD6);	//D6 como saída

//Definição dos pinos do atmega328p
#define eS_PORTB0 10
#define eS_PORTB1 11
#define eS_PORTB2 12
#define eS_PORTB3 13
#define eS_PORTB4 14
#define eS_PORTB5 15
#define eS_PORTB6 16
#define eS_PORTB7 17

#define eS_PORTC0 20
#define eS_PORTC1 21
#define eS_PORTC2 22
#define eS_PORTC3 23
#define eS_PORTC4 24
#define eS_PORTC5 25
#define eS_PORTC6 26

#define eS_PORTD0 30
#define eS_PORTD1 31
#define eS_PORTD2 32
#define eS_PORTD3 33
#define eS_PORTD4 34
#define eS_PORTD5 35
#define eS_PORTD6 36
#define eS_PORTD7 37

void pinChange(int a, int b);
void Lcd4_Port(char a);
void Lcd4_Cmd(char a);
void Lcd4_Clear();
void Lcd4_Set_Cursor(char a, char b);
void Lcd4_Init();
void Lcd4_Write_Char(char a);
void Lcd4_Write_String(char *a);
void Lcd4_Shift_Right();
void Lcd4_Shift_Left();

#endif /* LCD16X2_4B_H_ */
