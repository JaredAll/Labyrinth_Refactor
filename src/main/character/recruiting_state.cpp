#include "recruiting_state.h"

void RecruitingState::update( Character* character )
{
  character -> set_recruiting( true );
}

CharacterState* RecruitingState::right()
{
  return this;
}

CharacterState* RecruitingState::left()
{
  return this;
}

CharacterState* RecruitingState::no_input()
{
  return new StandingState();
}
