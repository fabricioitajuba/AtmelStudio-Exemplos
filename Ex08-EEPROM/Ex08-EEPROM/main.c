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

 /*
 Inicialização da EEPROM
 O Atmel studio gera 3 arquivos após a compilação: .hex, .elf, .eep
 
 .hex -> programa compilado
 .epp -> eeprom
 .elf = .hex + .epp + fuses
 
 No minipro, carrega-se o .hex em "Code Memo" e o .epp em "Data Memo". Ambos no formato: "INTEL HEX"
 No proteus, pode-se carregar o .hex ou o .elf, o .elf irá inicializar a eeprom com os valores inicializados.
 */
 
 //Formas de inicializar a eeprom
 __attribute__((section(".eeprom"))) uint8_t eepContent[8] = {0x46, 0x41, 0x42, 0x52, 0x49, 0x43, 0x49, 0x4F}; //Inicializa as 8 primeiras posições
 uint8_t EEMEM Var1 = 7;	//Inicializa a próxima localização 8bits
 uint8_t EEMEM Var2 = 3;	//Inicializa a próxima localização 8bits
 uint8_t EEMEM Var3 = 76;	//Inicializa a próxima localização 8bits
 int eevar EEMEM = 1976;	//Inicializa a próxima localização 16bits

 int outlcd(char c, FILE *stream);
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
	dado = eeprom_read_byte((uint8_t*)(end+offset));
	printf("\n%02Xh=%02Xh", end+offset, dado);
	
    while (1)
    {
	    tecla = le_teclado(LOOP);
	    
	    if(tecla == 1){		
			offset++;
			dado = eeprom_read_byte((uint8_t*)(end+offset));
			lcd_gotoxy(0, 1);
			printf("%02Xh=%02Xh", end+offset, dado);
			lcd_gotoxy(4, 1);
	    }
	    else if(tecla == 4){
			offset--;
			dado = eeprom_read_byte((uint8_t*)(end+offset));
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
			eeprom_write_byte ((end+offset), aux);
			lcd_command(LCD_DISP_ON);
	    }		
    }
 }



