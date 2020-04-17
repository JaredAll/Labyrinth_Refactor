#include "scene.h"

Scene::Scene( Camera* param_camera,
              Character* param_main_character,
              vector< Character* > param_characters,
              int param_left_boundary,
              int param_right_boundary )
  : camera( param_camera ),
    main_character( param_main_character ),
    characters( param_characters ),
    left_boundary( param_left_boundary ),
    right_boundary( param_right_boundary )
{
  state = SceneState::resume;
}

void Scene::update( InputEvent* event )
{
  update_entities( event );
  handle_boundary();
}

void Scene::update_entities( InputEvent* event )
{
  camera -> update( event );
  main_character -> update( event );
  for( Character* character : characters )
  {
    character -> update( event );
  }  
}

void Scene::handle_boundary()
{
  int main_character_position = main_character -> get_x();
  if( main_character_position > right_boundary )
  {
    state = SceneState::exit_right;
  }
  else if( main_character_position < left_boundary )
  {
    state = SceneState::exit_left;
  }
  else
  {
    state = SceneState::resume;
  }
}

SceneState* Scene::get_state()
{
  return &state;
}

void Scene::set_state( SceneState param_state )
{
  state = param_state;
}

void Scene::load_into_game( Game* game )
{
  uint speed = game -> get_speed();
  
  camera -> set_speed( speed );
  main_character -> set_speed( speed );
  for( Character* character : characters )
  {
    character -> set_speed( speed );
  }

  game -> add_component( this );
}

vector< RenderComponent* > Scene::get_render_components()
{
  vector< RenderComponent* > render_components;

  vector< RenderComponent* > camera_render_components = camera -> get_render_components();
  render_components.insert( render_components.end(),
                            camera_render_components.begin(),
                            camera_render_components.end() );
  
  render_components.push_back( main_character -> get_render_components().at( 0 ) );
  for( Character* character : characters )
  {
    render_components.push_back( character -> get_render_components().at( 0 ) );
  }

  return render_components;
}

Camera* Scene::get_camera()
{
  return camera;
}

Character* Scene::get_main_character()
{
  return main_character;
}

vector< Character* > Scene::get_characters()
{
  return characters;
}

int Scene::get_left_boundary()
{
  return left_boundary;
}

int Scene::get_right_boundary()
{
  return right_boundary;
}
