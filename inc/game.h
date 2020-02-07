#ifndef GAME
#define GAME

#include <SDL.h>
#include <stdio.h>
#include <SDL_image.h>
#include "cleanup.h"
#include <iostream>
#include <vector>
#include "game.h"
#include "game_renderer.h"

class Game
{
public:
  
  void initialize();

  GameRenderer* get_renderer();
  
private:
  
  GameRenderer* renderer;
};

#endif
