#ifndef CHARACTER_STATE_H
#define CHARACTER_STATE_H

#include "game_component.h"

class Character;

class CharacterState
{
public:
  virtual void update( Character* character ) = 0;

  virtual void left() = 0;

  virtual void right() = 0;
};

#endif
