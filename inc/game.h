#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include <stdio.h>
#include <SDL_image.h>
#include "cleanup.h"
#include <iostream>
#include <vector>
#include "game.h"
#include "game_renderer.h"
#include "character_struct.h"
#include "character.h"
#include "sprite_clipper.h"
#include <unistd.h>

class Game
{
public:
  
  void initialize();

  void render( vector< GameComponent* > components );

  void update( vector< GameComponent* > components );

  Character* create_character( CharacterConfig configuration );

private:

  Sprite* initialize_sprite( uint x, uint y, std::string resouce );

  GameRenderer* renderer;

  SpriteClipper* clipper;
};

#endif
