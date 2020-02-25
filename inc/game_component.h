#ifndef GAME_COMPONENT_H
#define GAME_COMPONENT_H

#include "render_component.h"
#include "input_event.h"

class GameComponent
{
public:

  virtual void update( InputEvent* event ) = 0;

  virtual void setRenderComponent( RenderComponent* component )
  {
    renderComponent = component;
  }

  virtual void set_distance( uint param_distance )
  {
    distance = param_distance;
    renderComponent -> calculate_destination( distance );
  }

  virtual RenderComponent* get_render_component() = 0;

  virtual void pan_left( uint speed )
  {
    int x = renderComponent -> get_x();
    renderComponent -> set_x( x - speed / distance );
    renderComponent -> calculate_destination( distance );
  }

  virtual void pan_right( uint speed )
  {
    int x = renderComponent -> get_x();
    renderComponent -> set_x( x + speed / distance );
    renderComponent -> calculate_destination( distance );
  }

protected:
  
  RenderComponent* renderComponent;

  uint distance = 1;
};

#endif
