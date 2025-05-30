#include "eeprom.h"
#include "i2c.h"

#define EEPROM_ADDR 0xA0 // Endereço base da EEPROM (24Cxx)

void delay_ms(unsigned int ms) {
    unsigned int i, j;
    for(i = 0; i < ms; i++)
        for(j = 0; j < 14000; j++) asm volatile("nop");
}

void eeprom_write_user(uint16_t index, Usuario user) {
    uint16_t addr = index * 8;
    uint8_t data[8];

    data[0] = user.id >> 8;
    data[1] = user.id & 0xFF;
    data[2] = user.senha >> 8;
    data[3] = user.senha & 0xFF;
    data[4] = user.tipo;
    data[5] = user.em_sala;
    data[6] = user.reservado[0];
    data[7] = user.reservado[1];

    i2c_start();
    i2c_write(EEPROM_ADDR);           // Slave address + Write
    i2c_write(addr >> 8);             // High byte do endereço
    i2c_write(addr & 0xFF);           // Low byte do endereço
    for (int i = 0; i < 8; i++) {
        i2c_write(data[i]);
    }
    i2c_stop();
    delay_ms(5); // Tempo de gravação da EEPROM
}

void eeprom_read_user(uint16_t index, Usuario* user) {
    uint16_t addr = index * 8;
    uint8_t data[8];

    i2c_start();
    i2c_write(EEPROM_ADDR);          // Write para definir endereço
    i2c_write(addr >> 8);
    i2c_write(addr & 0xFF);
    i2c_restart();
    i2c_write(EEPROM_ADDR | 0x01);   // Read mode

    for (int i = 0; i < 7; i++) {
        data[i] = i2c_read(1); // ACK
    }
    data[7] = i2c_read(0);     // NACK
    i2c_stop();

    user->id = (data[0] << 8) | data[1];
    user->senha = (data[2] << 8) | data[3];
    user->tipo = data[4];
    user->em_sala = data[5];
    user->reservado[0] = data[6];
    user->reservado[1] = data[7];
}
