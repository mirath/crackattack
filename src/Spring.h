#ifndef SPRING_H
#define SPRING_H

using namespace std;

// spring constants, if you will
#define SP_IMPACT_VELOCITY                      (0.1f)
#define SP_GARBAGE_DENSITY                      (0.2f)
#define SP_STIFFNESS                            (0.1f)
#define SP_DRAG                                 (0.1f)

/* static */ class Spring {
public:
  static void gameStart (   );

  static inline void notifyImpact ( int height, int width )
  {
    float dv = (SP_IMPACT_VELOCITY + v) * (height * width) * SP_GARBAGE_DENSITY;
    if (dv > 0.0f)
      v -= dv;
  };

  static inline void timeStep (   )
  {
    y += v;
    v -= SP_STIFFNESS * y + SP_DRAG * v;
  };

  static float y;

private:
  static float v;
};

#endif
