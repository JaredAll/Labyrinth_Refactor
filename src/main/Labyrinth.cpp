#include "following_state.h"
#include "game.h"
#include "game_renderer.h"
#include "sprite.h"
#include "input_event.h"
#include "camera.h"
#include "origin.h"
#include "origin_clone.h"
#include "text_box.h"
#include "game_state.h"
#include "boundary_scene.h"

using namespace std;

int main( int argc, char* argv[] )
{
  Game* labyrinth = new Game();
  labyrinth -> initialize();
  
  Scene* origin = labyrinth -> create_scene( origin_config );
  Scene* origin_end = new BoundaryScene( origin, true );
  GameState* origin_state = new GameState( origin );
  GameState* origin_end_state = new GameState( origin_end );

  Scene* origin_clone = labyrinth -> create_scene( origin_clone_config );
  Scene* origin_clone_end = new BoundaryScene( origin_clone, false );
  GameState* origin_clone_state = new GameState( origin_clone );
  GameState* origin_clone_end_state = new GameState( origin_clone_end );
  
  
  origin_state -> set_next_state( origin_clone_state );
  origin_state -> set_previous_state( origin_end_state );

  origin_end_state -> set_next_state( origin_state );
  origin_end_state -> set_previous_state( origin_end_state );

  origin_clone_state -> set_next_state( origin_clone_end_state );
  origin_clone_state -> set_previous_state( origin_state );

  origin_clone_end_state -> set_previous_state( origin_clone_state );
  origin_clone_end_state -> set_next_state( origin_clone_end_state );
  
  labyrinth -> set_state( origin_state );
  labyrinth -> play();
}
