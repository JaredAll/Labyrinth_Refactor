#include "walking_command.h"

void WalkCommand::execute( Character* character )
{
  uint stride_count = 0;
  character -> set_state( new WalkingState( stride_count ) );
}
