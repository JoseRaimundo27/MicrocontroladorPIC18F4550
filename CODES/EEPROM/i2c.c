#include <xc.h>
#include "i2c.h"

void i2c_init(void) {
    I2C1BRG = 0x0C2; // Aproximadamente 100 kHz (ajuste para seu clock)
    I2C1CON = 0x8200;
}

void i2c_start(void) {
    I2C1CONbits.SEN = 1;
    while (I2C1CONbits.SEN);
}

void i2c_restart(void) {
    I2C1CONbits.RSEN = 1;
    while (I2C1CONbits.RSEN);
}

void i2c_stop(void) {
    I2C1CONbits.PEN = 1;
    while (I2C1CONbits.PEN);
}

void i2c_write(uint8_t data) {
    I2C1TRN = data;
    while (I2C1STATbits.TRSTAT);
    while (I2C1STATbits.ACKSTAT); // Verifica ACK
}

uint8_t i2c_read(uint8_t ack) {
    I2C1CONbits.RCEN = 1;
    while (!I2C1STATbits.RBF);
    uint8_t data = I2C1RCV;
    I2C1CONbits.ACKDT = (ack ? 0 : 1); // 0 = ACK, 1 = NACK
    I2C1CONbits.ACKEN = 1;
    while (I2C1CONbits.ACKEN);
    return data;
}
