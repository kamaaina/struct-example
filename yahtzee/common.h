#ifndef __COMMON_H__
#define __COMMON_H__

typedef unsigned char  UINT8;
typedef unsigned short UINT16;
typedef unsigned int   UINT32;
typedef unsigned long  UINT64;

class Common
{
public:
   static short getByteValue(UINT64 data, int byte);
   static void setByteValue(UINT64 &data, short value, int byte);
   static void resetByteValue(UINT64 &data, int byte);
};

#endif
