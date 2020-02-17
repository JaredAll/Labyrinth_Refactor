#include "input_handler.h"

InputHandler::InputHandler()
{
  keyboard_state = SDL_GetKeyboardState( NULL );
}

InputEvent* InputHandler::handle_input()
{
  int x = 0;
  int y = 0;
  
  while( SDL_PollEvent( &e ))
  {
    if( e.type == SDL_KEYDOWN )
    {
      if( right_arrow( e ) )
      {
        x = 1;
      }
      
      if( left_arrow( e ))
      {
        x = -1;
      }
    }
  }    

  return new InputEvent( x, y );
}

bool InputHandler::right_arrow( SDL_Event e )
{
  return e.key.keysym.sym ==
   SDLK_RIGHT;
}

bool InputHandler::left_arrow( SDL_Event e )
{
  return e.key.keysym.sym ==
    SDLK_LEFT;
}
