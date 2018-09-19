#include <iostream>
#include <string.h>
#include "common.h"

std::string getIpStr(UINT32 ip)
{
   std::string ipStr = "";
   short a = (short)((ip & 0xff000000) >> 24);
   short b = (short)((ip & 0xff0000) >> 16);
   short c = (short)((ip & 0xff00) >> 8);
   short d = (short)(ip & 0xff);

   ipStr += std::to_string(a);
   ipStr += ".";
   ipStr += std::to_string(b);
   ipStr += ".";
   ipStr += std::to_string(c);
   ipStr += ".";
   ipStr += std::to_string(d);
   
#ifdef DEBUG   
   cout << ipStr << endl;
#endif
   
   return ipStr;
}

std::string bytesToString(UINT64 bytes)
{
   return "";
}

std::string getMacStr(UINT64 mac)
{
   return bytesToString(mac);
}

std::string getNextProtocol(UINT16 proto)
{
   return bytesToString(proto);
}

std::string getUDPHeader(UINT64 udp)
{
   return bytesToString(udp);
}

void printDataHeader(DataHeader* header)
{
   std::cout << "MAC src: " << getMacStr(header->mac_src) << std::endl;
   std::cout << "MAC dest: " << getMacStr(header->mac_dest) << std::endl;
   std::cout << "Next Protocol: " << getNextProtocol(header->next_protocol) << std::endl;
   std::cout << "IP src: " << getIpStr(header->ip_src) << std::endl;
   std::cout << "IP dest: " << getIpStr(header->ip_dest) << std::endl;
   std::cout << "UDP Header: " << getUDPHeader(header->udp_header) << std::endl;
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

   fclose(fp);

   printDataHeader(header);
   
   delete header;
   
   return 0;
}
