#include "following_state.h"

FollowingState::FollowingState( uint stride_count_param, Character* param_leader )
  : stride_count( stride_count_param ),
    leader( param_leader )
{
  facing_right = true;
  frames_per_stride = 12;
  follow_distance = 100;
}

void FollowingState::update( Character* character )
{
  int current_distance = abs( leader -> get_x() - character -> get_x() );

  if( abs( current_distance ) > follow_distance )
  {
    follow( current_distance, character, leader );
  }
  else
  {
    wait( character );
  }
}

void FollowingState::wait( Character* character )
{
  character -> set_panning( true );
  character -> reset_stride();
}

void FollowingState::follow( int current_distance,
                             Character* character,
                             Character* leader )
{
  character -> set_panning( false );
  stride_count++;
  if( stride_count % frames_per_stride == 0 )
  {
    character -> update_stride();
  }

  if( character -> get_x() > leader -> get_x() )
  {
    character -> set_x( character -> get_x() -
                        ( current_distance - follow_distance ) );
    character -> face_left();
  }
  else
  {
    character -> set_x( character -> get_x() +
                        ( current_distance - follow_distance ) );
    character -> face_right();
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

CharacterState* FollowingState::r_key()
{
  return new StandingState();
}

void FollowingState::set_facing_right( bool param_facing_right )
{
  facing_right = param_facing_right;
}
