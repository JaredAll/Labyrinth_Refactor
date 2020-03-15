#include "scene_config.h"
#include "grass.h"
#include "sky.h"
#include "doug.h"
#include "lunius.h"

std::vector< CharacterConfig* > characterConfigurations = { &lunius_config };
std::vector< SceneryConfig* > sceneryConfigurations = { &sky_config, &grass_config };

SceneConfig origin_config = {
  &doug_config, characterConfigurations, sceneryConfigurations
};
