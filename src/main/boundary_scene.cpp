#include "boundary_scene.h"

BoundaryScene::BoundaryScene( Scene* scene, bool param_left_boundary )
  :  Scene( scene -> get_camera(),
            scene -> get_main_character(),
            scene -> get_characters(),
            scene -> get_left_boundary(),
            scene -> get_right_boundary() ),
     left_boundary( param_left_boundary )
{
}

void BoundaryScene::handle_boundary()
{
}

void BoundaryScene::update_entities( InputEvent* event )
{
  int x_input = event -> get_x_input();
  if( x_input == 1 && left_boundary )
  {
    set_state( SceneState::boundary );
  }
  else if( x_input == -1 && !left_boundary )
  {
    set_state( SceneState::boundary );
  }
  else
  {
    set_state( SceneState::resume );
  }
}
