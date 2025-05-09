
_main:

;ProjetoTeste.c,2 :: 		void main() {
;ProjetoTeste.c,4 :: 		TRISB = 0;           // set direction to be output
	CLRF        TRISB+0 
;ProjetoTeste.c,6 :: 		do {
L_main0:
;ProjetoTeste.c,7 :: 		PORTB = 0x00;       // Turn OFF LEDs on PORTB
	CLRF        PORTB+0 
;ProjetoTeste.c,8 :: 		Delay_ms(1000);    // 1 second delay
	MOVLW       6
	MOVWF       R11, 0
	MOVLW       19
	MOVWF       R12, 0
	MOVLW       173
	MOVWF       R13, 0
L_main3:
	DECFSZ      R13, 1, 1
	BRA         L_main3
	DECFSZ      R12, 1, 1
	BRA         L_main3
	DECFSZ      R11, 1, 1
	BRA         L_main3
	NOP
	NOP
;ProjetoTeste.c,10 :: 		PORTB = 0xFF;       // Turn ON LEDs on PORTB
	MOVLW       255
	MOVWF       PORTB+0 
;ProjetoTeste.c,11 :: 		Delay_ms(1000);    // 1 second delay
	MOVLW       6
	MOVWF       R11, 0
	MOVLW       19
	MOVWF       R12, 0
	MOVLW       173
	MOVWF       R13, 0
L_main4:
	DECFSZ      R13, 1, 1
	BRA         L_main4
	DECFSZ      R12, 1, 1
	BRA         L_main4
	DECFSZ      R11, 1, 1
	BRA         L_main4
	NOP
	NOP
;ProjetoTeste.c,12 :: 		} while(1);          // Endless loop
	GOTO        L_main0
;ProjetoTeste.c,13 :: 		}
L_end_main:
	GOTO        $+0
; end of _main
