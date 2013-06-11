#include "ODB2Response.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

ODB2Response::ODB2Response()
{

}
ODB2Response::ODB2Response( char const *name, int value, char const *units, uint8_t pid, uint8_t const *data )
{
    strncpy( this->name, name, 128 );
    this->value = value;
    strncpy( this->units, units, 128 );
    this->pid = pid;
    memcpy( this->data, data, 8 );

}