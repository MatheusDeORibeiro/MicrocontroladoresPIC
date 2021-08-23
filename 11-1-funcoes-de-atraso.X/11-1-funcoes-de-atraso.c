/*
 * File:   11-1-funcoes-de-atraso.c
 * Author: Matheus
 *
 * Created on 22 de Junho de 2021, 13:03
 * 
 * Ao pressionar RB0: todo o PORTD deve piscar no tempo de 1s; para gerar um 
 *atraso de 1 segundo s�o necess�rios 5.000.000 de ciclos.
 */


//Inserindo bibliotecas
#include <xc.h>
#include "configuracao_pic18f4550.h"

//Inserindo defini��es
#define _XTAL_FREQ 20000000 //Com uma Fosc de 20MHz temos um Tciclo de 0,2us
#define RB0 PORTBbits.RB0

void main(void) {
    
    //Configurando os perif�ricos do dispositivo
    TRISA = 0x00;
    TRISB = 0b00000001;
    TRISC = 0x00;
    TRISD = 0x00;
    TRISE = 0x00;
    
    while(1){
        if(RB0 == 1){
            PORTD = 0xff;
            _delay(5000000); //5.000.000 de ciclos gera um atraso de 1 segundo
            PORTD = 0x00;
            _delay(5000000); //5.000.000 de ciclos gera um atraso de 1 segundo
        }else{
            PORTD = 0x00;
        }
    }
    
    return;
}
