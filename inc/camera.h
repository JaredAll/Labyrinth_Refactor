#ifndef CAMERA_H
#define CAMERA_H

#include "game_component.h"
#include <vector>

class Camera : public GameComponent
{
public:

  Camera( std::vector< GameComponent* > components );

  RenderComponent* get_render_component();

  void update( InputEvent* event );

  void pan_right();
  
  void pan_left();

private:

  std::vector< GameComponent* > components;

  uint speed;
};

#endif
