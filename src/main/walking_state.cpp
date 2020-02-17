#include "walking_state.h"

WalkingState::WalkingState()
{
  facing_right = true;
}

void WalkingState::update( Character* character )
{
  if( facing_right )
  {
    character -> face_right();
  }
  else
  {
    character -> face_left();
  }
  
  character -> update_stride();
}

CharacterState* WalkingState::right()
{
  WalkingState* walkingState = new WalkingState();
  walkingState -> set_facing_right( true );
  return walkingState;
}

CharacterState* WalkingState::left()
{
  WalkingState* walkingState = new WalkingState();
  walkingState -> set_facing_right( false );
  return walkingState;
}

CharacterState* WalkingState::no_input()
{
  return new StandingState();
}

void WalkingState::set_facing_right( bool param_facing_right )
{
  facing_right = param_facing_right;
}
