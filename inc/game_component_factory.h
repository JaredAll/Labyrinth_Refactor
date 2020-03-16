#ifndef GAME_COMPONENT_FACTORY_H
#define GAME_COMPONENT_FACTORY_H

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
#include "scene_config.h"
#include "scenery.h"
#include "scene.h"
#include "character.h"
#include "sprite_clipper.h"
#include "input_handler.h"
#include "input_event.h"
#include <unistd.h>
#include "text_box.h"

class TextBox;

class Scenery;

class GameComponentFactory
{
public:
  
  GameComponentFactory( GameRenderer* renderer, SpriteClipper* clipper );

  Character* create_character( CharacterConfig configuration );

  Scenery* create_scenery( SceneryConfig configuration );

  Scene* create_scene( SceneConfig configuration );

  TextBox* create_text_box();

private:
    Sprite* initialize_sprite( uint x, uint y, std::string resouce );

    GameRenderer* renderer;

    SpriteClipper* clipper;
};

#endif
