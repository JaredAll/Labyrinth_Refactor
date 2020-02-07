#include "character.h"
Character::Character( vector< SDL_Rect* > walking_clips_param,
                      vector< SDL_Rect* > talking_clips_param )
  : walking_clips( walking_clips_param ), talking_clips( talking_clips_param )
{
  x_pos = 0;
  y_pos = 0;
  stride = 1;
  facing_left = false;
  recruited = false;

  setRenderComponent( full_body );
}

RenderComponent* GameComponent::get_render_component()
{
  return renderComponent;
}

void Character::walk_right( uint speed, uint count )
{
  if( count == 3 )
  {
    stride = ( stride + 1 ) % walking_clips.size();
  }

  full_body -> set_clip( walking_clips.at( stride ) );
  
  set_position( x_pos + speed,
                y_pos );

  facing_left = false;
}

void Character::walk_left( uint speed, uint count )
{
  if( count == 3 )
  {
    stride = ( stride + 1 ) % walking_clips.size();
  }

  full_body -> set_clip( walking_clips.at( stride ) );
  set_position( x_pos - speed,
                y_pos );
  facing_left = true;
}

void Character::stand()
{
  stride = 1;
  full_body -> set_clip( walking_clips.at( stride ) );
}

void Character::set_position( int new_x, int new_y )
{
  x_pos = new_x;
  y_pos = new_y;
}

void Character::set_screen_position( int new_x, int new_y )
{
  full_body -> set_position( new_x, new_y );
}

vector< int >Character::get_screen_position()
{
  vector< int > position;
  position.push_back( full_body -> get_x() );
  position.push_back( full_body -> get_y() );
  return position;
}

vector< int > Character::get_position()
{
  vector< int > position;
  position.push_back( x_pos );
  position.push_back( y_pos );
  return position;
}

void Character::update()
{
  
}

void Character::reset()
{
  x_pos = 0;
  y_pos = 0;
  full_body -> reset_position();
}

void Character::reset( uint new_x )
{
  x_pos = new_x;
  y_pos = 0;
  full_body -> reset_position();
}

string Character::get_name()
{
  return name;
}

bool Character::equals( Character* character )
{
  return ( name == character -> get_name() );
}

void Character::set_stage_pos( int screen_pos, int pos )
{
  x_pos = pos;
  full_body -> set_position( screen_pos );
}
