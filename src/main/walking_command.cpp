#include "walking_command.h"

void WalkCommand::execute( Character* character )
{
  character -> set_state( new WalkingState() );
}
