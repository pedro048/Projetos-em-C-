#line 1 "E:/IFRN/Microcontroladores - mikroC/Aula de display 7 seg/Q1/Q1.c"

int cont = 0;
int sai = 0;

void interrupt(){

INTCON.TMR0IF = 0;
TMR0h = 0x48;
TMR0l = 0xE5;
cont = cont + 1;

}

void main() {

trisd = 0x00;
TMR0H = 0x48;
TMR0L = 0xE5;
T0CON = 0b10000110;
INTCON.TMR0IF = 0;
INTCON.GIEH = 1;
INTCON.TMR0IE = 1;
RCON.IPEN = 1;
INTCON2.TMR0IP = 1;

while(1){

 switch (cont) {

 case 0 : sai = 0b0111111; break;
 case 1 : sai = 0b0000110; break;
 case 2 : sai = 0b1011011; break;
 case 3 : sai = 0b1001111; break;
 case 4 : sai = 0b1100110; break;
 case 5 : sai = 0b1101101; break;
 case 6 : sai = 0b1111101; break;
 case 7 : sai = 0b0000111; break;
 case 8 : sai = 0b1111111; break;
 case 9 : sai = 0b1101111; break;
}
 portd = sai;

 if(cont == 10){
 cont = 0;
 }
}

}
