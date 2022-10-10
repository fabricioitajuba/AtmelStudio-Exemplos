/*
 * teclado4x4.h
 *
 * Created: 10/10/2022 14:04:09
 *  Author: Fabrício Ribeiro
 */ 


#ifndef TECLADO4X4_H_
#define TECLADO4X4_H_

#define OUTPUT 1
#define INPUT 0

#define HIGH 1
#define LOW 0

#define LOOP 1
#define NO_LOOP 0

int X0, X1, X2, X3, Y0, Y1, Y2, Y3;

//C0, C1, C2, C3, L0, L1, L2, L3
teclado4x4_ini(int _X0, int _X1, int _X2, int _X3, int _Y0, int _Y1, int _Y2, int _Y3);
char le_teclado(int loop);
		
#endif /* TECLADO4X4_H_ */