#ifndef CLOCK_H
#define CLOCK_H

using namespace std;

#include "Game.h"

/* static */ class Clock {
public:
  static void gameStart (   );

  static inline void timeStepPlay (   )
  {
    if (++tick != GC_STEPS_PER_SECOND) return;
    tick = 0;
    previous_digits[0] = digits[0];
    previous_digits[1] = digits[1];
    previous_digits[2] = digits[2];
    previous_digits[3] = digits[3];
    if (++digits[0] == 10) {
      digits[0] = 0;
      if (++digits[1] == 6) {
        digits[1] = 0;
        if (++digits[2] == 10) {
          digits[2] = 0;
          if (++digits[3] == 6)
            digits[3] = 0;
        }
      }
    }
  }

  static inline void timeStepMeta (   )
  /*
   * Ensures competion of the final tick fade after game end.
   */
  {
    if (tick == -1) return;
    if (++tick != GC_STEPS_PER_SECOND) return;
    tick = -1;
    previous_digits[0] = digits[0];
    previous_digits[1] = digits[1];
    previous_digits[2] = digits[2];
    previous_digits[3] = digits[3];
  }

  static short digits[4];
  static short previous_digits[4];
  static int tick;
};

#endif
