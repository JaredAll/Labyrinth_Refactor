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

Scene* GameComponentFactory::create_scene( SceneConfig configuration )
{
  Character* main_character = create_character( *configuration.main_character_config );
  main_character -> set_main_character( true );

  vector< GameComponent* > camera_components;
  vector< Character* > characters;
  for( CharacterConfig* characterConfig : configuration.characterConfigurations )
  {
    Character* character = create_character( *characterConfig );
    camera_components.push_back( character );
    characters.push_back( character );
  }

  for( SceneryConfig* sceneryConfig : configuration.sceneryConfigurations )
  {
    camera_components.push_back( create_scenery( *sceneryConfig ) );
  }

  Camera* camera = new Camera( camera_components );

  return new Scene( camera, main_character, characters );
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
  vector< Sprite* > sprites;
  for( uint i = 0; i < configuration.horizontal_repititions; i++ )
  {
    Sprite* sprite = initialize_sprite( configuration.image_x,
                                        configuration.image_y,
                                        configuration.scenery_resource );

    sprite -> set_x( sprite -> get_x() + i * sprite -> get_w() );

    sprites.push_back( sprite );
  }

  return new Scenery( sprites );
}
