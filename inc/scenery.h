#ifndef SCENERY_H
#define SCENERY_H

#include "game_component.h"
#include "render_component.h"
#include "input_event.h"
#include "sprite.h"
#include "game.h"

class Scenery : public GameComponent
{
public:
  Scenery( Sprite* sprite );

  void load_into_game( Game* game );

  void update( InputEvent* event );

private:
  Sprite* sprite;
};

#endif
