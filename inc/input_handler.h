#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include "input_event.h"
#include <SDL.h>

class InputHandler
{
public:

  InputHandler();

  InputEvent* handle_input();

private:

  bool right_arrow( SDL_Event e );

  bool left_arrow( SDL_Event e );

  SDL_Event e;
  const Uint8* keyboard_state;
  int x;
  int y;
};

#endif
