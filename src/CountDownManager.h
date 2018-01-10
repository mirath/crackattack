#ifndef COUNTDOWNMANAGER_H
#define COUNTDOWNMANAGER_H

using namespace std;

/* static */ class CountDownManager {
public:
  static void gameStart (   );
  static void cleanUp (   );

  static inline void timeStep (   )
  {
    if (state == -1) return;
    timeStep_inline_split_();
  }

  static int state;
  static int start_pause_alarm;
  static int message_switch_alarm;

private:
  static void timeStep_inline_split_ (   );
};

#endif
