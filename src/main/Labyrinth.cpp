#include "game.h"
#include "game_renderer.h"
#include "doug.h"
#include "lunius.h"
#include "grass.h"
#include "sky.h"
#include "sprite.h"
#include "input_event.h"
#include "camera.h"

using namespace std;

int main( int argc, char* argv[] )
{

  Game* labyrinth = new Game();
  labyrinth -> initialize();

  Character* doug =
    labyrinth -> create_character( doug_config );

  Character* lunius =
    labyrinth -> create_character( lunius_config );

  Scenery* sky =
    labyrinth -> create_scenery( sky_config );

  Scenery* grass =
    labyrinth -> create_scenery( grass_config );

  vector< GameComponent* > camera_components;
  camera_components.push_back( sky );
  camera_components.push_back( grass );
  camera_components.push_back( lunius );
  Camera* camera = new Camera( camera_components );

  camera -> load_into_game( labyrinth );
  labyrinth -> add_component( doug );

  labyrinth -> play();
}
