#ifndef CAMERA_H
#define CAMERA_H

#include "game_component.h"
#include <vector>

class Camera : public GameComponent
{
public:

  Camera( std::vector< GameComponent* > components );

  vector< RenderComponent* > get_render_components();

  void load_into_game( Game* game );

  void update( InputEvent* event );

  void pan_right();
  
  void pan_left();

private:

  std::vector< GameComponent* > components;

  uint speed;
};

#endif
