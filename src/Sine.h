#ifndef SINE_H
#define SINE_H

using namespace std;

#include "Game.h"

/* static */ class Sine {
public:
  static void initialize (   );

  static inline float sin ( float x )
  {
    int n = (int) ((x - GC_SINE_TABLE_LOWER_BOUND)
     * (1.0f / GC_SINE_TABLE_STEP_WIDTH));

    if (n < 0) n = 0;
    if (n > GC_SINE_TABLE_LENGTH - 2) n = GC_SINE_TABLE_LENGTH - 2;

    float remainder = x - GC_SINE_TABLE_LOWER_BOUND
     - n * GC_SINE_TABLE_STEP_WIDTH;

    float estimate = table[n] + (table[n + 1] - table[n])
     * remainder * (1.0f / GC_SINE_TABLE_STEP_WIDTH);
                    
    return estimate;
  }

  static float table[GC_SINE_TABLE_LENGTH];
};

#endif
