#ifndef FOLLOWING_STATE_H
#define FOLLOWING_STATE_H

#include <stdio.h>
#include <iostream>
#include "character_state.h"
#include "character.h"
#include "standing_state.h"

class FollowingState : public CharacterState
{
public:

  FollowingState( uint stride_count );

  void update( Character* character );

  CharacterState* right();

  CharacterState* left();

  CharacterState* no_input();

  void set_facing_right( bool facing_right );

private:

  bool facing_right;

  uint frames_per_stride;
  uint stride_count;
};

#endif
