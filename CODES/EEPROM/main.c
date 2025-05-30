#include "eeprom.h"
#include "i2c.h"
#include "types.h"
#include "uart.h"

#include <stdio.h> // para sprintf()

void main(void) {
    i2c_init();
    uart_init(); // Inicializa UART1 a 9600 bps

    Usuario master = { .id = 1234, .senha = 5678, .tipo = 1, .em_sala = 0, .reservado = {0, 0} };
    eeprom_write_user(0, master);

    Usuario lido;
    eeprom_read_user(0, &lido);

    char buffer[64];
    sprintf(buffer, "ID: %u\nSenha: %u\nTipo: %u\nEm sala: %u\n",
            lido.id, lido.senha, lido.tipo, lido.em_sala);
    uart_send_string(buffer); // Envia para o terminal serial

    while(1);
}
