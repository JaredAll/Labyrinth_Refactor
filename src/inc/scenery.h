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
  Scenery( vector< Sprite* > sprites );

  void load_into_game( Game* game ) override;

  void update( InputEvent* event ) override;

  vector< RenderComponent* > get_render_components() override;

private:
  vector< Sprite* > sprites;
};

#endif
