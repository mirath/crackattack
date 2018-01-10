#ifndef GARBAGEGENERATOR_H
#define GARBAGEGENERATOR_H

using namespace std;

#include "Game.h"
#include "MetaState.h"
#include "Communicator.h"
#include "Random.h"

class ComboTabulator;
class CommunicationBuffer;

class GarbageQueueElement {
public:
  bool active;
  int alarm;
  int height;
  int width;
  int flavor;
};

/* static */ class GarbageGenerator {
public:
  static void gameStart (   );

  static void comboElimination ( ComboTabulator &combo );
  static void comboComplete ( ComboTabulator &combo );
  static void timeStep (   );
  static void addToQueue ( CommunicationBuffer &buffer );

private:
  static inline void sendGarbage ( int height, int width, int flavor )
  {
    if (!(MetaState::mode & CM_SOLO))
      Communicator::sendGarbage(height, width, flavor);
    else
      dealLocalGarbage(height, width, flavor, Game::time_step);
  }

  static inline void sendSpecialGarbage ( int flavor )
  {
    if (!(MetaState::mode & CM_SOLO))
      Communicator::sendGarbage(0, 0, flavor);
    else
      dealSpecialLocalGarbage(flavor, Game::time_step);
  }

  static inline int determineDropTime ( int time_stamp )
  {
    return time_stamp
     + (GC_AVERAGE_GARBAGE_DROP_DELAY - GC_SPREAD_GARBAGE_DROP_DELAY / 2)
     + Random::number(GC_SPREAD_GARBAGE_DROP_DELAY);
  }

  static void dealLocalGarbage ( int height, int width, int flavor,
   int time_stamp );
  static void dealSpecialLocalGarbage ( int flavor, int time_stamp );

  static GarbageQueueElement garbage_queue[GC_GARBAGE_QUEUE_SIZE];
  static int waiting_count;
};

#endif
