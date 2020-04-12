#include "scene_config.h"
#include "grass.h"
#include "sky.h"
#include "doug.h"
#include "lunius.h"
#include "recruit_text_box.h"

#ifndef ORIGIN_CLONE_CONFIG
#define ORIGIN_CLONE_CONFIG

std::vector< CharacterConfig* > cloneCharacterConfigurations = {};
std::vector< SceneryConfig* > cloneSceneryConfigurations = { &sky_config, &grass_config };
std::vector< TextBoxConfig* > cloneTextBoxConfigurations = { & recruit_text_config };

SceneConfig origin_clone_config = {
  &doug_config,
  cloneCharacterConfigurations,
  cloneSceneryConfigurations,
  cloneTextBoxConfigurations,
  -100,
  100
};

#endif
