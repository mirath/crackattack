#ifndef SCORERECORDMANAGER_H
#define SCORERECORDMANAGER_H

#include <GL/glut.h>

#ifndef _WIN32
#else
#  include <glext.h>
#endif

using namespace std;

#include "WinRecord.h"
#include "Displayer.h"
#include "Score.h"

/* static */ class ScoreRecordManager {
public:
  static void initialize (   );
  static void gameFinish_inline_split_ (   );
  static void timeStep_inline_split_ (   );

  static inline void gameStart (   )
  {
    if (!(MetaState::mode & CM_SOLO)) return;

    glDeleteTextures(1, &Displayer::score_to_beat_texture);
  }

  static inline void gameFinish (   )
  {
    if (!(MetaState::mode & CM_SOLO)) return;
    if (!WinRecord::won) return;

    gameFinish_inline_split_();
  }

  static inline void ScoreRecordManager::timeStep (   )
  {
    if (!(MetaState::mode & CM_SOLO)) return;
    if (!WinRecord::won) return;
    if (Game::time_step < DC_WIN_FADE_TIME) return;

    timeStep_inline_split_();
  }

  static inline GLubyte *ScoreRecordManager::chooseTexture ( int rank )
  {
    if (rank > Score::player_rank)
      return Displayer::record_texture_data[rank - 1];
    if (rank < Score::player_rank)
      return Displayer::record_texture_data[rank];
    return Displayer::player_rank_texture_data;
  }

  static int top_rank;
  static int top_texture;
  static GLfloat offset;
  static GLfloat velocity;

  static bool spring_active;
  static bool control_active;
  static bool ignore_up;
  static bool ignore_down;
};

#endif
