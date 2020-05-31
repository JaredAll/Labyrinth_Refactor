#include "glyph.h"

Glyph::Glyph( SDL_Rect* param_destination, SDL_Texture* param_texture )
{
  destination = param_destination;
  texture = param_texture;
}

SDL_Texture* Glyph::getTexture() const
{
  return texture;
}

SDL_Rect* Glyph::getDestination() const
{
  return destination;
}

SDL_Rect* Glyph::getClip() const
{
  return NULL;
}

void Glyph::set_clip( SDL_Rect *clip )
{
  
}

void Glyph::set_destination( SDL_Rect* param_destination )
{
  destination = param_destination;
}

void Glyph::calculate_destination( uint distance )
{
  destination -> h = destination -> h / distance;
  destination -> w = destination -> w / distance;
}

int Glyph::get_x()
{
  return destination -> x;
}

int Glyph::get_y()
{
  return destination -> y;
}

void Glyph::set_x( int param_x )
{
  destination -> x = param_x;
}

void Glyph::set_y( int param_y )
{
  destination -> y = param_y;
}

bool Glyph::is_flipped()
{
  return false;
}

void Glyph::set_flipped( bool flipped )
{
  
}
