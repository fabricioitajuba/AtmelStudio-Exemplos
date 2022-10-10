//Biblioteca para acionar display 16x2 através de 4bits
//Atmega328P
//Autor: Fabrício de Lima Ribeiro
//Data: 26/09/2022

#ifndef LCD16X2_4B_H_
#define LCD16X2_4B_H_

#define F_CPU 16000000UL // 16 MHz clock speed
#include <avr/io.h>
#include <util/delay.h>

#define OUTPUT 1
#define INPUT 0

#define HIGH 1
#define LOW 0

int E, RS, D4, D5, D6, D7;

void Lcd4_Init(int _E, int _RS, int _D4, int _D5, int _D6, int _D7);

void pinChange(int a, int b);
void Lcd4_Port(char a);
void Lcd4_Cmd(char a);
void Lcd4_Clear();
void Lcd4_Set_Cursor(char a, char b);

void Lcd4_Write_Char(char a);
void Lcd4_Write_String(char *a);
void Lcd4_Shift_Right();
void Lcd4_Shift_Left();

#endif /* LCD16X2_4B_H_ */
