/*
 * File:   14-2-display-lcd.c
 * Author: Matheus
 *
 * Created on 3 de Julho de 2021, 17:32
 * 
 * Desenvolver um Quiz:
 * Utilizando o display LCD, voc� deve apresentar 3 perguntas.
 * Prever dois bot�es para respostas: SIM ou N�O.
 * Exibir uma tela de boas vindas com a mensagem: "QUIZ" na linha superior,
 * "UNIP" na linha inferior, centralizados.
 * Exibir uma tela coma pergunta, at� que seja respondida atrav�s dos bot�es.
 * Quando o usu�rio acertar a resposta, um led deve piscar 3 vezes, apresentar
 * uma mensagem "Parabens!" e a pr�xima pergunta ser� exibida.
 * Quando ousu�rio errar a resposta, um outro led devepiscar 2 vezes, apresentar
 * uma mensagem "Tente novamente" e a mesma pergunta ser� exibida.
 * Ao t�rmino das 3 perguntas, exibir uma tela com a mensagem ?FIM?.
 */


//Inserindo bibliotecas
#include <xc.h>
#include "configuracao_pic18f4550.h"
#include "biblioteca_lcd_2x16.h"

//Inserindo defini��es
#define _XTAL_FOSC 20000000 //Com uma Fosc de 20MHz temos um Tciclo de 0,2us

#define BOTAO_SIM     PORTBbits.RB0
#define BOTAO_NAO     PORTBbits.RB1
#define LED_ACERTOU   PORTCbits.RC0
#define LED_ERROU     PORTCbits.RC1

//Declarando prot�tipos de fun��es
void prepara_lcd(void);
void pergunta_1(void);
void pergunta_2(void);
void pergunta_3(void);
void acertou_pergunta(void);
void errou_pergunta(void);

void main(void) {
    
    //Configurando os perif�ricos do dispositivo
    TRISA = 0x00;
    TRISB = 0b00000011;
    TRISC = 0x00;
    TRISD = 0x00;
    TRISE = 0x00;
    
    //Inicializando o estado dos leds
    LED_ACERTOU = 0;
    LED_ERROU = 0;
    
    while(1){
        lcd_inicia(0x28,0x0F,0x06);
        //Display: 0x28 - comunica��o de 4 vias, duas linhas e matriz 8x5;
        //Cursor: 0x0F - liga o cursor com alternancia
        //Cursor: 0x06 - desloca o cursor para a direita quando um caractere � inserido, sem deslocar a mensagem
        prepara_lcd();
        lcd_posicao(1,7); //coloca o cursor na linha 1 e na coluna 7, ou seja, centraliza
        imprime_string_lcd("Quiz"); //envia uma string para o display de lcd
        lcd_posicao(2,7); //coloca o cursor na linha 2 e na coluna 7, ou seja, centraliza
        imprime_string_lcd("Quiz"); //envia uma string para o display de lcd
        _delay(5000000); //um delay de 5,000,000 de ciclos gera um atarso de 1 segundo
        while(1){
            prepara_lcd();      
            pergunta_1();
            if(BOTAO_SIM == 1){
                acertou_pergunta();
                break;
            }
            if(BOTAO_NAO == 1){
                errou_pergunta();                
            }           
        }
        while(1){
            prepara_lcd();      
            pergunta_2();
            if(BOTAO_SIM == 1){
                errou_pergunta();   
            }
            if(BOTAO_NAO == 1){
                acertou_pergunta();
                break;                             
            }
        }
        while(1){
            prepara_lcd();      
            pergunta_3();
            if(BOTAO_SIM == 1){
                acertou_pergunta();
                break;
            }
            if(BOTAO_NAO == 1){
                errou_pergunta();                
            }           
        }
        prepara_lcd();
        lcd_posicao(1,7); //coloca o cursor na linha 1 e na coluna 7, ou seja, centraliza
        imprime_string_lcd("FIM!"); //envia uma string para o display de lcd
        lcd_posicao(2,7); //coloca o cursor na linha 2 e na coluna 7, ou seja, centraliza
        imprime_string_lcd("FIM!"); //envia uma string para o display de lcd
        _delay(5000000); //um delay de 5,000,000 de ciclos gera um atarso de 1 segundo
        prepara_lcd();
        break;        
    }
    
    return;
}

void prepara_lcd(void){
    lcd_limpa_tela(); //limpa tela
    lcd_posicao(1,1); //coloca o cursor na linha 1 e na coluna 1
    lcd_LD_cursor(0); //desliga o cursor
}

void pergunta_1(void){
    lcd_posicao(1,1);
    imprime_string_lcd("Pergunta - 1"); 
    lcd_posicao(2,1); 
    imprime_string_lcd("E ou nao E?"); 
    _delay(100000); //um delay de 100.000 de ciclos gera um atarso de 20ms
}

void pergunta_2(void){
    lcd_posicao(1,1);
    imprime_string_lcd("Pergunta - 2"); 
    lcd_posicao(2,1); 
    imprime_string_lcd("E ou nao E?");
    _delay(100000); //um delay de 100.000 de ciclos gera um atarso de 20ms
}

void pergunta_3(void){
    lcd_posicao(1,1);
    imprime_string_lcd("Pergunta - 3"); 
    lcd_posicao(2,1); 
    imprime_string_lcd("E ou nao E?");  
    _delay(100000); //um delay de 100.000 de ciclos gera um atarso de 20ms
}

void acertou_pergunta(void){
    prepara_lcd();
    lcd_posicao(1,5);
    imprime_string_lcd("ACERTOU!");    
    lcd_posicao(2,5);
    imprime_string_lcd("PARABENS!");    
    LED_ACERTOU = 1;
    _delay(2500000);
    LED_ACERTOU = 0;
    _delay(2500000);
    LED_ACERTOU = 1;
    _delay(2500000);
    LED_ACERTOU = 0;
    _delay(2500000);
    LED_ACERTOU = 1;
    _delay(2500000);
    LED_ACERTOU = 0;
    _delay(2500000);    
}

void errou_pergunta(void){
    prepara_lcd();
    lcd_posicao(1,5);
    imprime_string_lcd("ERROU!!!"); 
    lcd_posicao(2,1);
    imprime_string_lcd("TENTE NOVAMENTE");    
    LED_ERROU = 1;
    _delay(2500000);
    LED_ERROU = 0;
    _delay(2500000);
    LED_ERROU = 1;
    _delay(2500000);
    LED_ERROU = 0;
    _delay(2500000);        
}
