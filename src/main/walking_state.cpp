#include "walking_state.h"

void WalkingState::update( Character* character )
{
  character -> update_stride();
}
