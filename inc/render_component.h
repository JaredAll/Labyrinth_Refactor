#ifndef RENDER_COMPONENT_H
#define RENDER_COMPONENT_H

#include <SDL.h>

class RenderComponent
{
public:
  
  virtual SDL_Texture* getTexture() = 0;

  virtual SDL_Rect* getDestination() = 0;

  virtual SDL_Rect* getClip() = 0;

  virtual void set_clip( SDL_Rect *clip ) = 0;

  virtual void set_destination( SDL_Rect* destination ) = 0;

  virtual int get_x() = 0;

  virtual int get_y() = 0;

  virtual void calculate_destination()
  {
    if( getDestination() )
    {
      free ( getDestination() );
    }

    SDL_Rect* new_destination = new SDL_Rect();
    new_destination -> x = get_x();
    new_destination -> y = get_y();
    new_destination -> h = getClip() -> h;
    new_destination -> w = getClip() -> w;

    set_destination( new_destination );
  }
  
};

#endif
