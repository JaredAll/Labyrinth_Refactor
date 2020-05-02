#ifndef GLYPH_H
#define GLYPH_H

#include <SDL.h>
#include <stdio.h>
#include <SDL_image.h>
#include <iostream>
#include <vector>
#include "render_component.h"

class Glyph : public RenderComponent
{
public:

  Glyph( SDL_Rect* destination, SDL_Texture* texture );

  SDL_Texture* getTexture();
  
  SDL_Rect* getDestination();
  
  SDL_Rect* getClip();
  
  void set_clip( SDL_Rect *clip );
  
  void set_destination( SDL_Rect* destination );

  void calculate_destination( uint distance );

  int get_x();
  
  int get_y();
  
  void set_x( int x );
  
  void set_y( int y );
  
  bool is_flipped();
  
  void set_flipped( bool flipped );

private:
  
  SDL_Rect* destination;
  
  SDL_Texture* texture;
  
};

#endif
