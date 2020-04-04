#include "scene.h"

Scene::Scene( Camera* param_camera,
              Character* param_main_character,
              vector< Character* > param_characters )
  : camera( param_camera ),
    main_character( param_main_character ),
    characters( param_characters )
{
}

void Scene::update( InputEvent* event )
{
  camera -> update( event );
  main_character -> update( event );
  for( Character* character : characters )
  {
    character -> update( event );
  }
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
