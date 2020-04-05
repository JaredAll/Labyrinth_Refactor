#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "scene.h"

class GameState
{
public:

  GameState( Scene* scene );

  Scene* get_scene();

  void set_next_state( GameState* next_state );

  void set_previous_state( GameState* previous_state );

  GameState* get_next_state();

  GameState* get_previous_state();

  GameState* handle_boundary();

private:
  
  Scene* scene;

  GameState* next_state;
  GameState* previous_state;

};

#endif
