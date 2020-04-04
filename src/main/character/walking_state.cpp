#include "walking_state.h"

WalkingState::WalkingState( uint stride_count_param )
  : stride_count( stride_count_param )
{
  facing_right = true;
  frames_per_stride = 12;
}

void WalkingState::update( Character* character )
{
  int displacement = character -> get_speed();
  if( facing_right )
  {
    character -> face_right();
  }
  else
  {
    character -> face_left();
    displacement *= -1;
  }

  stride_count++;

  if( stride_count % frames_per_stride == 0 )
  {
    character -> update_stride();
  }
  character -> set_x( character -> get_x() + displacement );
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

CharacterState* WalkingState::r_key()
{
  return new RecruitingState();
}

CharacterState* WalkingState::no_input()
{
  return new StandingState();
}

void WalkingState::set_facing_right( bool param_facing_right )
{
  facing_right = param_facing_right;
}
