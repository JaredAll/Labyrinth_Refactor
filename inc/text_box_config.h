#ifndef TEXT_BOX_CONFIG
#define TEXT_BOX_CONFIG

struct TextBoxConfig
{
  uint x_pos;
  uint y_pos;
  uint width;
  uint height;
  std::string message;
  const char * font_resource;
  uint font_size;
};

#endif
