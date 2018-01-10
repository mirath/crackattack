#ifndef CELEBRATIONMANAGER_H
#define CELEBRATIONMANAGER_H

#include <GL/glut.h>

#ifndef _WIN32
#else
#  include <glext.h>
#endif

using namespace std;

#include "Displayer.h"

/* static */ class CelebrationManager {
public:
  static inline void initialize (   )
  {
    draw_game = false;
    light_level = 1.0f;
  }

  static void gameFinish (   );
  static void celebrationFinish (   );

  static void timeStep (   );

  static bool draw_game;
  static GLfloat light_level;

  // celebration display variables

  static int spark_rate[DC_CSPARK_SOURCE_NUMBER];
  static int spark_color[DC_CSPARK_SOURCE_NUMBER];

  static float win_alpha;
  static float win_scale;
  static int win_flash1;
  static int win_flash2;

  static float loss_height;
  static float loss_velocity;
  static bool loss_rescale;
  static int loss_bounce_count;
};

#endif
