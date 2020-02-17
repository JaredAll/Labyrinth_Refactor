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
#include "input_handler.h"
#include "input_event.h"
#include <unistd.h>

class Game
{
public:
  
  void initialize();

  void render();

  void update( InputEvent* event );

  InputEvent* handle_input();

  Character* create_character( CharacterConfig configuration );

  Character* create_main_character( CharacterConfig configuration );

  void set_components( vector< GameComponent* > components );

private:

  Sprite* initialize_sprite( uint x, uint y, std::string resouce );

  GameRenderer* renderer;

  SpriteClipper* clipper;

  Character* main_character;

  InputHandler* input_handler;

  vector< GameComponent* > components;
};

#endif
