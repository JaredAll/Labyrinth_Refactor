#ifndef SPRITE_CLIPPER
#define SPRITE_CLIPPER

#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include "sprite.h"

using namespace std;

class SpriteClipper
{
public:
  vector< SDL_Rect* > clip_sprite( Sprite* sprite,
                                  uint segments );
};

#endif
