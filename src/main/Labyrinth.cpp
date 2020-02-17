#include "game.h"
#include "game_renderer.h"
#include "doug.h"
#include "sprite.h"
#include <unistd.h>
#include "input_event.h"

using namespace std;

int main( int argc, char* argv[] )
{

  Game* labyrinth = new Game();
  labyrinth -> initialize();

  Character* doug =
    labyrinth -> create_main_character( doug_config );

  vector< GameComponent* > components;
  components.push_back( doug );

  labyrinth -> set_components( components );

  uint milliseconds = 300;

  for( uint i = 0; i < 20; i++ )
  {
    InputEvent* event = labyrinth -> handle_input();
    labyrinth -> update( event );
    labyrinth -> render();
    free( event );
    usleep( milliseconds * 1000 );
  }
}
