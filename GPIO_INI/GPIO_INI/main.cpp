/*
 * GPIO_INI.cpp
 * Configuração simples dos GPIO'S
 * Created: 05/10/2022 09:37:56
 * Author : Fabrício Ribeiro
 * fonte: https://www.youtube.com/watch?v=FgVLt6sXmxI
 *        https://www.youtube.com/watch?v=A-ETcQ_rejU&list=PLaulI0GDfISlMI8n9f-dQWfu4ZIGDBZd1&index=24
 */ 

#define F_CPU 16000000

#include <avr/io.h>
#include <util/delay.h>

#define SET_BIT(byte, bit) (byte |= (1 << bit))
#define CLEAR_BIT(byte, bit) (byte &= ~(1 << bit))
#define IS_SET(byte, bit) ((byte) & (1<<bit))

#define OUTPUT 1
#define INPUT 0

#define HIGH 1
#define LOW 0


//Configura o pino como entrada ou saída
void pinMode(uint8_t volatile *pin_data_direction_register, uint8_t pin, bool Mode){
	
	if(Mode == OUTPUT)
		*pin_data_direction_register |= (1 << pin);
	else if(Mode == INPUT)
		*pin_data_direction_register &= ~(1 << pin);
}

//Escreve no pino
void digitalWrite(uint8_t volatile *port_data_pin_register, uint8_t pin, bool state){
	
	if(state == HIGH)
		*port_data_pin_register |= (1 << pin);
	else if(state == LOW)
		*port_data_pin_register &= ~(1 << pin);

}

//Lê o pino
uint8_t digitalRead(uint8_t volatile *port_input_pin_register, uint8_t pin){
	
	return ((*port_input_pin_register) & (1 << pin));
}

int main(void)
{
	//Configura o pino B5 como saída
    pinMode(&DDRB, DDB5, OUTPUT);
	
    while (1) 
    {

		digitalWrite(&PORTB, PB5, HIGH); //Coloca o pino B5 em HIGH
		_delay_ms(50);
		digitalWrite(&PORTB, PB5, LOW); //Coloca o pino B5 em LOW
		_delay_ms(50);		

		/*
		SET_BIT(PORTB, PB5);
		_delay_ms(500);
		CLEAR_BIT(PORTB, PB5);
		_delay_ms(500);		
		*/
    }
}

