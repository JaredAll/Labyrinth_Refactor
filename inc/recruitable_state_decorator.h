#ifndef RECRUITABLE_STATE_DECORATER_H
#define RECRUITABLE_STATE_DECORATER_H

#include "character_state.h"
#include "character.h"
#include "text_box.h"
#include "following_state.h"

class TextBox;

class RecruitableStateDecorator : public CharacterState
{
public:

  RecruitableStateDecorator( Character* main_character,
                             TextBox* param_prompt,
                             CharacterState* character_state );

  void update( Character* character );

  CharacterState* right();
  
  CharacterState* left();

  CharacterState* no_input();

private:

  CharacterState* character_state;
  TextBox* prompt;
  Character* main_character;
  uint recruit_distance;
};

#endif
