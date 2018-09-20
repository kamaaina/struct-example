#include <iostream>
#include <sstream>
#include <string.h>
#include "common.h"

template <typename T> std::string to_string(const T& n)
{
   std::ostringstream oss;
   oss << n;
   return oss.str();
}

void getIpStr(UINT32 ip)
{
   short a = (short)((ip & 0xff000000) >> 24);
   short b = (short)((ip & 0xff0000) >> 16);
   short c = (short)((ip & 0xff00) >> 8);
   short d = (short)(ip & 0xff);

   std::cout << std::dec
             << a << "."
             << b << "."
             << c << "."
             << d << std::endl;
}

void getMacStr(UINT64 mac)
{
   short a = (short)((mac & 0xff0000000000) >> 40);
   short b = (short)((mac & 0xff00000000) >> 32);
   short c = (short)((mac & 0xff000000) >> 24);
   short d = (short)((mac & 0xff0000) >> 16);
   short e = (short)((mac & 0xff00) >> 8);
   short f = (short)(mac & 0xff);

   std::cout << std::hex << std::uppercase
             << a << ":"
             << b << ":"
             << c << ":"
             << d << ":"
             << e << ":"
             << f << std::endl;
}

void getUDPHeader(UINT64 udp)
{
   UINT16 srcPort = (udp & 0xFFFF000000000000) >> 48;
   UINT16 destPort = (udp & 0xFFFF00000000) >> 32;
   UINT16 length = (udp & 0xFFFF0000) >> 16;
   UINT16 checksum = udp & 0xFFFF;
   std::cout << "srcPort: " << srcPort << std::endl
             << "destPort: " << destPort << std::endl
             << "length: " << length << std::endl
             << std::hex << "checksum: 0x" << std::uppercase << checksum << std::endl;
}

void printDataHeader(DataHeader* header)
{
   std::cout << "MAC SRC: ";
   getMacStr(header->mac_src);
   std::cout << "MAC dest: ";
   getMacStr(header->mac_dest);
   std::cout << "Next Protocol: " << header->next_protocol << std::endl;
   std::cout << "IP SRC: ";
   getIpStr(header->ip_src);
   std::cout << "IP DEST: ";
   getIpStr(header->ip_dest);
   std::cout << "-UDP Header-\n";
   getUDPHeader(header->udp_header);
}

int main(int argc, char* argv[])
{
   if (argc != 2)
   {
      std::cerr << "\n\tUsage: " << argv[0] << " <file>\n" << std::endl;
      return 1;
   }
   
   // read the file and parse out the data
   FILE* fp = fopen(argv[1], "rb");
   if (!fp)
   {
      std::cerr << "Error opening file. Aborting!" << std::endl;
      return 2;
   }

   DataHeader* header = new DataHeader();
   memset(header, 0, sizeof(DataHeader));
   fread(header, sizeof(DataHeader), 1, fp);
   fclose(fp);

   printDataHeader(header);
   
   delete header;
   
   return 0;
}
