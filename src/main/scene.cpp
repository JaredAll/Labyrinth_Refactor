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
  camera -> load_into_game( game );
  main_character -> load_into_game( game );
  for( Character* character : characters )
  {
    character -> load_into_game( game );
  }
}
