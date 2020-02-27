#ifndef CHARACTER_CONFIG
#define CHARACTER_CONFIG

struct CharacterConfig
{
  uint image_x;
  uint image_y;

  std::string sprite_sheet_body;
  std::string sprite_sheet_face;

  uint num_walking_sprites;
  uint num_talking_sprites;
};

#endif
