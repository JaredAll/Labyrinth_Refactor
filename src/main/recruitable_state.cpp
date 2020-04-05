#include "recruitable_state.h"

RecruitableState::RecruitableState( Character* param_main_character,
                                                      TextBox* param_prompt )
  : main_character( param_main_character ),
    prompt( param_prompt )
{
  recruit_distance = 100;
}

void RecruitableState::update( Character* character )
{
  if( abs( main_character -> get_x() - character -> get_x() ) < recruit_distance )
  {
    prompt -> set_display( true );
    if( main_character -> is_recruiting() )
    {
      main_character -> set_recruiting( false );
      prompt -> set_display( false );
      character -> set_state( new FollowingState( 0, main_character ) );
    }
  }
  else
  {
    prompt -> set_display( false );
  }
}

CharacterState* RecruitableState::right()
{
  return this;
}

CharacterState* RecruitableState::left()
{
  return this;
}

CharacterState* RecruitableState::r_key()
{
  return this;
}

CharacterState* RecruitableState::no_input()
{
  return this;
}
