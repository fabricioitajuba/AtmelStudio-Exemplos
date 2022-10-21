/*
 * Ex08-EEPROM.c
 *
 * Created: 21/10/2022 08:39:22
 * Author : Fabrício Ribeiro
 */

 #define  F_CPU 8000000UL
 
 #include <avr/io.h>
 #include <stdio.h>
 #include <util/delay.h>
 #include <avr/eeprom.h>
 #include "bibliotecas/lcd.h"
 #include "bibliotecas/gpio.h"
 #include "bibliotecas/teclado4x3.h"

 int   outlcd(char c, FILE *stream);
 FILE mystdout = FDEV_SETUP_STREAM(outlcd, NULL, _FDEV_SETUP_WRITE);

 int outlcd(char c, FILE *stream){
 lcd_putc(c);
 return 0;
 }

 int main(void)
 {

 	uint8_t offset,end, dado;
	char tecla, aux, n_digito;

	lcd_init(LCD_DISP_ON);
	stdout = &mystdout;
	teclado4x3_ini(_PC0, _PC1, _PC2, _PC3, _PC4, _PC5, _PB0);

    printf("End:Dado");
	
	offset=0;
	dado = eeprom_read_byte(end+offset);
	printf("\n%02Xh=%02Xh", end+offset, dado);
	
    while (1)
    {
	    tecla = le_teclado(LOOP);
	    
	    if(tecla == 1){		
			offset++;
			dado = eeprom_read_byte(end+offset);
			lcd_gotoxy(0, 1);
			printf("%02Xh=%02Xh", end+offset, dado);
			lcd_gotoxy(4, 1);
	    }
	    else if(tecla == 4){
			offset--;
			dado = eeprom_read_byte(end+offset);
			lcd_gotoxy(0, 1);
			printf("%02Xh=%02Xh", end+offset, dado);
			lcd_gotoxy(4, 1);
	    }
	    else if(tecla == '*'){
			lcd_gotoxy(4, 1);
			lcd_command(LCD_DISP_ON_CURSOR_BLINK);
			
			aux = 0;
			n_digito = 0;
			
			do{
				tecla = le_teclado(LOOP);
				
				if(tecla < 10){
					printf("%d", tecla);
					aux = aux * 16;
					aux = aux + tecla;					
					n_digito++;
				}
				
			}while(n_digito != 2);
			eeprom_write_byte (end+offset, aux);
			lcd_command(LCD_DISP_ON);
	    }		
    }
 }



