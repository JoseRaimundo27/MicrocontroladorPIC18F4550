#ifndef TYPES_H
#define TYPES_H

#include <stdint.h>

typedef struct {
    uint16_t id;          // 2 bytes
    uint16_t senha;       // 2 bytes
    uint8_t tipo;         // 1 byte (0 = normal, 1 = master)
    uint8_t em_sala;      // 1 byte (0 = não, 1 = sim)
    uint8_t reservado[2]; // 2 bytes para alinhamento
} Usuario;

#endif
