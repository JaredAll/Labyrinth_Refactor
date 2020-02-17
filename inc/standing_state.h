#ifndef STANDING_STATE_H
#define STANDING_STATE_H

#include <stdio.h>
#include <iostream>
#include "character_state.h"
#include "character.h"

class StandingState : public CharacterState
{
public:
  
  void update( Character* character );
  
  CharacterState* right();
  
  CharacterState* left();

  CharacterState* no_input();
};

#endif
