#include "walking_state.h"

WalkingState::WalkingState( uint stride_count_param )
  : stride_count( stride_count_param )
{
  facing_right = true;
  frames_per_stride = 12;
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

  stride_count++;

  if( stride_count % frames_per_stride == 0 )
  {
    character -> update_stride(); 
  }
}

CharacterState* WalkingState::right()
{
  WalkingState* walkingState = new WalkingState( stride_count );
  walkingState -> set_facing_right( true );
  return walkingState;
}

CharacterState* WalkingState::left()
{
  WalkingState* walkingState = new WalkingState( stride_count );
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
