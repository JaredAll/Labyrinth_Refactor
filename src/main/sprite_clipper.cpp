#include "sprite_clipper.h"

vector< SDL_Rect* > SpriteClipper::clip_sprite(
  Sprite* sprite,
  uint segments )
{
  
  vector< SDL_Rect* > clips;
  for( uint i = 0; i < segments; i++ )
  {
    SDL_Rect *clip = new SDL_Rect();
    clips.push_back( clip );
    
    clips.at( i ) -> x = i * ( sprite ->
                                       get_w() /
                                       segments );
    clips.at( i ) -> y = 0;
    
    clips.at( i ) -> h = sprite ->
      get_h();
    
    clips.at( i ) -> w = sprite ->
      get_w() /
      segments;
  }

  return clips;
}
