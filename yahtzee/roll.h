#ifndef __ROLL_H__
#define __ROLL_H__

#include "common.h"

class Roll
{
public:
   Roll();
   ~Roll();
   UINT64 handleTurn();

private:
   void printDice();
   void reRoll(char* roll);
   short nextDieRoll();

   UINT64 dice_;
};

#endif
