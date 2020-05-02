#include "camera.h"
#include "game.h"

Camera::Camera( std::vector< GameComponent* > param_components )
{
  speed = 0;
  components = param_components;
}

void Camera::load_into_game( Game* game )
{
  speed = game -> get_speed();
  game -> add_component( this );
}

void Camera::pan_right()
{
  for(GameComponent* component : components)
  {
    if( component -> is_panning() )
    {
      component -> pan_right( speed );
    }
  }
}

void Camera::pan_left()
{
  for( GameComponent* component : components )
  {
    if( component -> is_panning() )
    {
      component -> pan_left( speed );
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

  for( GameComponent* component : components )
  {
    vector< RenderComponent* > subRenderComponents =
      component -> get_render_components();

    for( RenderComponent* subRenderComponent : subRenderComponents )
    {
      renderComponents.push_back( subRenderComponent );
    }
  }

  return renderComponents;
}
