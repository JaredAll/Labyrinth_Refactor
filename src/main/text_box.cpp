#include "text_box.h"

TextBox::TextBox( vector< Glyph* > param_letters )
  : letters( param_letters )
{
  display = true;
}

void TextBox::update( InputEvent* e )
{  
}

void TextBox::load_into_game( Game* game )
{
  game -> add_component( this );
}

void TextBox::set_display( bool param_display )
{
  display = param_display;
}

bool TextBox::will_display()
{
  return display;
}

vector< RenderComponent* > TextBox::get_render_components()
{
  vector< RenderComponent* > glyphs;
  if( display )
  { 
    for( uint letter = 0; letter < letters.size(); letter++ )
    {
      glyphs.push_back( letters.at( letter ) );
    }
  }
  return glyphs;
}
