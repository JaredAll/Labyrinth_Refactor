#include "character.h"
#include "game.h"

Character::Character( Sprite* body,
                      vector< SDL_Rect* > walking_clips_param,
                      Sprite* face,
                      vector< SDL_Rect* > talking_clips_param )
  : walking_clips( walking_clips_param ), talking_clips( talking_clips_param )
{
  x_pos = 0;
  y_pos = 0;
  stride = 1;
  recruited = false;
  main_character = false;
  current_clip = walking_clips.at( 0 );
  state = new StandingState();

  setRenderComponent( body );
}

Character* Character::get_leader()
{
  return leader;
}

void Character::set_leader( Character* param_leader )
{
  leader = param_leader;
}

void Character::set_main_character( bool is_main_character )
{
  main_character = is_main_character;
}

void Character::load_into_game( Game* game )
{
  speed = game -> get_speed();
  game -> add_component( this );
}

void Character::setRenderComponent( RenderComponent* renderComponent )
{
  this -> renderComponent = renderComponent;
  renderComponent -> set_clip( current_clip );
  renderComponent -> calculate_destination( distance );
}

void Character::update( InputEvent* event )
{
  if( main_character )
  {
    set_state( state -> handle_input( event ) );    
  }

  state -> update( this );
}

void Character::set_state( CharacterState* param_state )
{
  free( state );
  state = param_state;
}

void Character::switch_state( CharacterState* param_state )
{
  state = param_state;
}

CharacterState* Character::get_state()
{
  return state;
}

void Character::update_stride()
{
  stride = ( stride + 1 ) % walking_clips.size();
  current_clip = walking_clips.at( stride );
  renderComponent -> set_clip( current_clip );
}

void Character::reset_stride()
{
  stride = 0;
  current_clip = walking_clips.at( stride );
  renderComponent -> set_clip( current_clip );  
}

uint Character::get_speed()
{
  return speed;
}

void Character::set_x( int x_param )
{
  x_pos = x_param;
}

int Character::get_x()
{
  return x_pos;
}

void Character::face_right()
{
  renderComponent -> set_flipped( false );
}

void Character::face_left()
{
  renderComponent -> set_flipped( true );
}
