#include <SDL.h>
#include <stdio.h>
#include <SDL_image.h>
#include "cleanup.h"
#include <iostream>
#include <vector>
#include "easy_sdl.h"
#include "game.h"

using namespace std;

int main( int argc, char* argv[] )
{

  /* Setup Window */

  //initialize video
  if (SDL_Init(SDL_INIT_VIDEO) != 0)
  {
    logSDLError( std::cout, "SDL_Init" );
    return 1;
  }


  //create window
  int window_width = 1000;
  int window_height = 500;
  SDL_Window *win = SDL_CreateWindow("Labyrinth sketch 1",
                                     SDL_WINDOWPOS_CENTERED,
                                     SDL_WINDOWPOS_CENTERED,
                                     window_width, window_height,
                                     SDL_WINDOW_SHOWN);
  if (win == nullptr)
  {
    logSDLError( std::cout, "CreateWindow" );
    SDL_Quit();
    return 1;
  }

  /* End Window Setup */

  /* Set Character Sprites */

  uint character_plane_x = 415;

  uint doug_x = 500;
  uint doug_y = character_plane_x;

  string resources_uri = "/home/jared/Games/Labyrinth/resources/";

  Sprite* doug_s =
    new Sprite( resources_uri + "sprites/dougsheet.png", ren, doug_x, doug_y );

  doug_s -> set_position(
    doug_x, character_plane_x - doug_s -> get_height() );

  Sprite* doug_faces = new Sprite( resources_uri + "sprites/dougFsheet.png", ren, 400, 0 );

  Character *doug = new Character( "doug",
                                   doug_s, doug_faces, 0, 0, 0, 3, 2 );

  

}
