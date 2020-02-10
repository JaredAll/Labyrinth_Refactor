#ifndef CHARACTER_H
#define CHARACTER_H

#include <SDL.h>
#include <stdio.h>
#include <SDL_image.h>
#include <iostream>
#include <vector>
#include "sprite.h"
#include <unistd.h>
#include "game_component.h"

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

  void update();

  /**
   * make the character walk left
   * @param speed the speed that the character walks
   * @param count the characters cycle count
   */
  void walk_left( uint speed, uint count );

  /**
   * make the character walk right
   * @param speed the speed that the character walks
   * @param count the characters walking cycle count
   */
  void walk_right( uint speed, uint count );

  /**
   * make the character stand
   */
  void stand();

  /**
   * set the characters coordinates
   */
  void set_position( int x, int y );
  
  /**
   * set the characters screen coordinates
   */
  void set_screen_position( int x, int y );

  /**
   * get the characters coordinates
   */
  vector< int > get_screen_position();

  /**
   * get the characters coordinates
   */
  vector< int > get_position();
  
  /**
   * update characters position
   */
  void update_pos( bool left, uint speed );

  /**
   * reset characters position
   */
  void reset();

  /**
   *reset characters position with offset
   */
  void reset( uint offset );

  /**
   * determine if two characters are equal
   */
  bool equals( Character *character );

  /**
   * gets the name of the character
   */
  string get_name();

  /**
   * set stage position
   */
  void set_stage_pos( int screen_pos, int pos );

  RenderComponent* get_render_component();

  void setRenderComponent( RenderComponent* renderComponent );

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
  
  Sprite *torso;
  vector< SDL_Rect* > talking_clips;
  
  uint force;
  uint diversion;
  uint stealth;

};

#endif

  

