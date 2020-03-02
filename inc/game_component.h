#ifndef GAME_COMPONENT_H
#define GAME_COMPONENT_H

#include "render_component.h"
#include "input_event.h"
#include <vector>
#include <iostream>

using namespace std;

class Game;

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

  virtual vector< RenderComponent* > get_render_components()
  {
    vector< RenderComponent* > renderComponents;
    renderComponents.push_back( renderComponent );
    return renderComponents;
  }

  virtual void pan_left( uint speed )
  {
    update_render_components( -1 * speed );
  }

  virtual void pan_right( uint speed )
  {
    update_render_components( speed );
  }

  virtual void load_into_game( Game* game ) = 0;
  
protected:
  
  RenderComponent* renderComponent;

  uint distance = 1;

private:
  
  void update_render_components( int speed )
  {
    for( RenderComponent* component : get_render_components() )
    {
      int x = component -> get_x();
      component -> set_x( x + speed / distance );
      component -> calculate_destination( distance );     
    }
  }
};

#endif
