#ifndef STRING_H
#define STRING_H

using namespace std;

#include "Displayer.h"

/* static */ class String {
public:
  static int mapCharToCode ( char c );
  static int stringWidth ( const char *string, int max_width );
  static void readyLetterTextures (   );
  static void freeLetterTextures (   );
  static void fillStringTexture ( const char *string, GLubyte *texture,
   int width, bool use_alpha = false, int texture_width = 0 );
  
private:
  static const char *letter_texture_files[DC_FONT_NUMBER][DC_LETTER_NUMBER];
  static const char letter_mapping[DC_LETTER_NUMBER];
  static const int letter_widths[DC_FONT_NUMBER][DC_LETTER_NUMBER];
  static const float colors[DC_FONT_COLOR_NUMBER][3];
  static GLubyte *letter_textures[DC_FONT_NUMBER][DC_LETTER_NUMBER];
};

#endif
