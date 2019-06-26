
_main:

;Questao1.c,15 :: 		void main() {
;Questao1.c,16 :: 		ADCON1 = 0b00001111;
	MOVLW       15
	MOVWF       ADCON1+0 
;Questao1.c,17 :: 		Lcd_Init();
	CALL        _Lcd_Init+0, 0
;Questao1.c,18 :: 		Lcd_cmd(_LCD_CLEAR);
	MOVLW       1
	MOVWF       FARG_Lcd_Cmd_out_char+0 
	CALL        _Lcd_Cmd+0, 0
;Questao1.c,19 :: 		while (1){
L_main0:
;Questao1.c,20 :: 		Lcd_out(1,2, "oi");
	MOVLW       1
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       2
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       ?lstr1_Questao1+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(?lstr1_Questao1+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;Questao1.c,21 :: 		Lcd_out(2,2, "mundo");
	MOVLW       2
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       2
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       ?lstr2_Questao1+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(?lstr2_Questao1+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;Questao1.c,22 :: 		}
	GOTO        L_main0
;Questao1.c,23 :: 		}
L_end_main:
	GOTO        $+0
; end of _main
