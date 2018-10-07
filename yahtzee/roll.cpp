#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <ctype.h>
#include "roll.h"

Roll::Roll()
   : dice_(0)
{
   srand (time(NULL));
}

Roll::~Roll()
{
}

UINT64 Roll::handleTurn()
{
   Common::setByteValue(dice_, nextDieRoll(), 0);
   Common::setByteValue(dice_, 0, 0);   
   Common::setByteValue(dice_, nextDieRoll(), 0);
/*   Common::setByteValue(dice_, nextDieRoll(), 1);
   Common::setByteValue(dice_, nextDieRoll(), 2);
   Common::setByteValue(dice_, nextDieRoll(), 3);
   Common::setByteValue(dice_, nextDieRoll(), 4);
*/

   printDice();
   
   char dieDiscard[6];
   memset(dieDiscard, '\0', sizeof(dieDiscard));
   for (int i=0; i<3; i++)
   {
      std::cout << "Dice to discard, others will be kept: ";
      std::cin >> dieDiscard;
      std::cout << "discarding: " << dieDiscard << std::endl;
      reRoll(dieDiscard);
      printDice();
   }

   return dice_;
}

void Roll::printDice()
{
   for (int i=0; i<5; i++)
      std::cout << "Dice#" << i+1 << ": " << Common::getByteValue(dice_, i) << std::endl;
   std::cout << std::endl;
}

void Roll::reRoll(char *roll)
{
   for (int i=0; i<strlen(roll); i++)
   {
      std::cout << "dice#" << (int)roll[i]-48 << std::endl;
      Common::resetByteValue(dice_, (int)roll[i]-49);
      Common::setByteValue(dice_, nextDieRoll(), (int)roll[i]-49);
   }
}

short Roll::nextDieRoll()
{
   return rand() % 6 + 1;
}
