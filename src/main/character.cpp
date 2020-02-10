#include "character.h"

Character::Character( Sprite* body,
                      vector< SDL_Rect* > walking_clips_param,
                      Sprite* face,
                      vector< SDL_Rect* > talking_clips_param )
  : walking_clips( walking_clips_param ), talking_clips( talking_clips_param )
{
  x_pos = 0;
  y_pos = 0;
  stride = 1;
  facing_left = false;
  recruited = false;
  current_clip = walking_clips.at( 0 );

  setRenderComponent( body );
}

RenderComponent* Character::get_render_component()
{
  return renderComponent;
}

void Character::setRenderComponent( RenderComponent* renderComponent )
{
  this -> renderComponent = renderComponent;
  renderComponent -> set_clip( current_clip );
  renderComponent -> calculate_destination();
}

void Character::update()
{
  stride = ( stride + 1 ) % walking_clips.size();
  current_clip = walking_clips.at( stride );
  renderComponent -> set_clip( current_clip );
}
