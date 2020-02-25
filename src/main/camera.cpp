#include "camera.h"

Camera::Camera( std::vector< GameComponent* > param_components )
{
  components = param_components;
  speed = 2;
}

void Camera::pan_right()
{
  for( uint i = 0; i < components.size(); i++ )
  {
    components.at( i ) -> pan_right( speed );
  }
}

void Camera::pan_left()
{
  for( uint i = 0; i < components.size(); i++ )
  {
    components.at( i ) -> pan_left( speed );
  }
}

void Camera::update( InputEvent* event )
{
  int input = event -> get_x_input();
  if( input == 1 )
  {
    pan_left();
  }
  else if( input == -1 )
  {
    pan_right();
  }
}

RenderComponent* Camera::get_render_component()
{
  return components.at( 0 ) -> get_render_component();
}
