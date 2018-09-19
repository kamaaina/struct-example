#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "common.h"

using namespace std;

UINT32 generateIpAddr()
{
   UINT32 ip = 0;
   
   // generate secret number between 1 and 255
   short a = rand() % 255 + 1;
   short b = rand() % 255 + 1;
   short c = rand() % 255 + 1;
   short d = rand() % 255 + 1;
#ifdef DEBUG
   cout << "a: " << a
        << " b: " << b
        << " c: " << c
        << " d: " << d << endl;
#endif

   ip = ((a << 24) | (b << 16) | (c << 8) | d);

#ifdef DEBUG   
   cout << "ip: " << ip << endl;
#endif
   
   return ip;
}

UINT64 generateMac()
{
   UINT64 mac = 0; // only using 6 of the 8 bytes
   short a = rand() % 255 + 1;
   short b = rand() % 255 + 1;
   short c = rand() % 255 + 1;
   short d = rand() % 255 + 1;
   short e = rand() % 255 + 1;
   short f = rand() % 255 + 1;

   mac = (((UINT64)a << 40) | ((UINT64)b << 32) | (c << 24) | (d << 16) | (e << 8) | f);
   return mac;
}

UINT16 generateProtocol()
{
   UINT16 proto = rand() % 10 + 1;
   return proto;
}

UINT64 generateUDPHeader()
{
   UINT64 udp = 0;
   UINT16 srcPort = rand() % 65536 + 1;
   UINT16 destPort = rand() % 65536 + 1;
   UINT16 length = rand() % 65536 + 1;
   UINT16 checksum = rand() % 65536 + 1;
   udp = ((UINT64)srcPort << 48) | ((UINT64)destPort << 32) | (length << 16) | checksum;
   return udp;
}

int main()
{
   srand (time(NULL));

   FILE *fp = fopen("bin/generated_data.bin", "wb");
   UINT64 mac = generateMac();
   fwrite(&mac, sizeof(UINT64),  1, fp);
   mac = generateMac();
   fwrite(&mac, sizeof(UINT64),  1, fp);

   UINT16 proto = generateProtocol();
   fwrite(&proto, sizeof(UINT16),  1, fp);

   UINT32 ip = generateIpAddr();
   fwrite(&ip, sizeof(UINT32),  1, fp);
   ip = generateIpAddr();
   fwrite(&ip, sizeof(UINT32),  1, fp);

   UINT64 udp = generateUDPHeader();
   fwrite(&udp, sizeof(UINT64),  1, fp);   

   fclose(fp);

   cout << "Done writing data" << endl;
   return 0;
}
