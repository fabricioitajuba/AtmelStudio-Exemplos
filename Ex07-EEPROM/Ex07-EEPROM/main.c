/*
 * Ex07-EEPROM.c
 *
 * Created: 20/10/2022 13:55:49
 * Author : Fabrício Ribeiro
 */

#define  F_CPU 8000000UL
 
#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#include <avr/eeprom.h>
#include "bibliotecas/lcd.h"
#include "bibliotecas/gpio.h"

int   outlcd(char c, FILE *stream);
FILE mystdout = FDEV_SETUP_STREAM(outlcd, NULL, _FDEV_SETUP_WRITE);

int outlcd(char c, FILE *stream){
	lcd_putc(c);
	return 0;
}

int main(void)
{
	uint8_t offset,end, dado;

	eeprom_write_byte (0x00, 0x00);
	eeprom_write_byte (0x01, 0x01);
	eeprom_write_byte (0x02, 0x02);
	eeprom_write_byte (0x03, 0x03);
	eeprom_write_byte (0x07, 0xFA);
	eeprom_write_byte (0x0A, 0x03);
	eeprom_write_byte (0x0B, 0x07);
	eeprom_write_byte (0x0C, 0x76);

	pinMode(_PC0, INPUT);
	pinMode(_PB1, INPUT);

	lcd_init(LCD_DISP_ON);
	stdout = &mystdout;

	offset=0;
	dado = eeprom_read_byte(end+offset);
	printf("%02Xh=%02Xh", end+offset, dado);
	
	offset++;
	dado = eeprom_read_byte(end+offset);
	printf("\n%02Xh=%02Xh", end+offset, dado);
	
	while(1)
	{
		if(!digitalRead(_PC0)){

			_delay_ms(500);//Anti-bounce
			do{				
			}while(!digitalRead(_PC0));
			
			dado = eeprom_read_byte(end+offset);
			lcd_gotoxy(0, 0);
			printf("%02Xh=%02Xh", end+offset, dado);
	
			offset++;
			dado = eeprom_read_byte(end+offset);
			lcd_gotoxy(0, 1);
			printf("%02Xh=%02Xh", end+offset, dado);
		}
		else if(!digitalRead(_PC1)){

			_delay_ms(500);
			offset--;
			offset--;
			dado = eeprom_read_byte(end+offset);
			lcd_gotoxy(0, 0);
			printf("%02Xh=%02Xh", end+offset, dado);
			offset++;
			dado = eeprom_read_byte(end+offset);
			lcd_gotoxy(0, 1);
			printf("%02Xh=%02Xh", end+offset, dado);
		}		

	}
}

