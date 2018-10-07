#include <iostream>
#include "command.h"
#include "roll.h"
#include "scorecard.h"

using namespace std;

int main(int argc, char* argv[])
{
   Command *command = new Command();
   Scorecard *scorecard = new Scorecard();
   Roll *roll = new Roll();

   volatile bool done = false;
   while (!done)
   {
      char cmd = command->getCommand();
      switch (cmd)
      {
      case 'r':
         roll->handleTurn();
         break;
      case 'p':
         scorecard->print();
         break;
      case 'q':
         done = true;
         break;
      default:
         cout << "Invalid command!" << endl;
         break;
      }
   }
   
   delete command;
   delete scorecard;
   delete roll;
   
   return 0;
}
