#ifndef GARBAGE_H
#define GARBAGE_H

#include <GL/glut.h>

#ifndef _WIN32
#else
#  include <glext.h>
#endif

using namespace std;

// flavor of garbage
#define GF_NORMAL                      (0)
#define GF_GRAY                        (1) // hard to destroy
#define GF_BLACK                       (2) // very hard to destroy
#define GF_WHITE                       (3) // crazy lights
#define GF_COLOR_1                     (4) // sprinkling of 1x1's
#define GF_COLOR_2                     (5) // shatters to normal garbage
#define GF_COLOR_3                     (6) // invisible swapper
#define GF_COLOR_4                     (7) // reverse controls
#define GF_COLOR_5                     (8) // tall garbage
#define GF_NUMBER                      (9)

// flavor effects
#define GF_SHATTER_TO_NORMAL_GARBAGE   (GF_COLOR_2)
#define GF_REVERSE_CONTROLS            (GF_COLOR_4)
#define GF_INVISIBLE_SWAPPER           (GF_COLOR_3)
#define GF_CRAZY_LIGHTS                (GF_WHITE)

// states of garbage
#define GS_STATIC              (1 << 0)
#define GS_FALLING             (1 << 1)
#define GS_AWAKING             (1 << 2)
#define GS_SHATTERING          (1 << 3)

class ComboTabulator;

class Garbage {
public:
  void initializeStatic ( int _x, int _y, int _height, int _width,
   int _flavor );
  void initializeFalling ( int _x, int _y, int _height, int _width,
   int _flavor );
  void initializeAwaking ( int _x, int _y, int _height, int pop_delay,
   int awake_delay, ComboTabulator *combo, int _pop_color );
  void timeStep ( int &l_x, int &l_y );
  void startFalling ( ComboTabulator *combo = null, bool no_hang = false,
   bool self_call = false );
  void startShattering ( int &s_x, int s_y, int &pop_delay, int awake_delay,
   ComboTabulator *combo );

  bool considerShattering ( Garbage *due_to )
  /*  
   * The grid is asking us if we should shatter due to the fact that our
   * neighbor - due_to - is shattering.  If due_to is null, we are shattering
   * because of a neighboring elimination.  Parts of the black garbage
   * algorithm are handled in Grid.cxx
   */ 
  {
    if (!due_to) return true;
    if (flavor == GF_GRAY)
      if (due_to->flavor == GF_GRAY)
        return true;
      else
        return false;
    if (flavor == GF_BLACK)
      if (due_to->flavor == GF_BLACK)
        return true;
      else
        return false;
    if (due_to->flavor == GF_GRAY)
      return false;
    else
      return true;
  }

  // free store id
  int id;

  // block type
  int flavor;

  // grid position
  int x, y;

  // garbage dimensions
  int height, width;

  // find position control; GC_STEPS_PER_GRID number of increments per grid
  int f_y;

  // garbage state
  int state;

  // time until awakening
  int alarm;

  // number of sections popped in awaking garbage
  int sections_popped;

  // true if we're in an initial fall
  bool initial_fall;

  // next direction of rotation upon popping
  int pop_direction;

  // time until pop
  int pop_alarm;

  // the block color before popping
  int pop_color;

private:
  // combo to pass on upon awakening
  ComboTabulator *awaking_combo;
};

#endif
