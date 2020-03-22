#include "following_state.h"
#include "game.h"
#include "game_renderer.h"
#include "sprite.h"
#include "input_event.h"
#include "camera.h"
#include "origin.h"
#include "hello_world.h"
#include "text_box.h"

using namespace std;

int main( int argc, char* argv[] )
{
  Game* labyrinth = new Game();
  labyrinth -> initialize();

  TextBox* hello_world = labyrinth -> create_text_box( hello_world_config );

  labyrinth -> load_scene( origin_config );
  hello_world -> load_into_game( labyrinth );
  labyrinth -> play();
}
