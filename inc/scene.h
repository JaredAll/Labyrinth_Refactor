#ifndef SCENE_H
#define SCENE_H
#include "game_component.h"
#include "camera.h"

class Scene : public GameComponent
{
public:

private:
  Camera* camera;
};

#endif
