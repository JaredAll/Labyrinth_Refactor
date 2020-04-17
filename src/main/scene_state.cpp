#include "scene_state.h"

using namespace std;

ostream& operator<<( ostream& output_stream, SceneState& state )
{
  switch( state )
  {
  case exit_right:
    output_stream << "exit_right" << endl;
    break;
  case exit_left:
    output_stream << "exit_left" << endl;
    break;
  case quit:
    output_stream << "quit" << endl;
    break;
  case switch_tracks:
    output_stream << "switch_tracks" << endl;
    break;
  case resume:
    output_stream << "resume" << endl;
    break;
  case boundary:
    output_stream << "boundary" << endl;
    break;
  }
  return output_stream;
}
