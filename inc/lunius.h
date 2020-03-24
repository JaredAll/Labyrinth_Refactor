#include "character_config.h"

uint lunius_image_x = 400;
uint lunius_image_y = 275;
std::string lunius_sprite_sheet_resource = 
  "/home/jared/Games/Labyrinth/resources/sprites/4knut.png";
uint lunius_num_walking_sprites = 4;
uint lunius_num_talking_sprites = 2;

CharacterConfig lunius_config = {
  lunius_image_x, lunius_image_y, lunius_sprite_sheet_resource,
  lunius_sprite_sheet_resource,
  lunius_num_walking_sprites, lunius_num_talking_sprites
};
