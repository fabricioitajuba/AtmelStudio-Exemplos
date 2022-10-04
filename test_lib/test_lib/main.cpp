/*
 * test_lib.cpp
 *
 * Created: 04/10/2022 15:10:35
 * Author : Desenvolvimento
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include "teste.h"

teste teste1;

int main(void)
{
    /* Replace with your application code */
    while (1) 
    {
		teste1.pisca(50);
    }
}

