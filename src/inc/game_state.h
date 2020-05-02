#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "scene.h"
#include "scene_state.h"

class GameState
{
public:

  GameState( Scene* scene );

  Scene* get_scene();

  void set_next_state( GameState* next_state );

  void set_previous_state( GameState* previous_state );

  GameState* get_next_state();

  GameState* get_previous_state();

  GameState* update();

private:

  void reset_scene( GameState* state, SceneState& scene_state );

  Scene* scene;

  GameState* next_state;
  GameState* previous_state;

};

#endif
