#include "character_struct.h"

uint image_x = 400;
uint image_y = 300;
std::string sprite_sheet_resource = 
  "/home/jared/Games/Labyrinth/resources/sprites/dougsheet.png";
uint num_walking_sprites = 3;
uint num_talking_sprites = 2;

CharacterConfig doug_config = {
  image_x, image_y, sprite_sheet_resource, sprite_sheet_resource,
  num_walking_sprites, num_talking_sprites
};
