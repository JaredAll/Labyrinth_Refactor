#ifndef SPRITE_H
#define SPRITE_H

#include <SDL.h>
#include <stdio.h>
#include <SDL_image.h>
#include <iostream>
#include <vector>
#include "render_component.h"

using namespace std;

/**
 * A sprite class
 * @author Jared Allen
 * @version 8 February 2019
 */
class Sprite : public RenderComponent
{
public:

  /**
   * Constructor
   * @param texture_path the texture file name
   * for the entire texture
   * @param x the x coordinate
   * @param y the y coordinate
   */
  Sprite( int x,
          int y,
          SDL_Texture* sprite_texture );

  /**
   * method to change source rectangle
   * @param source the new source
   */
  void set_clip( SDL_Rect *source ) override;

  /**
   * method to change destination rectangle
   * @param destination the new destination
   */
  void set_destination( SDL_Rect *destination ) override;

  /** 
   * method to change sprite position
   * @param new_x the new x coordinate
   * @param new_y the new y coordinate
   */
  void set_position( int new_x, int new_y );

  /**
   * method to change sprite position
   * @param new_x the new x coordinate
   */
  void set_position( int new_x );

  /**
   * method to reset sprite position with offset
   * @param offset the offset
   */
  void reset_position();

  /** 
   * method to get sprite x position
   */
  int get_x() override;

  /** 
   * method to get sprite y position
   */
  int get_y() override;

  void set_x( int x ) override;

  void set_y( int y ) override;

  int get_h();

  int get_w();
  
  SDL_Texture* getTexture() const override;

  SDL_Rect* getDestination() const override;

  SDL_Rect* getClip() const override;

  bool is_flipped() override;

  void set_flipped( bool flipped ) override;

private:

  void synchronize_destination();

  void initialize_dimensions();

  SDL_Texture *sprite_texture;
  SDL_Rect *clip;
  SDL_Renderer *renderer;
  SDL_Rect *destination;
  int x;
  int y;
  int h;
  int w;

  bool flipped;
};



#endif
