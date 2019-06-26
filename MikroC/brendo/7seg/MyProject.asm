
_interrupt:

;MyProject.c,5 :: 		void interrupt(){
;MyProject.c,7 :: 		tmr0l = 0xE5;
	MOVLW       229
	MOVWF       TMR0L+0 
;MyProject.c,8 :: 		tmr0h = 0x48;
	MOVLW       72
	MOVWF       TMR0H+0 
;MyProject.c,9 :: 		intcon.tmr0if = 0;
	BCF         INTCON+0, 2 
;MyProject.c,10 :: 		cont = cont + 1;
	INFSNZ      _cont+0, 1 
	INCF        _cont+1, 1 
;MyProject.c,12 :: 		}
L_end_interrupt:
L__interrupt15:
	RETFIE      1
; end of _interrupt

_main:

;MyProject.c,14 :: 		void main() {
;MyProject.c,16 :: 		trisd = 0x00;
	CLRF        TRISD+0 
;MyProject.c,17 :: 		TMR0H = 0x48;
	MOVLW       72
	MOVWF       TMR0H+0 
;MyProject.c,18 :: 		TMR0L = 0xE5;
	MOVLW       229
	MOVWF       TMR0L+0 
;MyProject.c,19 :: 		T0con = 0b10000110;
	MOVLW       134
	MOVWF       T0CON+0 
;MyProject.c,20 :: 		intcon.tmr0if = 0;
	BCF         INTCON+0, 2 
;MyProject.c,21 :: 		intcon.gieh = 1;
	BSF         INTCON+0, 7 
;MyProject.c,22 :: 		intcon.tmr0ie = 1;
	BSF         INTCON+0, 5 
;MyProject.c,23 :: 		rcon.ipen = 1;
	BSF         RCON+0, 7 
;MyProject.c,24 :: 		intcon2.tmr0ip = 1;
	BSF         INTCON2+0, 2 
;MyProject.c,25 :: 		rcon.ipen = 1;
	BSF         RCON+0, 7 
;MyProject.c,28 :: 		while(1){
L_main0:
;MyProject.c,30 :: 		switch (cont) {
	GOTO        L_main2
;MyProject.c,32 :: 		case 0 : sai =  0b1111110; break;
L_main4:
	MOVLW       126
	MOVWF       _sai+0 
	MOVLW       0
	MOVWF       _sai+1 
	GOTO        L_main3
;MyProject.c,33 :: 		case 1 : sai =  0b0110000; break;
L_main5:
	MOVLW       48
	MOVWF       _sai+0 
	MOVLW       0
	MOVWF       _sai+1 
	GOTO        L_main3
;MyProject.c,34 :: 		case 2 : sai =  0b0010010; break;
L_main6:
	MOVLW       18
	MOVWF       _sai+0 
	MOVLW       0
	MOVWF       _sai+1 
	GOTO        L_main3
;MyProject.c,35 :: 		case 3 : sai =  0b0000110; break;
L_main7:
	MOVLW       6
	MOVWF       _sai+0 
	MOVLW       0
	MOVWF       _sai+1 
	GOTO        L_main3
;MyProject.c,36 :: 		case 4 : sai =  0b1001100; break;
L_main8:
	MOVLW       76
	MOVWF       _sai+0 
	MOVLW       0
	MOVWF       _sai+1 
	GOTO        L_main3
;MyProject.c,37 :: 		case 5 : sai =  0b0100100; break;
L_main9:
	MOVLW       36
	MOVWF       _sai+0 
	MOVLW       0
	MOVWF       _sai+1 
	GOTO        L_main3
;MyProject.c,38 :: 		case 6 : sai =  0b0100000; break;
L_main10:
	MOVLW       32
	MOVWF       _sai+0 
	MOVLW       0
	MOVWF       _sai+1 
	GOTO        L_main3
;MyProject.c,39 :: 		case 7 : sai =  0b0001111; break;
L_main11:
	MOVLW       15
	MOVWF       _sai+0 
	MOVLW       0
	MOVWF       _sai+1 
	GOTO        L_main3
;MyProject.c,40 :: 		case 8 : sai =  0b0000000; break;
L_main12:
	CLRF        _sai+0 
	CLRF        _sai+1 
	GOTO        L_main3
;MyProject.c,41 :: 		case 9 : sai =  0b0000100; break;
L_main13:
	MOVLW       4
	MOVWF       _sai+0 
	MOVLW       0
	MOVWF       _sai+1 
	GOTO        L_main3
;MyProject.c,42 :: 		}
L_main2:
	MOVLW       0
	XORWF       _cont+1, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__main17
	MOVLW       0
	XORWF       _cont+0, 0 
L__main17:
	BTFSC       STATUS+0, 2 
	GOTO        L_main4
	MOVLW       0
	XORWF       _cont+1, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__main18
	MOVLW       1
	XORWF       _cont+0, 0 
L__main18:
	BTFSC       STATUS+0, 2 
	GOTO        L_main5
	MOVLW       0
	XORWF       _cont+1, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__main19
	MOVLW       2
	XORWF       _cont+0, 0 
L__main19:
	BTFSC       STATUS+0, 2 
	GOTO        L_main6
	MOVLW       0
	XORWF       _cont+1, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__main20
	MOVLW       3
	XORWF       _cont+0, 0 
L__main20:
	BTFSC       STATUS+0, 2 
	GOTO        L_main7
	MOVLW       0
	XORWF       _cont+1, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__main21
	MOVLW       4
	XORWF       _cont+0, 0 
L__main21:
	BTFSC       STATUS+0, 2 
	GOTO        L_main8
	MOVLW       0
	XORWF       _cont+1, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__main22
	MOVLW       5
	XORWF       _cont+0, 0 
L__main22:
	BTFSC       STATUS+0, 2 
	GOTO        L_main9
	MOVLW       0
	XORWF       _cont+1, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__main23
	MOVLW       6
	XORWF       _cont+0, 0 
L__main23:
	BTFSC       STATUS+0, 2 
	GOTO        L_main10
	MOVLW       0
	XORWF       _cont+1, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__main24
	MOVLW       7
	XORWF       _cont+0, 0 
L__main24:
	BTFSC       STATUS+0, 2 
	GOTO        L_main11
	MOVLW       0
	XORWF       _cont+1, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__main25
	MOVLW       8
	XORWF       _cont+0, 0 
L__main25:
	BTFSC       STATUS+0, 2 
	GOTO        L_main12
	MOVLW       0
	XORWF       _cont+1, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__main26
	MOVLW       9
	XORWF       _cont+0, 0 
L__main26:
	BTFSC       STATUS+0, 2 
	GOTO        L_main13
L_main3:
;MyProject.c,43 :: 		portd = sai;
	MOVF        _sai+0, 0 
	MOVWF       PORTD+0 
;MyProject.c,45 :: 		}
	GOTO        L_main0
;MyProject.c,47 :: 		}
L_end_main:
	GOTO        $+0
; end of _main
