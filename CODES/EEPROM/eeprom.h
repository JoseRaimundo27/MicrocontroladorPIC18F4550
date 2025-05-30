#ifndef EEPROM_H
#define EEPROM_H

#include "types.h"
void delay_ms(unsigned int ms);

void eeprom_init(void);
void eeprom_write_user(uint16_t index, Usuario user);
void eeprom_read_user(uint16_t index, Usuario* user);

#endif
