#include "game_state.h"

GameState::GameState( Scene* param_scene)
  : scene( param_scene )
{
}

GameState* GameState::handle_boundary()
{
  return this;
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
