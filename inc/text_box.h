#ifndef TEXT_BOX
#define TEXT_BOX

#include <SDL.h>
#include <SDL_ttf.h>
#include <string>
#include <vector>
#include <stdio.h>
#include <iostream>
#include "cleanup.h"
#include "game_component.h"
#include "game.h"
#include "glyph.h"

using namespace std;

/**
 * a class to represent a text box
 * @author Jared Allen
 * @version 1 June 2019
 */
class TextBox : public GameComponent
{
public:

  TextBox( vector< Glyph* > letters );

  void update( InputEvent* e );

  void load_into_game( Game* game );

  void set_display( bool display );

  bool will_display();

  vector< RenderComponent* > get_render_components();

private:

  vector< Glyph* > letters;

  bool display;

};

#endif
