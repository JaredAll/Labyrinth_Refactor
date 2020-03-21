#ifndef TEXT_BOX_CONFIG
#define TEXT_BOX_CONFIG

#include <SDL_ttf.h>

struct TextBoxConfig
{
  uint x_pos;
  uint y_pos;
  uint width;
  uint height;
  std::string message;
  TTF_Font* font;
};

#endif
