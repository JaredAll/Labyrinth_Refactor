#ifndef GAME_H
#define GAME_H

#include "game_component_factory.h"
#include <SDL.h>
#include <stdio.h>
#include <SDL_image.h>
#include "cleanup.h"
#include <iostream>
#include <vector>
#include "game_renderer.h"
#include "game_component.h"
#include "character_config.h"
#include "scenery_config.h"
#include "scenery.h"
#include "character.h"
#include "sprite_clipper.h"
#include "input_handler.h"
#include "input_event.h"
#include <unistd.h>

class Scenery;

class GameComponentFactory;

class Game
{
public:
  
  void initialize();

  void play();

  Character* create_character( CharacterConfig configuration );

  Scenery* create_scenery( SceneryConfig configuration );

  void set_components( vector< GameComponent* > components );

  void add_component( GameComponent* gameComponent );

  uint get_speed();

private:

  void render();

  void update( InputEvent* event );

  InputEvent* handle_input();

  GameRenderer* renderer;

  SpriteClipper* clipper;

  InputHandler* input_handler;

  GameComponentFactory* gameComponentFactory;

  vector< GameComponent* > components;

  uint speed;
};

#endif
