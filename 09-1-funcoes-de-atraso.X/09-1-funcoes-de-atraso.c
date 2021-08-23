/*
 * File:   09-1-funcoes-de-atraso.c
 * Author: Matheus
 *
 * Created on 12 de Junho de 2021, 16:15
 * 
 * Desenvolver uma programa��o que fa�a o Led RD0 piscar. Deseja-se um atraso 
 * de 100ms e s�o necess�rios 500.000 ciclos de instru��o, pode-se utilizar:
 * _delay(500000)
 */


//Inserindo bibliotecas
#include <xc.h>
#include "configuracao_pic18f4550.h" //Inserindo a configura��o do dispositivo

//Inserindo defini��es
#define RD0 PORTDbits.RD0
#define _XTAL_FREQ 20000000 //com uma Fosc de 20MHz temos um Tciclo de O,2us

void main(void) {
    
    //Configura��o dos perif�ricos do dispositivo
    TRISA = 0x00;
    TRISB = 0x00;
    TRISC = 0x00;
    TRISD = 0x00;
    TRISE = 0x00;
        
    while(1){
        RD0 = 0;
        _delay(500000); //para gerar um atraso de 100ms s�o necess�rios 500.000 ciclos
        RD0 = 1;
        _delay(500000); //para gerar um atraso de 100ms s�o necess�rios 500.000 ciclos
    }
    
    return;
}
