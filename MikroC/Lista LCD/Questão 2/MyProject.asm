
_main:

;MyProject.c,15 :: 		void main() {
;MyProject.c,16 :: 		ADCON1 = 0b00001111;
	MOVLW       15
	MOVWF       ADCON1+0 
;MyProject.c,17 :: 		Lcd_Init();
	CALL        _Lcd_Init+0, 0
;MyProject.c,18 :: 		Lcd_cmd(_LCD_CLEAR);
	MOVLW       1
	MOVWF       FARG_Lcd_Cmd_out_char+0 
	CALL        _Lcd_Cmd+0, 0
;MyProject.c,19 :: 		while (1){
L_main0:
;MyProject.c,20 :: 		for(i=0; i<=17; i++){
	CLRF        _i+0 
	CLRF        _i+1 
L_main2:
	MOVLW       128
	MOVWF       R0 
	MOVLW       128
	XORWF       _i+1, 0 
	SUBWF       R0, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__main7
	MOVF        _i+0, 0 
	SUBLW       17
L__main7:
	BTFSS       STATUS+0, 0 
	GOTO        L_main3
;MyProject.c,21 :: 		Lcd_out(1,i, "oi");
	MOVLW       1
	MOVWF       FARG_Lcd_Out_row+0 
	MOVF        _i+0, 0 
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       ?lstr1_MyProject+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(?lstr1_MyProject+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;MyProject.c,22 :: 		delay_ms(1000);
	MOVLW       61
	MOVWF       R11, 0
	MOVLW       225
	MOVWF       R12, 0
	MOVLW       63
	MOVWF       R13, 0
L_main5:
	DECFSZ      R13, 1, 1
	BRA         L_main5
	DECFSZ      R12, 1, 1
	BRA         L_main5
	DECFSZ      R11, 1, 1
	BRA         L_main5
	NOP
	NOP
;MyProject.c,23 :: 		Lcd_cmd(_LCD_CLEAR);
	MOVLW       1
	MOVWF       FARG_Lcd_Cmd_out_char+0 
	CALL        _Lcd_Cmd+0, 0
;MyProject.c,20 :: 		for(i=0; i<=17; i++){
	INFSNZ      _i+0, 1 
	INCF        _i+1, 1 
;MyProject.c,24 :: 		}
	GOTO        L_main2
L_main3:
;MyProject.c,25 :: 		}
	GOTO        L_main0
;MyProject.c,26 :: 		}
L_end_main:
	GOTO        $+0
; end of _main
