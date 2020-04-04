#include "text_box_config.h"

uint recruit_text_x = 300;
uint recruit_text_y = 400;
uint recruit_text_w = 100;
uint recruit_text_h = 100;
std::string recruit_text_message = "R to recruit";
const char * recruit_text_font = "/home/jared/Games/Labyrinth/resources/OpenSans-Bold.ttf";
uint recruit_text_font_size = 16;

TextBoxConfig recruit_text_config = {
  recruit_text_x,
  recruit_text_y,
  recruit_text_w,
  recruit_text_h,
  recruit_text_message,
  recruit_text_font,
  recruit_text_font_size
};
