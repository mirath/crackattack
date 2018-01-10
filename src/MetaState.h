#ifndef METASTATE_H
#define METASTATE_H

using namespace std;

#include "Game.h"

// program states
#define MS_BOTH_KEY_WAIT                   (1 << 0)
#define MS_REMOTE_KEY_WAIT                 (1 << 1)
#define MS_LOCAL_KEY_WAIT                  (1 << 2)
#define MS_GAME_OVER_KEY_WAIT              (1 << 3)
#define MS_READY_GAME_START                (1 << 4)
#define MS_CELEBRATION_WAIT                (1 << 5)
#define MS_GAME_PLAY                       (1 << 6)
#define MS_CONCESSION                      (1 << 7)

/* static */ class MetaState {
public:
  static void programStart ( int _mode,
   char player_name[GC_PLAYER_NAME_LENGTH] );
  static void programEnd (   );
  static void gameStart (   );
  static void gameWon (   );
  static void gameLoss (   );
  static void gameFinish (   );

  static void celebrationComplete (   );

  static void localKeyPressed ( bool esc );
  static void remoteKeyPressed (   );
  static void remoteReady (   );

  // set to Game::time_step upon game finish
  static int final_time_step;

  // current game state - playing, local key wait, ...
  static int state;

  // global game mode - server, client, solo, ...
  static int mode;

  // player name
  static char player_name[GC_PLAYER_NAME_LENGTH];
};

#endif
