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

void WalkingState::right()
{
  facing_right = true;
}

void WalkingState::left()
{
  facing_right = false;
}
