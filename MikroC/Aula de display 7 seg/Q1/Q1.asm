
_interrupt:

;Q1.c,5 :: 		void interrupt(){
;Q1.c,7 :: 		INTCON.TMR0IF = 0;
	BCF         INTCON+0, 2 
;Q1.c,8 :: 		TMR0h = 0x48;
	MOVLW       72
	MOVWF       TMR0H+0 
;Q1.c,9 :: 		TMR0l = 0xE5;
	MOVLW       229
	MOVWF       TMR0L+0 
;Q1.c,10 :: 		cont = cont + 1;
	INFSNZ      _cont+0, 1 
	INCF        _cont+1, 1 
;Q1.c,12 :: 		}
L_end_interrupt:
L__interrupt16:
	RETFIE      1
; end of _interrupt

_main:

;Q1.c,14 :: 		void main() {
;Q1.c,16 :: 		trisd = 0x00;
	CLRF        TRISD+0 
;Q1.c,17 :: 		TMR0H = 0x48;
	MOVLW       72
	MOVWF       TMR0H+0 
;Q1.c,18 :: 		TMR0L = 0xE5;
	MOVLW       229
	MOVWF       TMR0L+0 
;Q1.c,19 :: 		T0CON = 0b10000110;
	MOVLW       134
	MOVWF       T0CON+0 
;Q1.c,20 :: 		INTCON.TMR0IF = 0;
	BCF         INTCON+0, 2 
;Q1.c,21 :: 		INTCON.GIEH = 1;
	BSF         INTCON+0, 7 
;Q1.c,22 :: 		INTCON.TMR0IE = 1;
	BSF         INTCON+0, 5 
;Q1.c,23 :: 		RCON.IPEN = 1;
	BSF         RCON+0, 7 
;Q1.c,24 :: 		INTCON2.TMR0IP = 1;
	BSF         INTCON2+0, 2 
;Q1.c,26 :: 		while(1){
L_main0:
;Q1.c,28 :: 		switch (cont) {
	GOTO        L_main2
;Q1.c,30 :: 		case 0 : sai =  0b0111111; break;
L_main4:
	MOVLW       63
	MOVWF       _sai+0 
	MOVLW       0
	MOVWF       _sai+1 
	GOTO        L_main3
;Q1.c,31 :: 		case 1 : sai =  0b0000110; break;
L_main5:
	MOVLW       6
	MOVWF       _sai+0 
	MOVLW       0
	MOVWF       _sai+1 
	GOTO        L_main3
;Q1.c,32 :: 		case 2 : sai =  0b1011011; break;
L_main6:
	MOVLW       91
	MOVWF       _sai+0 
	MOVLW       0
	MOVWF       _sai+1 
	GOTO        L_main3
;Q1.c,33 :: 		case 3 : sai =  0b1001111; break;
L_main7:
	MOVLW       79
	MOVWF       _sai+0 
	MOVLW       0
	MOVWF       _sai+1 
	GOTO        L_main3
;Q1.c,34 :: 		case 4 : sai =  0b1100110; break;
L_main8:
	MOVLW       102
	MOVWF       _sai+0 
	MOVLW       0
	MOVWF       _sai+1 
	GOTO        L_main3
;Q1.c,35 :: 		case 5 : sai =  0b1101101; break;
L_main9:
	MOVLW       109
	MOVWF       _sai+0 
	MOVLW       0
	MOVWF       _sai+1 
	GOTO        L_main3
;Q1.c,36 :: 		case 6 : sai =  0b1111101; break;
L_main10:
	MOVLW       125
	MOVWF       _sai+0 
	MOVLW       0
	MOVWF       _sai+1 
	GOTO        L_main3
;Q1.c,37 :: 		case 7 : sai =  0b0000111; break;
L_main11:
	MOVLW       7
	MOVWF       _sai+0 
	MOVLW       0
	MOVWF       _sai+1 
	GOTO        L_main3
;Q1.c,38 :: 		case 8 : sai =  0b1111111; break;
L_main12:
	MOVLW       127
	MOVWF       _sai+0 
	MOVLW       0
	MOVWF       _sai+1 
	GOTO        L_main3
;Q1.c,39 :: 		case 9 : sai =  0b1101111; break;
L_main13:
	MOVLW       111
	MOVWF       _sai+0 
	MOVLW       0
	MOVWF       _sai+1 
	GOTO        L_main3
;Q1.c,40 :: 		}
L_main2:
	MOVLW       0
	XORWF       _cont+1, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__main18
	MOVLW       0
	XORWF       _cont+0, 0 
L__main18:
	BTFSC       STATUS+0, 2 
	GOTO        L_main4
	MOVLW       0
	XORWF       _cont+1, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__main19
	MOVLW       1
	XORWF       _cont+0, 0 
L__main19:
	BTFSC       STATUS+0, 2 
	GOTO        L_main5
	MOVLW       0
	XORWF       _cont+1, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__main20
	MOVLW       2
	XORWF       _cont+0, 0 
L__main20:
	BTFSC       STATUS+0, 2 
	GOTO        L_main6
	MOVLW       0
	XORWF       _cont+1, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__main21
	MOVLW       3
	XORWF       _cont+0, 0 
L__main21:
	BTFSC       STATUS+0, 2 
	GOTO        L_main7
	MOVLW       0
	XORWF       _cont+1, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__main22
	MOVLW       4
	XORWF       _cont+0, 0 
L__main22:
	BTFSC       STATUS+0, 2 
	GOTO        L_main8
	MOVLW       0
	XORWF       _cont+1, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__main23
	MOVLW       5
	XORWF       _cont+0, 0 
L__main23:
	BTFSC       STATUS+0, 2 
	GOTO        L_main9
	MOVLW       0
	XORWF       _cont+1, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__main24
	MOVLW       6
	XORWF       _cont+0, 0 
L__main24:
	BTFSC       STATUS+0, 2 
	GOTO        L_main10
	MOVLW       0
	XORWF       _cont+1, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__main25
	MOVLW       7
	XORWF       _cont+0, 0 
L__main25:
	BTFSC       STATUS+0, 2 
	GOTO        L_main11
	MOVLW       0
	XORWF       _cont+1, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__main26
	MOVLW       8
	XORWF       _cont+0, 0 
L__main26:
	BTFSC       STATUS+0, 2 
	GOTO        L_main12
	MOVLW       0
	XORWF       _cont+1, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__main27
	MOVLW       9
	XORWF       _cont+0, 0 
L__main27:
	BTFSC       STATUS+0, 2 
	GOTO        L_main13
L_main3:
;Q1.c,41 :: 		portd = sai;
	MOVF        _sai+0, 0 
	MOVWF       PORTD+0 
;Q1.c,43 :: 		if(cont == 10){
	MOVLW       0
	XORWF       _cont+1, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__main28
	MOVLW       10
	XORWF       _cont+0, 0 
L__main28:
	BTFSS       STATUS+0, 2 
	GOTO        L_main14
;Q1.c,44 :: 		cont = 0;
	CLRF        _cont+0 
	CLRF        _cont+1 
;Q1.c,45 :: 		}
L_main14:
;Q1.c,46 :: 		}
	GOTO        L_main0
;Q1.c,48 :: 		}
L_end_main:
	GOTO        $+0
; end of _main
