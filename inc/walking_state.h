#ifndef WALKING_STATE_H
#define WALKING_STATE_H

#include <stdio.h>
#include <iostream>
#include "character_state.h"
#include "character.h"

class WalkingState : public CharacterState
{
public:

  WalkingState();

  void update( Character* character );

  void right();

  void left();

private:
  bool facing_right;
};

#endif
