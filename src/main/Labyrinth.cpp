#include "game.h"
#include "game_renderer.h"
#include "doug.h"
#include "sprite.h"
#include <unistd.h>
#include "walking_command.h"

using namespace std;

int main( int argc, char* argv[] )
{

  Game* labyrinth = new Game();
  labyrinth -> initialize();

  Character* doug = labyrinth -> create_character( doug_config );

  vector< GameComponent* > components;
  components.push_back( doug );

  uint milliseconds = 300;

  for( uint i = 0; i < 20; i++ )
  {
    labyrinth -> update( components );
    labyrinth -> render( components );
    usleep( milliseconds * 1000 );
  }
}
