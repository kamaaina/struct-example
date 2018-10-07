#include <iostream>
#include "command.h"

Command::Command()
{
}

Command::~Command()
{
}

char Command::getCommand()
{
   char cmd;
   std::cout << "What would you like to do?\n"
      << "\t p - print scorecard\n"
      << "\t r - roll dice\n"
      << "\t q - quit"
      << std::endl
      << "Choose: ";
         std::cin >> cmd;
         std::cout << "cmd: " << cmd << std::endl;
         return cmd;
}
