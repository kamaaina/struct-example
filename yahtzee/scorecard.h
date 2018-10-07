#ifndef __SCORECARD_H__
#define __SCORECARD_H__

#include "common.h"

#define ACES 0
#define TWOS 1
#define THREES 2
#define FOURS 3
#define FIVES 4
#define SIXES 5
#define UPPER_BONUS 6

#define THREE_OF_A_KIND 0
#define FOUR_OF_A_KIND 1
#define SMALL_STRAIGHT 2
#define LARGE_STRAIGHT 3
#define FULL_HOUSE 4
#define CHANCE 5
#define YAHTZEE 6
#define YAHTZEE_BONUS 7

// 0 ----------- 15 ------------ 31 ------------ 48 ------------ 64
// | Aces | Twos | Threes| Fours | Fives | Sixes | Bonus  | xxxx |   // UpperScore
// |3Kind | 4Kind| Sm S. | Lg S. | House | Chance| Yahtzee|Ybonus|   // LowerScore
typedef struct {
   UINT64 upperScore;
   UINT64 lowerScore;
} Score;

class Scorecard
{
public:
   Scorecard();
   ~Scorecard();
   void print();

private:
   Score *score_;
};

#endif
