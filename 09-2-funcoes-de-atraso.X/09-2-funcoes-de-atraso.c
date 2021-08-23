/*
 * File:   09-2-funcoes-de-atraso.c
 * Author: Matheus
 *
 * Created on 14 de Junho de 2021, 15:37
 * 
 *  
 * Desenvolver uma programa��o que fa�a todo o PORTD piscar. Deseja-se um atraso 
 * de 100ms e s�o necess�rios 500.000 ciclos de instru��o, pode-se utilizar:
 * _delay(500000)
 */


//Inserindo bibliotecas
#include <xc.h>
#include "configuracao_pic18f4550.h" //Inserindo a configura��o do dispositivo

//Inserindo defini��es
#define _XTAL_FREQ_ 20000000 //com uma Fosc de 20MHz temos um Tciclo O,2us

void main(void) {
    
    //Configura��o dos perif�ricos do dispositivo
    TRISA = 0x00;
    TRISB = 0x00;
    TRISC = 0x00;
    TRISD = 0x00;
    TRISE = 0x00;

    while(1){
    
        PORTD = 0x00;
        _delay(500000); //para gerar um atraso de 100ms s�o necess�rios 500.000 cilcos
        PORTD = 0xff;
        _delay(500000); //para gerar um atraso de 100ms s�o necess�rios 500.000 cilcos
    }
  
    return;
}
