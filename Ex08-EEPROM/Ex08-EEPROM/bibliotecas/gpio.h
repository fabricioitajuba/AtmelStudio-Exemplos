/*
 * gpio.h
 *
 * Created: 10/10/2022 11:23:20
 *  Author: Fabrício Ribeiro
 */ 


#ifndef GPIO_H_
#define GPIO_H_

//Definição dos pinos do atmega328p
#define _PB0 0
#define _PB1 1
#define _PB2 2
#define _PB3 3
#define _PB4 4
#define _PB5 5
#define _PB6 6
#define _PB7 7

#define _PC0 8
#define _PC1 9
#define _PC2 10
#define _PC3 11
#define _PC4 12
#define _PC5 13
#define _PC6 14

#define _PD0 15
#define _PD1 16
#define _PD2 17
#define _PD3 18
#define _PD4 19
#define _PD5 20
#define _PD6 21
#define _PD7 22

#define LOOP	1
#define NO_LOOP	0

#define OUTPUT 1
#define INPUT 0

#define HIGH 1
#define LOW 0

void pinMode(int pino, int Mode);
void digitalWrite(int pino, int state);
int digitalRead(int pino);

#endif /* GPIO_H_ */