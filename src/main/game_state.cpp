#include "game_state.h"

GameState::GameState( Scene* param_scene)
  : scene( param_scene )
{
}

GameState* GameState::update()
{
  SceneState scene_state = *( scene -> get_state() );
  GameState* state;
  if( scene_state == SceneState::resume )
  {
    state = this;
  }
  else if( scene_state == SceneState::exit_left )
  {
    state = previous_state;
  }
  else if( scene_state == SceneState::boundary )
  {
    if( this == next_state )
    {
      state = previous_state;
    }
    else
    {
      state = next_state;
    }
  }
  else
  {
    state = next_state;
  }
  reset_scene( state, scene_state );
  return state;
}

void GameState::reset_scene( GameState* state, SceneState& scene_state )
{
  Scene* scene = state -> get_scene();
  if( scene_state == SceneState::exit_left )
  {
    scene -> reset_right();
  }
  else if( scene_state == SceneState::exit_right )
  {
    scene -> reset_left();
  }
}

Scene* GameState::get_scene()
{
  return scene;
}

void GameState::set_next_state( GameState* param_next_state )
{
  next_state = param_next_state;
}

void GameState::set_previous_state( GameState* param_previous_state )
{
  previous_state = param_previous_state;
}

GameState* GameState::get_next_state()
{
  return next_state;
}

GameState* GameState::get_previous_state()
{
  return previous_state;
}
