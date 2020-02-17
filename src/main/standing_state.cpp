#include "standing_state.h"

void StandingState::update( Character* character )
{
  character -> reset_stride();
}

CharacterState* StandingState::right()
{
  WalkingState* walkingState = new WalkingState();
  walkingState -> set_facing_right( true );
  return walkingState;
}

CharacterState* StandingState::left()
{
  WalkingState* walkingState = new WalkingState();
  walkingState -> set_facing_right( false );
  return walkingState;
}

CharacterState* StandingState::no_input()
{
  return new StandingState();
}
