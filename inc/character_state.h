#ifndef CHARACTER_STATE_H
#define CHARACTER_STATE_H

#include "game_component.h"

class Character;

class CharacterState
{
public:
  virtual void update( Character* character ) = 0;
};

#endif
