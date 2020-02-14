#include "input_handler.h"

InputHandler::InputHandler()
{
  state = new StandingState();
  keyboard_state = SDL_GetKeyboardState( NULL );
}

CharacterState* InputHandler::handle_input()
{
  CharacterState* previous_state = state;
  SDL_PumpEvents();
  
  while( SDL_PollEvent( &e ))
  {
    if( e.type == SDL_KEYDOWN )
    {
      if( right_arrow( e ) )
      {
        std::cout << "right" << std::endl;
        state = new WalkingState();
        state -> right();
      }
      
      if( left_arrow( e ))
      {
        std::cout << "left" << std::endl;
        state = new WalkingState();
        state -> left();
      }
    }
    else
    {
      state = new StandingState();
    }
  }    

  if( state != previous_state )
  {
    free( previous_state );
  }

  return state;
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
