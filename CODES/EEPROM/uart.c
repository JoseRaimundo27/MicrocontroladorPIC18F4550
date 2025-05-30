#include <xc.h>
#include "uart.h"

void uart_init(void) {
    U1MODE = 0x8000; // Enable UART, 8-bit, no parity
    U1STA  = 0x0400; // Enable TX
    U1BRG  = 259;    // Para 9600 bps com PBCLK = 40 MHz
}

void uart_send_char(char c) {
    while (U1STAbits.UTXBF); // Espera até o buffer estar livre
    U1TXREG = c;
}

void uart_send_string(const char *str) {
    while (*str) {
        uart_send_char(*str++);
    }
}
