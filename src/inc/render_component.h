#ifndef RENDER_COMPONENT_H
#define RENDER_COMPONENT_H

#include <SDL.h>
#include <iostream>

using namespace std;

class RenderComponent
{
public:
  
  virtual SDL_Texture* getTexture() const = 0; 

  virtual SDL_Rect* getDestination() const = 0;

  virtual SDL_Rect* getClip() const = 0;

  virtual void set_clip( SDL_Rect *clip ) = 0;

  virtual void set_destination( SDL_Rect* destination ) = 0;

  virtual int get_x() = 0;

  virtual int get_y() = 0;

  virtual void set_x( int x ) = 0;

  virtual void set_y( int y ) = 0;

  virtual bool is_flipped() = 0;

  virtual void set_flipped( bool flipped ) = 0;

  virtual void calculate_destination( uint distance )
  {
    if( getDestination() )
    {
      free ( getDestination() );
    }

    SDL_Rect* new_destination = new SDL_Rect();
    new_destination -> x = get_x();
    new_destination -> y = get_y();
    new_destination -> h = ( getClip() -> h ) / distance;
    new_destination -> w = ( getClip() -> w ) / distance;

    set_destination( new_destination );
  }
  
};

#endif
