#ifndef RECRUITING_STATE_H
#define RECRUITING_STATE_H

#include <stdio.h>
#include <iostream>
#include "character_state.h"
#include "character.h"

class RecruitingState : public CharacterState
{
public:

  void update( Character* character );

  CharacterState* right();

  CharacterState* left();

  CharacterState* r_key();

  CharacterState* no_input();
  
};

#endif
