/**
 * CAN BUS
 *
 * Copyright (c) 2010 Sukkin Pang All rights reserved.
 */

#ifndef canbus__h
#define canbus__h

#include "mcp2515.h"

#define CANSPEED_125    7       // CAN speed at 125 kbps
#define CANSPEED_250    3       // CAN speed at 250 kbps
#define CANSPEED_500    1       // CAN speed at 500 kbps

class CanbusClass
{
public:

    CanbusClass();
    char init(unsigned char);
    char message_tx(void);
    char message_rx(unsigned char *buffer);
    char ecu_req(unsigned char pid,  char *buffer);
    char ecu_req(unsigned char pid,  tCAN *message);
private:

};
extern CanbusClass Canbus;

#endif
