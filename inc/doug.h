#include "character_config.h"

uint doug_image_x = 400;
uint doug_image_y = 300;
std::string doug_sprite_sheet_resource = 
  "/home/jared/Games/Labyrinth/resources/sprites/dougsheet.png";
uint doug_num_walking_sprites = 3;
uint doug_num_talking_sprites = 2;

CharacterConfig doug_config = {
  doug_image_x, doug_image_y, doug_sprite_sheet_resource,
  doug_sprite_sheet_resource,
  doug_num_walking_sprites, doug_num_talking_sprites
};
