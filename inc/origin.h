#include "scene_config.h"
#include "grass.h"
#include "sky.h"
#include "doug.h"
#include "lunius.h"
#include "recruit_text_box.h"

#ifndef ORIGIN_CONFIG
#define ORIGIN_CONFIG

std::vector< CharacterConfig* > characterConfigurations = { &lunius_config };
std::vector< SceneryConfig* > sceneryConfigurations = { &sky_config, &grass_config };
std::vector< TextBoxConfig* > textBoxConfigurations = { & recruit_text_config };

SceneConfig origin_config = {
  &doug_config,
  characterConfigurations,
  sceneryConfigurations,
  textBoxConfigurations,
  -100,
  100
};

#endif
