#include "sprite.h"
#include "easy_sdl.h"

Sprite::Sprite( int param_x,
                int param_y,
                SDL_Texture* param_sprite_texture )
  : x( param_x ),
    y( param_y ),
    sprite_texture( param_sprite_texture )
{
  clip = NULL;
  destination = new SDL_Rect();
  initialize_dimensions();
  synchronize_destination();
  flipped = false;
}

void Sprite::synchronize_destination()
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

void Sprite::set_destination( SDL_Rect* param_destination )
{
  destination = param_destination;
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

void Sprite::set_x( int param_x )
{
  x = param_x;
}

void Sprite::set_y( int param_y )
{
  y = param_y;
}

bool Sprite::is_flipped()
{
  return flipped;
}

void Sprite::set_flipped( bool param_flipped )
{
  flipped = param_flipped;
}
