#ifndef CONTORLLER_H
#define CONTORLLER_H

using namespace std;

#define CC_LEFT                     (1 << 0)
#define CC_RIGHT                    (1 << 1)
#define CC_UP                       (1 << 2)
#define CC_DOWN                     (1 << 3)
#define CC_SWAP                     (1 << 4)
#define CC_ADVANCE                  (1 << 5)
#define CC_PAUSE                    (1 << 6)

/* static */ class Controller {
public:
  static void gameStart (   );
  static void keyboardPlay ( unsigned char key, int x, int y );
  static void keyboardUpPlay ( unsigned char key, int x, int y );
  static void specialPlay ( int key, int x, int y );
  static void specialUpPlay ( int key, int x, int y );
  static void keyboardMeta ( unsigned char key, int x, int y );
  static void keyboardUpMeta ( unsigned char key, int x, int y );
  static void specialMeta ( int key, int x, int y );
  static void specialUpMeta ( int key, int x, int y );
  static void entry ( int mouse_state );

  static inline int moveCommand (   )
    { return state & (CC_LEFT | CC_RIGHT | CC_UP | CC_DOWN); }

  static inline bool swapCommand (   )
    { return state & CC_SWAP; }

  static inline bool advanceCommand (   )
    { return state & CC_ADVANCE; }

  static inline bool pauseCommand (   )
    { return state & CC_PAUSE; }

private:
  static int state;
};

#endif
