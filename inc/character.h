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

/**
 * A character class
 * @author Jared Allen
 * @version 9 February 2019
 */
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

  RenderComponent* get_render_component();

  void setRenderComponent( RenderComponent* renderComponent );

  void set_state( CharacterState* state );

  void reset_stride();

  void update_stride();

  void face_right();

  void face_left();

  uint get_x();

private:

  string name;
  bool recruited;

  bool facing_left;
  int x_pos;
  int y_pos;

  uint num_walking_sprites;
  uint num_talking_sprites;

  Sprite *full_body;
  vector< SDL_Rect* > walking_clips;
  SDL_Rect* current_clip;
  uint stride;
  CharacterState* state;
  
  Sprite *torso;
  vector< SDL_Rect* > talking_clips;
  
  uint force;
  uint diversion;
  uint stealth;

};

#endif

  

