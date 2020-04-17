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
  return state;
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
