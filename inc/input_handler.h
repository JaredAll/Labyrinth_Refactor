#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include "character_state.h"
#include "walking_state.h"
#include "standing_state.h"
#include <SDL.h>

class InputHandler
{
public:

  InputHandler();

  CharacterState* handle_input();

private:

  bool right_arrow( SDL_Event e );

  bool left_arrow( SDL_Event e );

  CharacterState* state;
  SDL_Event e;
  const Uint8* keyboard_state;
};

#endif
