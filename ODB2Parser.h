#ifndef ODB2_PARSER_H
#define ODB2_PARSER_H

#include "mcp2515.h"


class ODB2Response;

class ODB2Parser
{
  public:
  static ODB2Response parse( tCAN const * rawResponse );
};

#endif