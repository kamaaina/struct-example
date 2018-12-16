#include <string>
#include "common.h"

short Common::getByteValue(UINT64 data, int byte)
{
   UINT64 mask = 0xFFULL << (byte * 8);
   return (data & mask) >> (byte * 8);
}

void Common::setByteValue(UINT64 &data, short value, int byte)
{
   printf("*****value: %i byte: %i\n", value, byte);
   data |= (UINT64)value << (byte * 8);
}

void Common::resetByteValue(UINT64 &data, int byte)
{
   printf("##byte: %i\n", byte);
   data &= ~(0 << (byte * 8));
}

