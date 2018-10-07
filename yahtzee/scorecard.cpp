#include <iostream>
#include "scorecard.h"
#include "common.h"

Scorecard::Scorecard()
   : score_(0)
{
   score_ = new Score();

   /*
   std::cout << std::hex << score_->upperScore << std::endl;
   Common::setValue(score_->upperScore, 25, ACES);
   std::cout << std::hex << score_->upperScore << std::endl;
   std::cout << std::dec;
   */
}

Scorecard::~Scorecard()
{
   delete score_;
}

void Scorecard::print()
{
   std::cout << "\n---------- Score --------\n"
             << "Upper Section\n"
             << "Aces:           " << Common::getByteValue(score_->upperScore, ACES) << "\n"
             << "Twos:           " << Common::getByteValue(score_->upperScore, TWOS) << "\n"
             << "Threes:         " << Common::getByteValue(score_->upperScore, THREES) << "\n"
             << "Fours:          " << Common::getByteValue(score_->upperScore, FOURS) << "\n"
             << "Fives:          " << Common::getByteValue(score_->upperScore, FIVES) << "\n"
             << "Sixes:          " << Common::getByteValue(score_->upperScore, SIXES) << "\n"
             << "Bonus (>63):    " << Common::getByteValue(score_->upperScore, UPPER_BONUS) << "\n"
             << "Total Upper:    " << "0\n"
             << "\nLower Section\n"
             << "3 of a Kind:    " << Common::getByteValue(score_->lowerScore, THREE_OF_A_KIND) << "\n"
             << "4 of a Kind:    " << Common::getByteValue(score_->lowerScore, FOUR_OF_A_KIND) << "\n"
             << "Small Straight: " << Common::getByteValue(score_->lowerScore, SMALL_STRAIGHT) << "\n"
             << "Large Straight: " << Common::getByteValue(score_->lowerScore, LARGE_STRAIGHT) << "\n"
             << "Full House:     " << Common::getByteValue(score_->lowerScore, FULL_HOUSE) << "\n"
             << "Chance:         " << Common::getByteValue(score_->lowerScore, CHANCE) << "\n"
             << "Yahtzee:        " << Common::getByteValue(score_->lowerScore, YAHTZEE) << "\n"
             << "Yahtzee bonus:  " << Common::getByteValue(score_->lowerScore, YAHTZEE_BONUS) << "\n"
             << "Total Lower:    " << "0\n\n"
             << "Grand Total:    " << "0\n"
             << std::endl;
}
