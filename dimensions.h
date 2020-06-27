#ifndef DIMENSION_H
#define DIMENSION_H
#include "porter.h"

typedef struct DIM_STRUCT {
    p* ports;
    struct DIMENSIONS** dim;
    int dimension_port;
    struct {
        int port_in_use;
        size_t memory_span;
        size_t from_memory_block; /* 
            index of zero of ports memory array
        */
        int* memory_usage_blocks;
    } NormalMode;
    struct {} StrictMode;
    struct {} HighMode;
    struct {} LowMode;
} DIM_;

#define NORMAL_DIMENSION    0x1AF1 // 6897
#define LOW_DIMENSION       0x1551 // 5617
#define STRICT_DIMENSIOIN   0x0F20 /* 
    3872, will change depending on memory management and or memory ammounts
    being used up.
*/
#define HIGH_DIMENSION      0xDCF2 // 56562

DIM_* default_dimension_setup(PORTS* port);
DIM_* dimension_get_dimension_port(DIM_* dim);

#endif