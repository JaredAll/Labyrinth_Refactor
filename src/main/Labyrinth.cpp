#include "following_state.h"
#include "game.h"
#include "game_renderer.h"
#include "sprite.h"
#include "input_event.h"
#include "camera.h"
#include "origin.h"
#include "text_box.h"
#include "game_state.h"

using namespace std;

int main( int argc, char* argv[] )
{
  Game* labyrinth = new Game();
  labyrinth -> initialize();
  
  Scene* origin = labyrinth -> create_scene( origin_config );
  GameState* origin_state = new GameState( origin );
  
  origin_state -> set_next_state( origin_state );
  origin_state -> set_previous_state( origin_state );
  
  labyrinth -> set_state( origin_state );
  labyrinth -> play();
}
