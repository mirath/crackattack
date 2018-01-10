#ifndef COMBOTABULATOR_H
#define COMBOTABULATOR_H

using namespace std;

#include "Game.h"

class Block;

class ComboTabulator {
public:
  void initialize (   );

  void reportElimination ( int _magnitude, Block &kernel );

  inline void incrementInvolvement (   )
    { ++involvement_count; }
  inline void decrementInvolvement (   )
    { --involvement_count; }

  // free store id
  int id;

  // latest elimination time stamp
  int time_stamp;

  // creation time stamp
  int creation_time_stamp;

  // number of blocks involved in combo
  int involvement_count;

  // normal elimination magnitude
  int magnitude;

  // special elimination magnitude
  int special_magnitude;

  // combo multiplier
  int multiplier;

  // number of multipliers this time step
  int n_multipliers_this_step;

  // base score earned so far on this multiplier
  int base_accumulated_score;

  // base score earned so far on this turn
  int base_score_this_step;

  // used by blocks the step after elimination to determine spark number
  int latest_magnitude;

  // keep track of the location of the eliminations
  int x, y;

  // keeps track of the various special blocks which have been eliminated
  int special[BF_NUMBER_SPECIAL];
};

#endif
