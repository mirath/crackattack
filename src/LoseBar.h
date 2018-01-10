#ifndef LOSEBAR_H
#define LOSEBAR_H

#include <cassert>

using namespace std;

#define LB_INACTIVE                  (1 << 0)
#define LB_LOW_ALERT                 (1 << 1)
#define LB_HIGH_ALERT                (1 << 2)
#define LB_FADE_LOW_TO_INACTIVE      (1 << 3)
#define LB_FADE_HIGH_TO_INACTIVE     (1 << 4)
#define LB_FADE_RESET_HIGH           (1 << 5)

/* static */ class LoseBar {
public:
  static void initialize (   );
  static void gameStart (   );

  static void timeStep (   );

  static inline void highAlertReset (   )
  /*
   * Called by Creep when the high alert timer is reset.
   */
  {
    assert(state == LB_HIGH_ALERT);

    fade_timer = DC_LOSEBAR_FADE_TIME;
    state = LB_FADE_RESET_HIGH;
  }

  static int state;
  static GLfloat bar;
  static int fade_timer;

private:
  static inline void enterLowToInactiveFade (   )
  {
    fade_timer = DC_LOSEBAR_FADE_TIME;
    state = LB_FADE_LOW_TO_INACTIVE;
  }

  static inline void enterHighToInactiveFade (   )
  {
    fade_timer = DC_LOSEBAR_FADE_TIME;
    state = LB_FADE_HIGH_TO_INACTIVE;
  }
};

#endif
