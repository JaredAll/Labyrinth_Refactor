#ifndef INPUT_EVENT_H
#define INPUT_EVENT_H

class InputEvent
{
public:

  InputEvent( bool r_key, int x_input, int y_input );

  int get_x_input();
  int get_y_input();
  bool is_r_pressed();
  
private:
  bool r_pressed;
  int x_input;
  int y_input;
};

#endif
