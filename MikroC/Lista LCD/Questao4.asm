
_main:

;Questao4.c,15 :: 		void main() {
;Questao4.c,16 :: 		trisb.rb0 = 1;
	BSF         TRISB+0, 0 
;Questao4.c,17 :: 		trisb.rb1 = 1;
	BSF         TRISB+0, 1 
;Questao4.c,18 :: 		ADCON1 = 0b00001111;
	MOVLW       15
	MOVWF       ADCON1+0 
;Questao4.c,19 :: 		Lcd_Init();
	CALL        _Lcd_Init+0, 0
;Questao4.c,20 :: 		Lcd_cmd(_LCD_CLEAR);
	MOVLW       1
	MOVWF       FARG_Lcd_Cmd_out_char+0 
	CALL        _Lcd_Cmd+0, 0
;Questao4.c,22 :: 		while (1){
L_main0:
;Questao4.c,23 :: 		if( portb.rb0 == 0){
	BTFSC       PORTB+0, 0 
	GOTO        L_main2
;Questao4.c,24 :: 		Lcd_out(1,2,"Chave um acionada");
	MOVLW       1
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       2
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       ?lstr1_Questao4+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(?lstr1_Questao4+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;Questao4.c,26 :: 		}
L_main2:
;Questao4.c,27 :: 		if( portb.rb1 == 0){
	BTFSC       PORTB+0, 1 
	GOTO        L_main3
;Questao4.c,28 :: 		Lcd_out(1,2,"Chave dois acionada");
	MOVLW       1
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       2
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       ?lstr2_Questao4+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(?lstr2_Questao4+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;Questao4.c,29 :: 		}
L_main3:
;Questao4.c,31 :: 		if(portb.rb0 == 1 && portb.rb1 == 1){
	BTFSS       PORTB+0, 0 
	GOTO        L_main6
	BTFSS       PORTB+0, 1 
	GOTO        L_main6
L__main7:
;Questao4.c,32 :: 		Lcd_Cmd(_Lcd_clear);
	MOVLW       1
	MOVWF       FARG_Lcd_Cmd_out_char+0 
	CALL        _Lcd_Cmd+0, 0
;Questao4.c,33 :: 		Lcd_out(1,2,"Nenhuma chave");
	MOVLW       1
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       2
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       ?lstr3_Questao4+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(?lstr3_Questao4+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;Questao4.c,34 :: 		}
L_main6:
;Questao4.c,35 :: 		}
	GOTO        L_main0
;Questao4.c,36 :: 		}
L_end_main:
	GOTO        $+0
; end of _main
