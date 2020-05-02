#ifndef CAMERA_H
#define CAMERA_H

#include "game_component.h"
#include <vector>

class Camera : public GameComponent
{
public:

  explicit Camera( std::vector< GameComponent* > components );

  vector< RenderComponent* > get_render_components() override;

  void load_into_game( Game* game ) override;

  void update( InputEvent* event ) override;

  void pan_right();
  
  void pan_left();

  void set_speed( uint speed );

private:

  std::vector< GameComponent* > components;

  uint speed;
};

#endif
