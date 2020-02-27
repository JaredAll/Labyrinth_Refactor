#include "game_component_factory.h"

GameComponentFactory::GameComponentFactory(
  GameRenderer* gameRenderer,
  SpriteClipper* spriteClipper )
  : renderer( gameRenderer ),
    clipper( spriteClipper )
{
}

Sprite* GameComponentFactory::initialize_sprite(
  uint x,
  uint y,
  std::string resource)
{
  SDL_Texture* sprite_texture =
    renderer -> create_texture( resource );

  Sprite* sprite = new Sprite( x, y, sprite_texture );

  return sprite;
}

Character* GameComponentFactory::create_character( CharacterConfig configuration )
{
  Sprite* body = initialize_sprite(
    configuration.image_x,
    configuration.image_y,
    configuration.sprite_sheet_body );

  vector< SDL_Rect* > walking_clips = clipper -> clip_sprite(
    body,
    configuration.num_walking_sprites );

  Sprite* face = initialize_sprite(
    0,
    0,
    configuration.sprite_sheet_face );

  vector< SDL_Rect* > talking_clips = clipper -> clip_sprite(
    face,
    configuration.num_talking_sprites );

  Character* character = new Character( body,
                                        walking_clips,
                                        face,
                                        talking_clips );
  return character;
}

Scenery* GameComponentFactory::create_scenery( SceneryConfig configuration )
{
  Sprite* sprite = initialize_sprite( configuration.image_x,
                                      configuration.image_y,
                                      configuration.scenery_resource );
  return new Scenery( sprite );
}
