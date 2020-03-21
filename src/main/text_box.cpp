#include "text_box.h"

TextBox::TextBox( SDL_Rect* param_display_box,
                  vector< SDL_Rect* > param_letter_slots,
                  vector< SDL_Texture* > param_letter_textures )
  : display_box( param_display_box ),
    letter_slots( param_letter_slots ),
    letter_textures( param_letter_textures )
{}

void TextBox::update( InputEvent* e )
{  
}

void TextBox::load_into_game( Game* game )
{
  game -> add_component( this );
}
