//Biblioteca para acionar display 16x2 através de 4bits
//Atmega328P
//Autor: Fabrício de Lima Ribeiro
//Data: 26/09/2022

#include "lcd16x2_4b.h"

void Lcd4_Port(char a){
	
	if(a & 1)
		digitalWrite(D4, HIGH);
	else
		digitalWrite(D4, LOW);
	
	if(a & 2)
		digitalWrite(D5, HIGH);
	else
		digitalWrite(D5, LOW);
	
	if(a & 4)
		digitalWrite(D6, HIGH);
	else
		digitalWrite(D6, LOW);
	
	if(a & 8)
		digitalWrite(D7, HIGH);
	else
		digitalWrite(D7, LOW);
}

void Lcd4_Cmd(char a){
	
	digitalWrite(RS, LOW);
	Lcd4_Port(a);
	digitalWrite(E, HIGH);
	_delay_ms(1);
	digitalWrite(E, LOW);
	_delay_ms(1);
}

void Lcd4_Clear(){
	
	Lcd4_Cmd(0);
	Lcd4_Cmd(1);
}

void Lcd4_Set_Cursor(char a, char b){
	
	char temp,z,y;
	
	if(a == 1){
		temp = 0x80 + b;
		z = temp>>4;
		y = (0x80+b) & 0x0F;
		Lcd4_Cmd(z);
		Lcd4_Cmd(y);
	}
	else if(a == 2){
		temp = 0xC0 + b;
		z = temp>>4;
		y = (0xC0+b) & 0x0F;
		Lcd4_Cmd(z);
		Lcd4_Cmd(y);
	}
}

void Lcd4_Init(int _E, int _RS, int _D4, int _D5, int _D6, int _D7){
	
	E = _E;
	RS = _RS;
	D4 = _D4;
	D5 = _D5;
	D6 = _D6;
	D7 = _D7;

	pinMode(E, OUTPUT);
	pinMode(RS, OUTPUT);
	pinMode(D4, OUTPUT);
	pinMode(D5, OUTPUT);
	pinMode(D6, OUTPUT);
	pinMode(D7, OUTPUT);

	digitalWrite(E, HIGH);
	digitalWrite(RS, HIGH);
	digitalWrite(D4, HIGH);
	digitalWrite(D5, HIGH);
	digitalWrite(D6, HIGH);
	digitalWrite(D7, HIGH);

	//Lcd4_Port(0x00);
	_delay_ms(20);
	Lcd4_Cmd(0x03);
	_delay_ms(5);
	Lcd4_Cmd(0x03);
	_delay_ms(11);
	Lcd4_Cmd(0x03);
	Lcd4_Cmd(0x02);
	Lcd4_Cmd(0x02);
	Lcd4_Cmd(0x08);
	Lcd4_Cmd(0x00);
	Lcd4_Cmd(0x0C);
	Lcd4_Cmd(0x00);
	Lcd4_Cmd(0x06);
}

void Lcd4_Write_Char(char a){
	
	char temp,y;
	
	temp = a&0x0F;
	y = a&0xF0;
	digitalWrite(RS, HIGH);
	Lcd4_Port(y>>4);             //Data transfer
	digitalWrite(E, HIGH);
	_delay_ms(1);
	digitalWrite(E, LOW);
	_delay_ms(1);
	Lcd4_Port(temp);
	digitalWrite(E, HIGH);
	_delay_ms(1);
	digitalWrite(E, LOW);
	_delay_ms(1);
}

void Lcd4_Write_String(char *a){
	
	int i;
	for(i=0;a[i]!='\0';i++)
	Lcd4_Write_Char(a[i]);
}

void Lcd4_Shift_Right(){
	
	Lcd4_Cmd(0x01);
	Lcd4_Cmd(0x0C);
}

void Lcd4_Shift_Left(){
	
	Lcd4_Cmd(0x01);
	Lcd4_Cmd(0x08);
}

