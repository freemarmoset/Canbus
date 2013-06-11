
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "ODB2Parser.h"
#include "ODB2Response.h"
#include "mcp2515.h"
#include "pids.h"


ODB2Response ODB2Parser::parse( tCAN const *rawResponse )
{

    uint8_t pid = rawResponse->data[2];

    switch (pid)
    {
      /* Details from http://en.wikipedia.org/wiki/OBD-II_PIDs */
      case ENGINE_RPM:        //   ((A*256)+B)/4    [RPM]
      {
          int value =  ((rawResponse->data[3] * 256) + rawResponse->data[4]) / 4;
          ODB2Response response( "CAN_ENGINE_RPM", value, "rpm", pid, rawResponse->data );
          return response;
      }
      case ENGINE_COOLANT_TEMP:   //  A-40        [degree C]
      {
          int value =  rawResponse->data[3] - 40;
          ODB2Response response( "CAN_ENGINE_COOLANT_TEMP", value, "degC", pid, rawResponse->data );
          return response;
      }
      case VEHICLE_SPEED:     // A          [km]
      {
          int value =  rawResponse->data[3];
          ODB2Response response( "CAN_VEHICLE_SPEED", value, "km/h", pid, rawResponse->data );
          return response;
      }
      case MAF_SENSOR:        // ((256*A)+B) / 100  [g/s]
      {
          int value =  ((rawResponse->data[3] * 256) + rawResponse->data[4]) / 100;
          ODB2Response response( "CAN_MAF_SENSOR", value, "grams/sec", pid, rawResponse->data );
          return response;
      }
      case THROTTLE:        // Throttle Position
      {
          int value = (rawResponse->data[3] * 100) / 255;
          ODB2Response response( "CAN_THROTTLE_POSITION", value, "%", pid, rawResponse->data );
          return response;
      }
      case FUEL_LEVEL:        
      {
          int value = (rawResponse->data[3] * 100) / 255;
          ODB2Response response( "CAN_FUEL_LEVEL", value, "%", pid, rawResponse->data );
          return response;
      }
      default:
      {
          ODB2Response response( "CAN_UNKONWN", 0, "?", pid, rawResponse->data );
          return response;
      }
    }

}