#include "input_event.h"

InputEvent::InputEvent( bool param_r_pressed, int param_x_input, int param_y_input )
  : x_input( param_x_input ),
    y_input( param_y_input ),
    r_pressed( param_r_pressed )
{}

bool InputEvent::is_r_pressed() const
{
  return r_pressed;
}

int InputEvent::get_x_input() const
{
  return x_input;
}

int InputEvent::get_y_input() const
{
  return y_input;
}
