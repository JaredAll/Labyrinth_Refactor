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

  SDL_Texture* getTexture() const override;
  
  SDL_Rect* getDestination() const override;
  
  SDL_Rect* getClip() const override;
  
  void set_clip( SDL_Rect *clip ) override;
  
  void set_destination( SDL_Rect* destination ) override;

  void calculate_destination( uint distance ) override;

  int get_x() override;
  
  int get_y() override;
  
  void set_x( int x ) override;
  
  void set_y( int y ) override;
  
  bool is_flipped() override;
  
  void set_flipped( bool flipped ) override;

private:
  
  SDL_Rect* destination;
  
  SDL_Texture* texture;
  
};

#endif
