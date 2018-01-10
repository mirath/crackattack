#ifndef LIGHTMANAGER_H
#define LIGHTMANAGER_H

#include <GL/glut.h>
#include <cassert>

#ifndef _WIN32
#else
#  include <glext.h>
#endif

using namespace std;

#include "Displayer.h"
#include "SparkleManager.h"
#include "CountDownManager.h"
#include "X.h"

#define LL_BELOW                     (1 << 0)
#define LL_ABOVE                     (1 << 1)
#define LL_LEFT                      (1 << 2)
#define LL_RIGHT                     (1 << 3)

class Light {
public:
  int association;
  GLfloat location[4];
  GLfloat brightness[4];
  bool enabled;
  bool to_be_enabled;
  bool attenuated;
};

/* static */ class LightManager {
public:
  static void initialize (   );
  static void setupBlockLights ( float x, float y );
  static void setupGarbageLights ( float x, float y, int h, int w );

  static inline void setupHeadLightPlay (   )
  {
    if (!(Game::state & GS_SYNC_WAIT) && CountDownManager::state == -1
     && !X::crazyLights())
      return;
    setupHeadLightPlay_inline_split_();
  }

  static void setupHeadLightMeta (   );

  static inline void resetHeadLight (   )
  {
    if (headlight_normal) return;
    resetHeadLight_inline_split_();
  }

  static inline void timeStepInitialize (   )
  {
    for (int n = DC_NUMBER_EXTRA_LIGHTS; n--; ) {
      if (lights[n].enabled) {
        glDisable((GLenum) (DC_EXTRA_LIGHT_BASE + n));
        lights[n].enabled = false;
      }
      lights[n].association = -1;
      if (lights[n].attenuated)
        unattenuateLight(lights[n], n);
    }

    last_associated = 0;
  }

private:
  static void setupHeadLightPlay_inline_split_ (   );
  static void resetHeadLight_inline_split_ (   );

  static inline void associateLight ( Light &light, int a, Mote &mote, int m )
  {
    light.association = m;
    mote.associated_light = a;

    light.location[0] = mote.x;
    light.location[1] = mote.y;
    glLightfv((GLenum) (DC_EXTRA_LIGHT_BASE + a), GL_POSITION, light.location);
  }

  static inline void configureBlockBrightness ( Light &light, int a, Mote &mote,
   float r )
  {
    assert(a >= 0);
    assert(a < DC_NUMBER_EXTRA_LIGHTS);

    float brightness = (DC_MOTE_LIGHT_RANGE * DC_MOTE_LIGHT_RANGE - r)
     * (1.0f / (DC_MOTE_LIGHT_RANGE * DC_MOTE_LIGHT_RANGE))
     * mote.brightness;

    if (mote.light_color == 0) {
      light.brightness[0] = brightness;
      light.brightness[1] = brightness;
      light.brightness[2] = brightness;

    } else {
      light.brightness[0] = brightness
       * Displayer::mote_light_colors[mote.light_color][0];
      light.brightness[1] = brightness
       * Displayer::mote_light_colors[mote.light_color][1];
      light.brightness[2] = brightness
       * Displayer::mote_light_colors[mote.light_color][2];
    }

    glLightfv((GLenum) (DC_EXTRA_LIGHT_BASE + a), GL_DIFFUSE,
     light.brightness);
    glLightfv((GLenum) (DC_EXTRA_LIGHT_BASE + a), GL_SPECULAR,
     light.brightness);
  }

  static inline void configureGarbageBrightness ( Light &light, int a,
   Mote &mote, float r)
  {
    assert(a >= 0);
    assert(a < DC_NUMBER_EXTRA_LIGHTS);

    float brightness;
    if (r > 0.0f)
      brightness = (DC_MOTE_LIGHT_RANGE * DC_MOTE_LIGHT_RANGE - r)
       * (1.0f / (DC_MOTE_LIGHT_RANGE * DC_MOTE_LIGHT_RANGE)) * mote.brightness;
    else
      brightness = mote.brightness;

    if (mote.light_color == 0) {
      light.brightness[0] = brightness;
      light.brightness[1] = brightness;
      light.brightness[2] = brightness;

    } else {
      light.brightness[0] = brightness
       * Displayer::mote_light_colors[mote.light_color][0];
      light.brightness[1] = brightness
       * Displayer::mote_light_colors[mote.light_color][1];
      light.brightness[2] = brightness
       * Displayer::mote_light_colors[mote.light_color][2];
    }

    glLightfv((GLenum) (DC_EXTRA_LIGHT_BASE + a), GL_DIFFUSE,
     light.brightness);
    glLightfv((GLenum) (DC_EXTRA_LIGHT_BASE + a), GL_SPECULAR,
     light.brightness);
  }

  static inline void attenuateLight ( Light &light, int a )
  {
    glLightf((GLenum) (DC_EXTRA_LIGHT_BASE + a), GL_QUADRATIC_ATTENUATION,
     DC_MOTE_LIGHT_ATTENUATION);
    light.attenuated = true;
  }

  static inline void unattenuateLight ( Light &light, int a )
  {
    glLightf((GLenum) (DC_EXTRA_LIGHT_BASE + a), GL_QUADRATIC_ATTENUATION,
     0.0f);
    light.attenuated = false;
  }

  static Light lights[DC_NUMBER_EXTRA_LIGHTS];
  static int last_associated;
  static bool headlight_normal;
};

#endif
