#include "scenery_config.h"

#ifndef SKY_CONFIG
#define SKY_CONFIG

int sky_x = 0;
int sky_y = 0;

std::string sky_resource = "/home/jared/Games/Labyrinth/resources/sprites/sky.png";

int sky_repititions = 5;

SceneryConfig sky_config = {
  sky_x, sky_y, sky_resource, sky_repititions
};

#endif
