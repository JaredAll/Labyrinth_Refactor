#include "scenery.h"

Scenery::Scenery( vector< Sprite* > param_sprites )
{
  sprites = param_sprites;
}

void Scenery::update( InputEvent* event )
{
  
}

void Scenery::load_into_game( Game* game )
{
  game -> add_component( this );
}

vector< RenderComponent* > Scenery::get_render_components()
{
  vector< RenderComponent* > renderComponents(
    sprites.begin(), sprites.end() );
  
  return renderComponents;
}
