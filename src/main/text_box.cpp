#include "text_box.h"

TextBox::TextBox( vector< Glyph* > param_letters )
  : letters( param_letters )
{
  panning = false;
}

void TextBox::update( InputEvent* e )
{  
}

void TextBox::load_into_game( Game* game )
{
  game -> add_component( this );
}

vector< RenderComponent* > TextBox::get_render_components()
{
  vector< RenderComponent* > glyphs;
  for( uint letter = 0; letter < letters.size(); letter++ )
  {
    glyphs.push_back( letters.at( letter ) );
  }
  return glyphs;
}
