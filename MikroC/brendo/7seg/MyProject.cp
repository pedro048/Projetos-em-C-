#line 1 "C:/Users/Colab57-1/Desktop/brendo/7seg/MyProject.c"

int cont = 0;
int sai = 0;

void interrupt(){

tmr0l = 0xE5;
tmr0h = 0x48;
intcon.tmr0if = 0;
cont = cont + 1;

}

void main() {

trisd = 0x00;
TMR0H = 0x48;
TMR0L = 0xE5;
T0con = 0b10000110;
intcon.tmr0if = 0;
intcon.gieh = 1;
intcon.tmr0ie = 1;
rcon.ipen = 1;
intcon2.tmr0ip = 1;
rcon.ipen = 1;


while(1){

 switch (cont) {

 case 0 : sai = 0b1111110; break;
 case 1 : sai = 0b0110000; break;
 case 2 : sai = 0b0010010; break;
 case 3 : sai = 0b0000110; break;
 case 4 : sai = 0b1001100; break;
 case 5 : sai = 0b0100100; break;
 case 6 : sai = 0b0100000; break;
 case 7 : sai = 0b0001111; break;
 case 8 : sai = 0b0000000; break;
 case 9 : sai = 0b0000100; break;
}
 portd = sai;

}

}
