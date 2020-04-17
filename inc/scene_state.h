#ifndef SCENE_STATE_H
#define SCENE_STATE_H

#include <iostream>
#include <stdlib.h>

enum SceneState
{
  exit_right = 0,
  exit_left = 1,
  quit = 2,
  switch_tracks = 3,
  resume = 4,
  boundary = 5
};

std::ostream& operator<<( std::ostream& output_stream, SceneState& state );

#endif
