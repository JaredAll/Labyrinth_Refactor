#include "camera.h"
#include "game.h"

Camera::Camera( std::vector< GameComponent* > param_components )
{
  components = param_components;
}

void Camera::load_into_game( Game* game )
{
  speed = game -> get_speed();
  game -> add_component( this );
}

void Camera::pan_right()
{
  for( uint i = 0; i < components.size(); i++ )
  {
    if( components.at( i ) -> is_panning() )
    {
      components.at( i ) -> pan_right( speed ); 
    }
  }
}

void Camera::pan_left()
{
  for( uint i = 0; i < components.size(); i++ )
  {
    if( components.at( i ) -> is_panning() )
    {
      components.at( i ) -> pan_left( speed );
    }
  }
}

void Camera::set_speed( uint param_speed )
{
  speed = param_speed;
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

vector< RenderComponent* > Camera::get_render_components()
{
  vector< RenderComponent* > renderComponents;

  for( uint i = 0; i < components.size(); i++ )
  {
    vector< RenderComponent* > subRenderComponents =
      components.at( i ) -> get_render_components();
    
    for( uint j = 0; j < subRenderComponents.size(); j++ )
    {
      renderComponents.push_back( subRenderComponents.at( j ) );
    }
  }

  return renderComponents;
}
