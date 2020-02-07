#ifndef RENDER_COMPONENT_H
#define RENDER_COMPONENT_H

#include <SDL.h>

class RenderComponent
{
public:
  
  virtual SDL_Texture* getTexture() = 0;

  virtual SDL_Rect* getDestination() = 0;

  virtual SDL_Rect* getClip() = 0;
  
};

#endif
