#ifndef TEXTURELOADER_H
#define TEXTURELOADER_H

#include <GL/glut.h>

#ifndef _WIN32
#  include <sstream>
#else
#  include <glext.h>
#  include <strstrea.h>
#endif

using namespace std;

#define TL_GARBAGE_TEXTURE_TGA_ID     "Crack Attack! garbage texture"
#define TL_SCREEN_SHOT_TGA_ID         "Crack Attack! screen shot"

/* static */ class TextureLoader {
public:
  static GLubyte *loadAlphaTGA ( const char *tga_file_name, int _height,
   int _width );
  static GLubyte *loadNoAlphaTGA ( const char *tga_file_name, int _height,
   int _width );
  static GLubyte *loadTGA ( const char *tga_file_name, int _height, int _width,
   int _color_depth = 32 );
  static void createTGA ( const char *tga_file_name, GLubyte *texture,
   int _height, int _width, const char *tga_id );
  static bool fileExists ( const char *file_name );
  static unsigned long determineTGACheckSum ( const char *tga_file_name,
   int _height, int _width );
  static void determineTGASize ( const char *tga_file_name, int &height,
   int &width );

  static inline void buildLocalDataDirectoryName ( char dir_name[256] )
  {
    ostringstream s;
#ifndef _WIN32
    s << getenv("HOME") << GC_LOCAL_DATA_DIRECTORY << ends;
#else
    s << GC_LOCAL_DATA_DIRECTORY << ends;
#endif
    strncpy(dir_name, s.str().data(), 256);
  }

  static inline void buildLocalDataFileName ( const char base_name[256],
   char file_name[256] )
  {
    ostringstream s;
#ifndef _WIN32
    s << getenv("HOME") << GC_LOCAL_DATA_DIRECTORY << base_name << ends;
#else
    s << GC_LOCAL_DATA_DIRECTORY << base_name << ends;
#endif
    strncpy(file_name, s.str().data(), 256);
  }
};

#endif
