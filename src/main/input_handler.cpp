#include "input_handler.h"

InputHandler::InputHandler()
{
  keyboard_state = SDL_GetKeyboardState( NULL );
  int x = 0;
  int y = 0;
}

InputEvent* InputHandler::handle_input()
{ 
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

    if( e.type == SDL_KEYUP )
    {
      x = 0;
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
