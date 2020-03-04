#ifndef CHARACTER_H
#define CHARACTER_H

#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL_image.h>
#include <iostream>
#include <vector>
#include "sprite.h"
#include <unistd.h>
#include "game_component.h"
#include "character_state.h"
#include "walking_state.h"
#include "standing_state.h"
#include "input_event.h"

using namespace std;

class Character : public GameComponent
{
public:

  /**
   * Constructor
   * @param full_body the full body sprite
   * @param torso the torso sprite
   */
  Character( Sprite* body,
             vector< SDL_Rect* > walking_clips,
             Sprite* face,
             vector< SDL_Rect* > talking_clips );

  void update( InputEvent* event );

  void setRenderComponent( RenderComponent* renderComponent );

  void load_into_game( Game* game );

  void set_state( CharacterState* state );

  void set_main_character( bool is_main_character );

  void set_leader( Character* leader );

  Character* get_leader();

  void reset_stride();

  void update_stride();

  void face_right();

  void face_left();

  uint get_speed();

  void set_x( int param_x );

  int get_x();

private:

  string name;
  bool recruited;
  bool main_character;

  int x_pos;
  int y_pos;
  uint speed;

  uint num_walking_sprites;
  uint num_talking_sprites;

  Sprite *full_body;
  vector< SDL_Rect* > walking_clips;
  SDL_Rect* current_clip;
  uint stride;
  CharacterState* state;
  Character* leader;
  
  Sprite *torso;
  vector< SDL_Rect* > talking_clips;
  
  uint force;
  uint diversion;
  uint stealth;

};

#endif

  

