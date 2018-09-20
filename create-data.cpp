#include <iostream>
#include <string.h>
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

   ip = ((a << 24) | (b << 16) | (c << 8) | d);

#ifdef DEBUG
   cout << "ip: " << a << "." << b << "." << c << "." << d << "  (" << ip << ")" << endl;
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

#ifdef DEBUG
   cout << "mac: " << std::hex << uppercase
        << a << ":"
        << b << ":"
        << c << ":"
        << d << ":"
        << e << ":"
        << f << endl;
#endif
   
   mac = (((UINT64)a << 40) | ((UINT64)b << 32) | (c << 24) | (d << 16) | (e << 8) | f);
   return mac;
}

UINT16 generateProtocol()
{
   UINT16 proto = rand() % 10 + 1;
#ifdef DEBUG
   cout << std::dec << "protocol: " << proto << endl;
#endif
   return proto;
}

UINT64 generateUDPHeader()
{
   UINT64 udp = 0;
   UINT16 srcPort = rand() % 0xFFFF + 1;
   UINT16 destPort = rand() % 0xFFFF + 1;
   UINT16 length = rand() % 100 + 1;
   UINT16 checksum = rand() % 0xFFFF + 1;
   udp = ((UINT64)srcPort << 48) | ((UINT64)destPort << 32) | (length << 16) | checksum;
#ifdef DEBUG
   cout << "udp src port: " << srcPort << endl
        << "udp dest port: " << destPort << endl
        << "udp length: " << length << endl
        << std::hex << "checksum: 0x" << checksum << endl;
#endif
   return udp;
}

int main()
{
   // seed our random number generator
   srand (time(NULL));

   // output file to write data to (data will change each time)
   FILE *fp = fopen("bin/generated_data.bin", "wb");

   DataHeader *header = new DataHeader();
   memset(header, 0, sizeof(DataHeader));
   
   header->mac_src = generateMac();
   header->mac_dest = generateMac();
   header->next_protocol = generateProtocol();
   header->ip_src = generateIpAddr();
   header->ip_dest = generateIpAddr();
   header->udp_header = generateUDPHeader();
   fwrite(header, sizeof(DataHeader), 1, fp);

   // size of udp data - write 0xDD as data
   int size = (header->udp_header & 0xFFFF0000) >> 16;
   char *data = new char[size];
   memset(data, 0xDD, size);
   fwrite(data, size, 1, fp);

   delete [] data;
   delete header;
   fclose(fp);

   return 0;
}
