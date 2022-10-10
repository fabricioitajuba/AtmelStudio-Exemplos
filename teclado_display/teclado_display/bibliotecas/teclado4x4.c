/*
 * teclado4x4.c
 *
 * Created: 10/10/2022 14:04:23
 *  Author: Fabrício Ribeiro
 */ 

#define  F_CPU 16000000UL

#include <util/delay.h>

#include "teclado4x4.h"

teclado4x4_ini(int _X0, int _X1, int _X2, int _X3, int _Y0, int _Y1, int _Y2, int _Y3){

	X0 = _X0;
	X1 = _X1;
	X2 = _X2;
	X3 = _X3;
	
	Y0 = _Y0;
	Y1 = _Y1;
	Y2 = _Y2;
	Y3 = _Y3;

	pinMode(X0, INPUT);
	pinMode(X1, INPUT);
	pinMode(X2, INPUT);
	pinMode(X3, INPUT);

	pinMode(Y0, OUTPUT);
	pinMode(Y1, OUTPUT);
	pinMode(Y2, OUTPUT);
	pinMode(Y3, OUTPUT);
	
	digitalWrite(Y0, HIGH);	
	digitalWrite(Y1, HIGH);	
	digitalWrite(Y2, HIGH);	
	digitalWrite(Y3, HIGH);	
}

char le_teclado(int loop){
	
	char tecla;
	int bounce_ms;
	
	bounce_ms = 300;
	
	_delay_ms(bounce_ms);
	
	if(loop)
		tecla='t';
	else
		tecla = 'f';
		
	do{
		//Leitura da coluna YO
		digitalWrite(Y0, LOW);
		if(digitalRead(X0) == 0){
			tecla = 1;
		}
		else if(digitalRead(X1) == 0){
			tecla = 4;
		}
		else if(digitalRead(X2) == 0){
			tecla = 7;
		}
		else if(digitalRead(X3) == 0){
			tecla = '*';//*
		}
		digitalWrite(Y0, HIGH);
		
		//Leitura da coluna Y1
		digitalWrite(Y1, LOW);
		if(digitalRead(X0) == 0){
			tecla = 2;
		}
		else if(digitalRead(X1) == 0){
			tecla = 5;
		}
		else if(digitalRead(X2) == 0){
			tecla = 8;
		}
		else if(digitalRead(X3) == 0){
			tecla = 0;
		}
		digitalWrite(Y1, HIGH);

		//Leitura da coluna Y2
		digitalWrite(Y2, LOW);
		if(digitalRead(X0) == 0){
			tecla = 3;
		}
		else if(digitalRead(X1) == 0){
			tecla = 6;
		}
		else if(digitalRead(X2) == 0){
			tecla = 9;
		}
		else if(digitalRead(X3) == 0){
			tecla = '#';//#
		}
		digitalWrite(Y2, HIGH);
		
		//Leitura da coluna Y3
		digitalWrite(Y3, LOW);
		if(digitalRead(X0) == 0){
			tecla = 'A';
		}
		else if(digitalRead(X1) == 0){
			tecla = 'B';
		}
		else if(digitalRead(X2) == 0){
			tecla = 'C';
		}
		else if(digitalRead(X3) == 0){
			tecla = 'D';
		}
		digitalWrite(Y3, HIGH);

	}while(tecla == 't');
	
	return tecla;	
}
