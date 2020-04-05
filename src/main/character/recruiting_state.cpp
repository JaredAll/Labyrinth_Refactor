#include "recruiting_state.h"

void RecruitingState::update( Character* character )
{
  character -> set_recruiting( true );
}

CharacterState* RecruitingState::right()
{
  return new StandingState();
}

CharacterState* RecruitingState::left()
{
  return new StandingState();
}

CharacterState* RecruitingState::r_key()
{
  return new StandingState();
}

CharacterState* RecruitingState::no_input()
{
  return new StandingState();
}
