#ifndef MESSAGEMANAGER_H
#define MESSAGEMANAGER_H

using namespace std;

#include "Displayer.h"

// message shapes
#define MS_1x1                  (1 << 0)
#define MS_2x1                  (1 << 1)
#define MS_4x1                  (1 << 2)

// messages
#define MS_COUNT_DOWN_GO        (0)
#define MS_COUNT_DOWN_1         (1)
#define MS_COUNT_DOWN_2         (2)
#define MS_COUNT_DOWN_3         (3)
#define MS_ANYKEY               (4)
#define MS_WAITING              (5)
#define MS_PAUSED               (6)
#define MS_WINNER               (7)
#define MS_LOSER                (8)
#define MS_GAME_OVER            (9)

// message modes
#define MM_NORMAL               (1 << 0)
#define MM_CELEBRATION          (1 << 1)

/* static */ class MessageManager {
public:
  static inline void readyMessage ( int message )
  {
    Displayer::readyMessage(message);
    message_shape = Displayer::message_shape[message];
    time_step = 0;
  }

  static inline void nextMessage ( int message )
  {
    Displayer::nextMessage(message);
    message_shape = Displayer::message_shape[message];
    time_step = 0;
  }

  static inline void freeMessage (   )
  {
    Displayer::freeMessage();
    message_shape = 0;
  }

  static inline void timeStep (   )
  {
    if (!message_shape) return;
    if (++time_step == DC_MESSAGE_PULSE_PERIOD)
      time_step = 0;
  }

  static int message_shape;
  static int time_step;
  static int mode;
};

#endif
