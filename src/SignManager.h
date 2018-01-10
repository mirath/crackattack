#ifndef SIGNMANAGER_H
#define SIGNMANAGER_H

using namespace std;

#include "Displayer.h"

// sign types
#define ST_MAGNITUDE                      (0)
#define ST_MULTIPLIER                     (1)
#define ST_SPECIAL                        (2)

// sign textures
#define ST_SMALL_TEXTURE                  (0)
#define ST_LARGE_TEXTURE                  (1)

// content bases
#define SC_BASE_MAGNITUDE_CONTENT         (0)
#define SC_BASE_MULTIPLIER_CONTENT        (13)

class Sign {
public:
  bool active;
  float x, y;
  int texture;
  GLfloat subtexture_s;
  GLfloat subtexture_t;
  GLfloat size;
  int life_time;
  int g_x, g_y;
  int color;
};

/* static */ class SignManager {
public:
  static void initialize (   );

  static inline void timeStep (   )
  {
    if (sign_count > 0) timeStep_inline_split_();
  }

  static void createSign ( int x, int y, int type, int level );

  static int sign_count;
  static Sign signs[DC_MAX_SIGN_NUMBER];

private:
  static void timeStep_inline_split_ (   );

  static inline bool confirmSignLocation ( Sign &sign )
  {
    if (sign.g_y <= 0) return false;
    if (sign.g_x <= 0 || sign.g_x >= GC_PLAY_WIDTH) return false;

    // sign being created is still inactive
    int c = sign_count;
    for (int n = 0; c; n++)
      if (signs[n].active) {
        c--;
        if (sign.g_x == signs[n].g_x && sign.g_y == signs[n].g_y) return false;
      }

    return true;
  }
};

#endif
