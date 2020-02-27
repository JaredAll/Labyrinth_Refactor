#include "scenery.h"

Scenery::Scenery( Sprite* param_sprite )
{
  sprite = param_sprite;
  setRenderComponent( sprite );
}

void Scenery::update( InputEvent* event )
{
  
}

void Scenery::load_into_game( Game* game )
{
  game -> add_component( this );
}
