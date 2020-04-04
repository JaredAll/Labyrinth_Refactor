#include "standing_state.h"

void StandingState::update( Character* character )
{
  character -> reset_stride();
}

CharacterState* StandingState::right()
{
  uint stride_count = 0;
  WalkingState* walkingState = new WalkingState( stride_count );
  walkingState -> set_facing_right( true );
  return walkingState;
}

CharacterState* StandingState::left()
{
  uint stride_count = 0;
  WalkingState* walkingState = new WalkingState( stride_count );
  walkingState -> set_facing_right( false );
  return walkingState;
}

CharacterState* StandingState::r_key()
{
  return new RecruitingState();
}

CharacterState* StandingState::no_input()
{
  return new StandingState();
}
