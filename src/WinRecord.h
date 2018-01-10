#ifndef WINRECORD_H
#define WINRECORD_H

using namespace std;

#include "Game.h"
#include "MetaState.h"

// game results
#define GR_NOT_PLAYED             (1 << 0)
#define GR_BEING_PLAYED           (1 << 1)
#define GR_WON                    (1 << 2)
#define GR_LOST                   (1 << 3)

class Star {
public:
  GLfloat a;
  GLfloat v_a;
  GLfloat size;
  GLfloat v_size;
};

/* static */ class WinRecord {
public:
  static void initialize (   );
  static void timeStep (   );
  static void gameStart (   );
  static void gameWon (   );
  static void gameLoss (   );

  static inline bool isMatchFinished (   )
  {
    if (concession) return true;
    if (MetaState::mode & CM_SOLO) return true;
    if (won) {
      if (games_won == 1 + GC_GAMES_PER_MATCH / 2)
        return true;
    } else
      if (games_lost == 1 + GC_GAMES_PER_MATCH / 2)
        return true;
    return false;
  }

  static inline void matchConceded (   )
  {
    concession = true;
  }

  static int current_game;
  static bool won;
  static bool concession;
  static int games_won;
  static int games_lost;

  static int record[GC_GAMES_PER_MATCH];

  static Star stars[GC_GAMES_PER_MATCH];

  static int dynamic_star;
  static int displaced_star;
  static GLfloat win_star_x;
  static GLfloat win_star_y;
  static GLfloat win_star_v_x;
  static GLfloat win_star_v_y;
  static GLfloat old_star_a;
  static GLfloat old_star_size;

  static bool draw_old_star;
};

#endif
