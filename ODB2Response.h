#ifndef ODB2RESPONSE_H
#define ODB2RESPONSE_H

#include <stdint.h>

class ODB2Response
{
public:
    uint8_t pid;
    uint8_t data[8];
    char name[128];
    int value;
    char units[128];
    
    ODB2Response();
    ODB2Response( char const *name, int value, char const *units, uint8_t pid, uint8_t const *data );

};

#endif