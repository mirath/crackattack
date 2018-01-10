#ifndef ATTACK_H
#define ATTACK_H

#include "Game.h"

using namespace std;

void usage (   );
void parseCommandLine ( int argc, char **argv, int &mode, int &port,
 char *host_name, char player_name[GC_PLAYER_NAME_LENGTH] );
void setupLocalDataDirectory (   );

#endif
