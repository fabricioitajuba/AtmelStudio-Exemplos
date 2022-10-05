/*
 * gpio_config.cpp
 *
 * Created: 05/10/2022 17:13:00
 *  Author: Desenvolvimento
 */ 

#include <stdint.h>
#include "gpio.h"

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