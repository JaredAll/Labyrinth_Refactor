#include "following_state.h"
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
  doug -> set_main_character( true );

  Character* lunius =
    labyrinth -> create_character( lunius_config );

  lunius -> set_leader( doug );
  lunius -> set_state( new FollowingState( lunius_config.num_walking_sprites ) );

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
  doug -> load_into_game( labyrinth );
  lunius -> load_into_game( labyrinth );

  labyrinth -> play();
}
