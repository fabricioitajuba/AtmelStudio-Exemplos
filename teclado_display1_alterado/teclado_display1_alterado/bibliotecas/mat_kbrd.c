#define F_CPU 8000000UL

#include "mat_kbrd.h"
#include <avr/io.h>
#include <util/delay.h>
//unsigned static char* kbrd_port;

//TODO: agregar la mascara para el otro pin si se esta utilizando un teclado 4x4
#define KBRD_ROW_MASK()  (KBRD_F0_PINPORT & (1<<KBRD_F0_PIN)) >> KBRD_F0_PIN | ((KBRD_F1_PINPORT & (1<<KBRD_F1_PIN)) >> KBRD_F1_PIN) << 1 | ((KBRD_F2_PINPORT & (1<<KBRD_F2_PIN)) >> KBRD_F2_PIN) << 2 | ((KBRD_F3_PINPORT & (1<<KBRD_F3_PIN)) >> KBRD_F3_PIN) << 3

#define KBRD_ROW_MASK_AL()  (~(KBRD_F0_PINPORT | ~(1<<KBRD_F0_PIN)) >> KBRD_F0_PIN) | (~(KBRD_F1_PINPORT | ~(1<<KBRD_F1_PIN)) >> KBRD_F1_PIN) << 1 | (~(KBRD_F2_PINPORT | ~(1<<KBRD_F2_PIN)) >> KBRD_F2_PIN) << 2 | (~(KBRD_F3_PINPORT | ~(1<<KBRD_F3_PIN)) >> KBRD_F3_PIN) << 3

//function prototypes
 void activate_column(unsigned char column);
 void reset_columns(void);

void kbrd_init()
{
	//Column pins are Outputs
	KBRD_C0_DDR |= (1<<KBRD_C0_PIN);
	KBRD_C1_DDR |= (1<<KBRD_C1_PIN);
	KBRD_C2_DDR |= (1<<KBRD_C2_PIN);
	KBRD_C3_DDR |= (1<<KBRD_C3_PIN);
	
	//Row pins are Inputs
	KBRD_F0_DDR &= ~(1<<KBRD_F0_PIN);
	KBRD_F1_DDR &= ~(1<<KBRD_F1_PIN);
	KBRD_F2_DDR &= ~(1<<KBRD_F2_PIN);
	KBRD_F3_DDR &= ~(1<<KBRD_F3_PIN);
	
	
	//enable pull ups on row pins
	KBRD_F0_PORT |= (1<<KBRD_F0_PIN);
	KBRD_F1_PORT |= (1<<KBRD_F1_PIN);
	KBRD_F2_PORT |= (1<<KBRD_F2_PIN);
	KBRD_F3_PORT |= (1<<KBRD_F3_PIN);
	// Put Ones in Columns
	KBRD_C0_PORT |= (1<<KBRD_C0_PIN);
	KBRD_C1_PORT |= (1<<KBRD_C1_PIN);
	KBRD_C2_PORT |= (1<<KBRD_C2_PIN);
	KBRD_C3_PORT |= (1<<KBRD_C3_PIN);
}

char kbrd_read(char loop)
{
	//reset_columns();
	char tecla;

	if(loop)
		tecla='t';
	else
		tecla = 'f';

	do{
		//verify first column
		KBRD_C0_PORT &= ~(1<< KBRD_C0_PIN);
		switch(KBRD_ROW_MASK_AL()){
			case 1:
				tecla='7';
				_delay_ms(KBRD_DELAY);
				break;
			case 2:
				tecla= '4';
				_delay_ms(KBRD_DELAY);
				break;
			case 4:
				tecla= '1';
				_delay_ms(KBRD_DELAY);
				break;
			case 8:
				tecla= '.';
				_delay_ms(KBRD_DELAY);
				break;
		}
		KBRD_C0_PORT |= (1<< KBRD_C0_PIN);

		//verify second column
		KBRD_C1_PORT &= ~(1<< KBRD_C1_PIN);
		switch(KBRD_ROW_MASK_AL()){
			case 1:
				tecla= '8';
				_delay_ms(KBRD_DELAY);
				break;
			case 2:
				tecla= '5';
				_delay_ms(KBRD_DELAY);
				break;
			case 4:
				tecla= '2';
				_delay_ms(KBRD_DELAY);
				break;
			case 8:
				tecla= '0';// +
				_delay_ms(KBRD_DELAY);
				break;
		}
		KBRD_C1_PORT |= (1<< KBRD_C1_PIN);
	
		//verify thirth column
		KBRD_C2_PORT &= ~(1<< KBRD_C2_PIN);
		switch(KBRD_ROW_MASK_AL()){
			case 1:
				tecla= '9';// /
				_delay_ms(KBRD_DELAY);
				break;
			case 2:
				tecla= '6';// X
				_delay_ms(KBRD_DELAY);
				break;
			case 4:
				tecla= '3';// -
				_delay_ms(KBRD_DELAY);
				break;
			case 8:
				tecla= '=';
				_delay_ms(KBRD_DELAY);
				break;
		}
		KBRD_C2_PORT |= (1<< KBRD_C2_PIN);
	
		//verify four column
		KBRD_C3_PORT &= ~(1<< KBRD_C3_PIN);
		switch(KBRD_ROW_MASK_AL()){
			case 1:
				tecla= '/';
				_delay_ms(KBRD_DELAY);
				break;
			case 2:
				tecla= 'X';
				_delay_ms(KBRD_DELAY);
				break;
			case 4:
				tecla= '-';
				_delay_ms(KBRD_DELAY);
				break;
			case 8:
				tecla= '+';
				_delay_ms(KBRD_DELAY);
				break;
		}
		KBRD_C3_PORT |= (1<< KBRD_C3_PIN);

	}while(tecla == 't');
	
	return tecla;	
}
