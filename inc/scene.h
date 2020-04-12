#ifndef SCENE_H
#define SCENE_H
#include "game_component.h"
#include "camera.h"
#include "character.h"
#include "game.h"
#include "scene_state.h"

class Game;

class Scene : public GameComponent
{
public:

  Scene( Camera* camera,
         Character* main_character,
         vector< Character* > characters,
         int left_boundary,
         int right_boundary );

  void update( InputEvent* event );

  void load_into_game( Game* game );

  vector< RenderComponent* > get_render_components();

  SceneState* get_state();

private:
  Camera* camera;
  
  Character* main_character;

  vector< Character* > characters;
  
  SceneState state;

  int left_boundary;
  int right_boundary;

  void handle_boundary();
  
  void update_entities( InputEvent* event );
};

#endif
