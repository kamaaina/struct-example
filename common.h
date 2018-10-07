#ifndef __COMMON_H__
#define __COMMON_H__

typedef unsigned char  UINT8;  // 1 byte  - 8  bits
typedef unsigned short UINT16; // 2 bytes - 16 bits
typedef unsigned int   UINT32; // 4 bytes - 32 bits
typedef unsigned long  UINT64; // 8 bytes - 64 bits

typedef struct {
   UINT64 mac_src;
   UINT64 mac_dest;
   UINT16 next_protocol;
   UINT32 ip_src;
   UINT32 ip_dest;
   UINT64 udp_header;
} DataHeader;

#endif
