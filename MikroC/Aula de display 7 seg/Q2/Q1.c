
int cont_1 = 0;
int cont_2 = 0;
int sai = 0;

void interrupt(){          // Alta prioridade

INTCON.TMR0IF = 0;
TMR0H = 0x48;
TMR0L = 0xE5;
cont_1 = cont_1 + 1;

}

void interrupt(){       // Baixa prioridade

PIR1.TMR1IF = 0;
TMR1H = 0xE2;
TMR0L = 0xAC;
cont_2 = cont_2 + 1;

}

void main() {

trisd = 0x00;    //Configura como saida o PORTD para ligar os displays 7 seg

TMR0H = 0x48;
TMR0L = 0xE5;

TMR1H = 0xE2;
TMR1L = 0xAC;

T0CON = 0b10000111;  //Habilita o TIMER0 com 16 bits, clock interno, PreS ativado e no valor de 256


T1CON =	0b11110101;  /*Habilita o TIMER1 com 16 bits, clock interno sem sincronismo com o clock externo,
                      oscilador do TIMER1 desabilitado com Pres de 2*/

RCON.IPEN = 1;    //Habilita o modo de alta e baixa prioridade de interrupcao
INTCON2 = 0b10000100;   //Desabilita os pull-ups e atribui alta prioridade ao TIMER0

INTCON     0b11100000; //Habilita o GIEH, GIEL e a interrupcao de TIMER0

IPR1.TMR1IP = 0;  //Interrupcao de TIMER1 como baixa prioridade
PIE1.TMR1IE = 1;  // Habilita a interrupcao de TIMER1

while(1){

 switch (cont_1) {

     case 0 : sai =  0b0111111; break;
     case 1 : sai =  0b0000110; break;
     case 2 : sai =  0b1011011; break;
     case 3 : sai =  0b1001111; break;
     case 4 : sai =  0b1100110; break;
     case 5 : sai =  0b1101101; break;
     case 6 : sai =  0b1111101; break;
     case 7 : sai =  0b0000111; break;
     case 8 : sai =  0b1111111; break;
     case 9 : sai =  0b1101111; break;
}
     portd = sai;


}

}