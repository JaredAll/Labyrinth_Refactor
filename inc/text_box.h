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

using namespace std;

/**
 * a class to represent a text box
 * @author Jared Allen
 * @version 1 June 2019
 */
class TextBox : GameComponent
{
public:

  TextBox( SDL_Rect* displayBox,
           vector< SDL_Rect* > letter_slots,
           vector< SDL_Texture* > letter_textures );

  void update( InputEvent* e );

  void load_into_game( Game* game );

private:

  vector< SDL_Rect* > letter_slots;
  SDL_Rect *display_box;
  vector< SDL_Texture *> letter_textures;
  
};

#endif
