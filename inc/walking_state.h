#ifndef WALKING_STATE_H
#define WALKING_STATE_H

#include <stdio.h>
#include <iostream>
#include "character_state.h"
#include "character.h"

class WalkingState : public CharacterState
{
public:
  void update( Character* character );
};

#endif
