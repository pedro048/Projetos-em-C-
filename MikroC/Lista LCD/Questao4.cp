#line 1 "G:/IFRN/Microcontroladores - mikroC/Lista LCD/Questao4.c"
sbit LCD_RS at RE2_bit;
sbit LCD_EN at RE1_bit;
sbit LCD_D4 at RD4_bit;
sbit LCD_D5 at RD5_bit;
sbit LCD_D6 at RD6_bit;
sbit LCD_D7 at RD7_bit;
sbit LCD_RS_Direction at TRISE2_bit;
sbit LCD_EN_Direction at TRISE1_bit;
sbit LCD_D4_Direction at TRISD4_bit;
sbit LCD_D5_Direction at TRISD5_bit;
sbit LCD_D6_Direction at TRISD6_bit;
sbit LCD_D7_Direction at TRISD7_bit;


void main() {
trisb.rb0 = 1;
trisb.rb1 = 1;
 ADCON1 = 0b00001111;
 Lcd_Init();
 Lcd_cmd(_LCD_CLEAR);

 while (1){
if( portb.rb0 == 0){
 Lcd_out(1,2,"Chave um acionada");

 }
 if( portb.rb1 == 0){
 Lcd_out(1,2,"Chave dois acionada");
 }

 if(portb.rb0 == 1 && portb.rb1 == 1){
 Lcd_Cmd(_Lcd_clear);
 Lcd_out(1,2,"Nenhuma chave");
 }
}
}
