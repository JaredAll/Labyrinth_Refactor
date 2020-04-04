#include "recruitable_state_decorator.h"

RecruitableStateDecorator::RecruitableStateDecorator( Character* param_main_character,
                                                      TextBox* param_prompt,
                                                      CharacterState* param_character_state )
  : main_character( param_main_character ),
    prompt( param_prompt ),
    character_state( param_character_state )
{
  recruit_distance = 100;
}

void RecruitableStateDecorator::update( Character* character )
{
  character_state -> update( character );
}

CharacterState* RecruitableStateDecorator::handle_input( InputEvent* e )
{
  
  if( abs( main_character -> get_x() - character -> get_x() ) < recruit_distance )
  {
    prompt -> set_display( true );
    if( main_character -> is_recruiting() )
    {
      character -> switch_state( new FollowingState( main_character ) );
    }
  }
  else
  {
    prompt -> set_display( false );
  }
}

CharacterState* RecruitableStateDecorator::right()
{
  return new RecruitableStateDecorator( main_character, prompt, character_state -> right() );
}

CharacterState* RecruitableStateDecorator::left()
{
  return new RecruitableStateDecorator( main_character, prompt, character_state -> left() );
}

CharacterState* RecruitableStateDecorator::no_input()
{
  return new RecruitableStateDecorator( main_character, prompt, character_state -> no_input() );
}
