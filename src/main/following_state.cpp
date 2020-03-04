#include "following_state.h"

FollowingState::FollowingState( uint stride_count_param )
  : stride_count( stride_count_param )
{
  facing_right = true;
  frames_per_stride = 12;
}

void FollowingState::update( Character* character )
{
  Character* leader = character -> get_leader();
  uint follow_distance = 100;

  if( abs( leader -> get_x() - character -> get_x() ) >
      follow_distance )
  {
    stride_count++;
    if( stride_count % frames_per_stride == 0 )
    {
      character -> update_stride();
    }
  }
}

CharacterState* FollowingState::right()
{
  return new StandingState();
}

CharacterState* FollowingState::left()
{
  return new StandingState();  
}

CharacterState* FollowingState::no_input()
{
  return new StandingState();  
}

void FollowingState::set_facing_right( bool param_facing_right )
{
  facing_right = param_facing_right;
}
