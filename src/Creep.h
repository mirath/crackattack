#ifndef CREAP_H
#define CREAP_H

using namespace std;

/* static */ class Creep {
public:
  static void gameStart (   );
  static void timeStep (   );

  static int creep;
  static int loss_alarm;
  static bool creep_freeze;

private:
  static int creep_timer_step;
  static int creep_timer;
  static int increase_velocity_alarm;
  static bool advance;
};

#endif
