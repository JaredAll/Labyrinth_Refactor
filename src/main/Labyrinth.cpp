#include "following_state.h"
#include "game.h"
#include "game_renderer.h"
#include "sprite.h"
#include "input_event.h"
#include "camera.h"
#include "origin.h"
#include "text_box.h"

using namespace std;

int main( int argc, char* argv[] )
{
  Game* labyrinth = new Game();
  
  labyrinth -> initialize();
  labyrinth -> load_scene( origin_config );
  labyrinth -> play();
}
