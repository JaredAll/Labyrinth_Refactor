#ifndef CHARACTER_STATE_H
#define CHARACTER_STATE_H

#include "game_component.h"
#include "input_event.h"

class Character;

class CharacterState
{
public:
  virtual void update( Character* character ) = 0;

  virtual CharacterState* handle_input( InputEvent* event )
  {
    CharacterState* next_state;
    if( event -> get_x_input() == 1 )
    {
      next_state = this -> right();
    }
    else if( event -> get_x_input() == -1 )
    {
      next_state = this -> left();
    }
    else if( event -> is_r_pressed())
    {
      next_state = this -> r_key();
    }
    else
    {
      next_state = this -> no_input();
    }

    return next_state;
  }

  virtual CharacterState* left() = 0;

  virtual CharacterState* right() = 0;

  virtual CharacterState* r_key() = 0;

  virtual CharacterState* no_input() = 0;

};

#endif
