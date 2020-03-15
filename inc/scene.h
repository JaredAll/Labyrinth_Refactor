#ifndef SCENE_H
#define SCENE_H
#include "game_component.h"
#include "camera.h"
#include "character.h"

class Scene : public GameComponent
{
public:

  Scene( Camera* camera,
         Character* main_character,
         vector< Character* > characters );

  void update( InputEvent* event );

  void load_into_game( Game* game );

private:
  Camera* camera;
  
  Character* main_character;

  vector< Character* > characters;
};

#endif
