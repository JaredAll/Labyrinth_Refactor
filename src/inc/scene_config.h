#ifndef SCENE_CONFIG
#define SCENE_CONFIG

struct SceneConfig
{
  CharacterConfig* main_character_config;
  std::vector< CharacterConfig* > characterConfigurations;
  std::vector< SceneryConfig* > sceneryConfigurations;
  std::vector< TextBoxConfig* > textBoxConfigurations;
  int left_boundary;
  int right_boundary;
};

#endif
