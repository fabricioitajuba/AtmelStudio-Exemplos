/*
 * gpio_config.h
 *
 * Created: 05/10/2022 17:11:31
 *  Author: Desenvolvimento
 */ 

#ifndef GPIO_H_
#define GPIO_H_


#define SET_BIT(byte, bit) (byte |= (1 << bit))
#define CLEAR_BIT(byte, bit) (byte &= ~(1 << bit))
#define IS_SET(byte, bit) ((byte) & (1<<bit))

#define OUTPUT 1
#define INPUT 0

#define HIGH 1
#define LOW 0

void pinMode(uint8_t volatile *pin_data_direction_register, uint8_t pin, bool Mode);
void digitalWrite(uint8_t volatile *port_data_pin_register, uint8_t pin, bool state);
uint8_t digitalRead(uint8_t volatile *port_input_pin_register, uint8_t pin);

#endif /* GPIO-CONFIG_H_ */