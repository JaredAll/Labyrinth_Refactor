#include "game.h"
#include "game_renderer.h"
#include "doug.h"
#include "sprite.h"
#include <unistd.h>

using namespace std;

int main( int argc, char* argv[] )
{

  Game* labyrinth = new Game();
  labyrinth -> initialize();

  GameRenderer* renderer = labyrinth -> get_renderer();

  SDL_Texture* sprite_texture =
    renderer -> create_texture( doug.sprite_sheet_resource );

  Sprite* doug_s =
    new Sprite( doug.image_x, doug.image_y,
                sprite_texture );

  doug_s -> set_position(
    doug.image_x, doug.image_y - doug_s -> get_h() );

  vector< RenderComponent* > components;
  components.push_back( doug_s );

  uint milliseconds = 500;

  for( uint i = 0; i < 4; i++ )
  {
    renderer -> render( components );
    usleep( milliseconds * 1000 );
  }
}
