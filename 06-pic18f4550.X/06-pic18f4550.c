/*
 * File:   06-pic18f4550.c
 * Author: Matheus
 *
 * Created on 4 de Junho de 2021, 17:52
 * 
 * Ao acionar o pino RB0 atrav�s de um bot�o, o led do pino RD0 � acionado, 
 * ao acionar o pino RB1 atrav�s de um bot�o, o led do pino RD1 � acionado, 
 * e assim por diante para todo o PORTB e PORTD.
 */


//Inserindo bibliotecas
#include <xc.h>
#include "configuracao_pic18f4550.h" //Inserindo a configura��o do dispositivo 

void main(void) {  
    
    //Configura��o dos perif�ricos do dispositivo
    //ADCON1 = 0b00001111; //Configurando os canais anal�gicos como I/Os; j� configurado pela lista de configura��o PBADEN = OFF
    TRISA = 0x00;
    TRISB = 0xff;
    TRISC = 0x00;
    TRISD = 0x00;
    TRISE = 0x00;

    if(PORTBbits.RB0 == 1){
        PORTDbits.RD0 = 1;  
    }else{
	    PORTDbits.RD0 = 0;
    }    
    if(PORTBbits.RB1 == 1){
        PORTDbits.RD1 = 1;
    }else{
        PORTDbits.RD1 = 0;
    }    
    if(PORTBbits.RB2 == 1){
        PORTDbits.RD2 = 1;
    }else{
	    PORTDbits.RD2 = 0;
    }    
    if(PORTBbits.RB3 == 1){
	    PORTDbits.RD3 = 1;
    }else{
	    PORTDbits.RD3 = 0;
    }
    if(PORTBbits.RB4 == 1){
	    PORTDbits.RD4 = 1;
    }else{
	    PORTDbits.RD4 = 0;
    }
    if(PORTBbits.RB5 == 1){
	    PORTDbits.RD5 = 1;
    }else{
	    PORTDbits.RD5 = 0;
    }
    if(PORTBbits.RB6 == 1){
        PORTDbits.RD6 = 1;
    }else{
        PORTDbits.RD6 = 0;
    }
    if(PORTBbits.RB7 == 1){
        PORTDbits.RD7 = 1;
    }else{
        PORTDbits.RD7 = 0;
    }
    
    return;
}
