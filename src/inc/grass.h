#include "scenery_config.h"

#ifndef GRASS_CONFIG
#define GRASS_CONFIG

int grass_x = 0;
int grass_y = 0;

std::string grass_resource = "/home/jared/Games/Labyrinth/resources/sprites/grass1.png";

int repititions = 5;

SceneryConfig grass_config = {
  grass_x, grass_y, grass_resource, repititions
};

#endif
