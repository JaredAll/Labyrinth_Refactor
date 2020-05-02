#ifndef GAME_RENDERER_H
#define GAME_RENDERER_H

#include "game_component.h"
#include <vector>
#include <SDL.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <iostream>
#include "easy_sdl.h"
#include "cleanup.h"
#include <SDL_image.h>

class GameRenderer
{
public:
  
  GameRenderer( SDL_Window* win );

  void render( std::vector< GameComponent* > gameComponents );

  SDL_Texture* create_texture( std::string image_path );

  SDL_Texture* render_letter_texture( TTF_Font* font,
                                      char letter_singleton[],
                                      SDL_Color color);

private:

  SDL_Renderer* renderer;

  void render( RenderComponent* renderComponent );
};

#endif
