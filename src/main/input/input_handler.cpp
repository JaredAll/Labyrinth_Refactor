#include "input_handler.h"

InputHandler::InputHandler()
{
  keyboard_state = SDL_GetKeyboardState( NULL );
  int x = 0;
  int y = 0;
  bool r_key = false;
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

      if( r_key_down( e ) )
      {
        r_key = true;
      }

      if( escape( e ))
      {
        exit( 0 );
      }
    }

    if( e.type == SDL_KEYUP )
    {
      x = 0;
      r_key = false;
    }

    if( e.type == SDL_QUIT )
    {
      exit( 0 );
    }
  }
  
  return new InputEvent(r_key, x, y );
}

bool InputHandler::escape( SDL_Event e )
{
  return e.key.keysym.sym ==
    SDLK_ESCAPE;
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

bool InputHandler::r_key_down( SDL_Event e )
{
  return e.key.keysym.sym ==
    SDLK_r;
}
