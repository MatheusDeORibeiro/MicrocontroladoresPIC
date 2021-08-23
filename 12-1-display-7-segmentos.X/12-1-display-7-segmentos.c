/*
 * File:   12-1-display-7-segmentos.c
 * Author: Matheus
 *
 * Created on 29 de Junho de 2021, 14:45
 * 
 * 2� tarefa do dia: visualizar o n�mero 3 no display.
 */


//Inserindo bibliotecas
#include <xc.h>
#include "configuracao_pic18f4550.h"

void main(void) {
    
    //Configurando os perif�ricos do dispositivo
    TRISA = 0x00;
    TRISB = 0x00;
    TRISC = 0x00;
    TRISD = 0x00;
    TRISE = 0x00;
    
    while(1){
        PORTD = 0b01001111; //acendendo os segmentos equivalentes ao n�mero 3 no display
    }
    
    return;
}
