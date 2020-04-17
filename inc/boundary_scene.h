#ifndef BOUNDARY_SCENE_H
#define BOUNDARY_SCENE_H
#include "game_component.h"
#include "camera.h"
#include "character.h"
#include "game.h"
#include "scene_state.h"

class Game;

class BoundaryScene : public Scene
{
public:

  BoundaryScene( Scene* scene, bool left_boundary );

private:
  void handle_boundary() override;
  void update_entities( InputEvent* event ) override;

  bool left_boundary;
};

#endif
