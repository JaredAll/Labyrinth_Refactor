#ifndef WALK_COMMAND_H
#define WALK_COMMAND_H

#include "character.h"
#include "walking_state.h"

class WalkCommand
{
public:
  void execute( Character* character );
};

#endif
