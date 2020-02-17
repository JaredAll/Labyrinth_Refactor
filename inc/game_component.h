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

  virtual RenderComponent* get_render_component() = 0;

protected:
  RenderComponent* renderComponent;
};

#endif
