#ifndef GARBAGEFLAVORIMAGE_H
#define GARBAGEFLAVORIMAGE_H

#include <GL/glut.h>

#ifndef _WIN32
#else
#  include <glext.h>
#endif

using namespace std;

#include "Displayer.h"
#include "Garbage.h"
#include "Random.h"

/* static */ class GarbageFlavorImage {
public:
  static void initialize (   );

  static bool personalGarbageFlavorImageExists (   );
  static GLubyte *loadPersonalGarbageFlavorImage (   );
  static void handleNetworkGarbageFlavorImage ( GLubyte *texture );

  static void buildGarbageTextureFileName ( char file_name[256],
   const char *dir_name, int n );
  static void buildGarbageTextureFileName ( char file_name[256], int n );
  static void buildOriginalGarbageTextureFileName ( char file_name[256],
   int n );

  static void requestGarbageFlavorImage_inline_split_ ( Garbage &garbage );

  static inline void requestGarbageFlavorImage ( Garbage &garbage )
  {
    if (garbage.height < DC_MIN_FLAVOR_GARBAGE_LENGTH) return;
    if (associated_garbage_id != -1) return;
    if (!Random::number(DC_CHANCE_NO_GARBAGE_FLAVOR)) return;

    requestGarbageFlavorImage_inline_split_(garbage);
  }

  static inline void notifyGarbageDestruction ( Garbage &garbage )
  {
    if (garbage.id == associated_garbage_id)
      associated_garbage_id = -1;
  }

  static int current_texture;
  static int associated_garbage_id;
  static int x, y;
  static bool network_texture;
};

#endif
