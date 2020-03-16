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

  TextBox( uint param_x,
           uint param_y,
           uint param_h,
           uint param_w );

  void display( string message,
                SDL_Renderer *renderer,
                TTF_Font *font,
                uint letters );

  void update( InputEvent* e );

  void load_into_game( Game* game );

private:

  uint x_pos;
  uint y_pos;
  uint height;
  uint width;
  vector< SDL_Rect* > letter_slots;
  SDL_Rect *display_box;
  vector< SDL_Texture *> letter_textures;
  string previous_message;

};

#endif
