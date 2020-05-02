#ifndef RECRUITABLE_STATE_H
#define RECRUITABLE_STATE_H

#include "character_state.h"
#include "character.h"
#include "text_box.h"
#include "following_state.h"

class TextBox;

class RecruitableState : public CharacterState
{
public:

  RecruitableState( Character* main_character,
                    TextBox* param_prompt );

  void update( Character* character );

  CharacterState* right();
  
  CharacterState* left();

  CharacterState* r_key();

  CharacterState* no_input();

private:

  TextBox* prompt;
  Character* main_character;
  uint recruit_distance;
};

#endif
