#include "sprite.h"
#include "easy_sdl.h"

Sprite::Sprite( int param_x,
                int param_y,
                SDL_Texture* sprite_texture )
  : x( param_x ), y( param_y )
{
  this -> sprite_texture = sprite_texture;
  clip = NULL;
  destination = new SDL_Rect();
  initialize_dimensions();
  initialize_destination();
}

void Sprite::initialize_destination()
{
  destination -> x = x;
  destination -> y = y;
  destination -> h = h;
  destination -> w = w;
}

void Sprite::initialize_dimensions()
{
  SDL_QueryTexture( sprite_texture, NULL, NULL, &w,
                    &h );
}

void Sprite::set_clip( SDL_Rect *param_clip )
{
  clip = param_clip;
}

void Sprite::set_position( int new_x, int new_y )
{
  x = new_x;
  y = new_y;
}

void Sprite::set_position( int new_x )
{
  x = new_x;
}

void Sprite::reset_position()
{
  
}

SDL_Texture* Sprite::getTexture()
{
  return sprite_texture;
}

SDL_Rect* Sprite::getDestination()
{
  return destination;
}

SDL_Rect* Sprite::getClip()
{
  return clip;
}

int Sprite::get_h()
{
  return h;
}

int Sprite::get_w()
{
  return w;
}

int Sprite::get_x()
{
  return x;
}

int Sprite::get_y()
{
  return y;
}
