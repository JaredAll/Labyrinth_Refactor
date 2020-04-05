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

  TextBox* recruit_text_box;
  for( TextBoxConfig* textBoxConfig : configuration.textBoxConfigurations )
  {
    recruit_text_box = create_text_box( *textBoxConfig );
    camera_components.push_back( recruit_text_box );
  }

  for( Character* character : characters )
  {
    character -> switch_state( new RecruitableState( main_character,
                                                     recruit_text_box ) );
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

TextBox* GameComponentFactory::create_text_box( TextBoxConfig configuration )
{
  SDL_Rect* displayBox = new SDL_Rect();
  displayBox -> x = configuration.x_pos;
  displayBox -> y = configuration.y_pos;
  displayBox -> h = configuration.height;
  displayBox -> w = configuration.width;

  vector< SDL_Rect* > letter_slots = create_letter_slots( configuration.message,
                                                          displayBox );


  TTF_Font* font = initialize_font( configuration.font_resource, configuration.font_size );

  vector< SDL_Texture* > letter_textures = create_letter_textures( configuration.message,
                                                                   font );

  vector< Glyph* > letters;
  for( uint letter = 0; letter < letter_slots.size(); letter++ )
  {
    letters.push_back( new Glyph( letter_slots.at( letter ), letter_textures.at( letter ) ) );
  }

  return new TextBox( letters );
}

TTF_Font* GameComponentFactory::initialize_font( const char* resource, uint size )
{
  TTF_Font* font = TTF_OpenFont( resource, size );

  if( font == NULL )
  {
    printf( "Unable to render text surface! SDL_ttf Error: %s\n",
            TTF_GetError() );
  }
  return font;
}

vector< SDL_Rect* > GameComponentFactory::create_letter_slots( string message,
                                                               SDL_Rect* displayBox )
{
  uint height = displayBox -> h;
  uint width = displayBox -> w;
  uint x_pos = displayBox -> x;
  uint y_pos = displayBox -> y;
  
  uint thin_letter_divisor = 10;
  uint letter_divisor = 6;
  uint next_x = 0;
  uint next_y = y_pos;
  uint lines_per_box = 3;
  uint line_padding = 5;

  vector< SDL_Rect* > letter_slots;
  for( uint letter = 0; letter < message.length(); letter++ )
  {
    SDL_Rect *letter_slot = new SDL_Rect();
    uint letter_width;
    if( message.at( letter ) == 'i' ||
        message.at( letter ) == 'l' ||
        message.at( letter ) == 'I' ||
        message.at( letter ) == ' ' )
    {
      letter_width = height / thin_letter_divisor;
    }
    else
    {
      letter_width = height / letter_divisor;
    }

    if( next_x > width && message.at( letter - 1 ) == ' ' )
    {
      next_y = next_y + (height / lines_per_box ) + line_padding;
      next_x = 0; 
    }

    letter_slot -> x = x_pos + next_x;
    letter_slot -> y = next_y;
    letter_slot -> h = height / lines_per_box;
    letter_slot -> w = letter_width;
    
    letter_slots.push_back( letter_slot );

    next_x += letter_width;
  }

  return letter_slots;
}

vector< SDL_Texture* > GameComponentFactory::create_letter_textures( string message,
                                                                     TTF_Font* font )
{
  vector< SDL_Texture* > letter_textures;
  
  char message_array[ 100 ];
  strcpy( message_array, message.c_str() );
  SDL_Color color = {0, 0, 0};

  for( uint i = 0; i < message.length(); i++ )
  {
    char letter_singleton[ 2 ] = { message_array[ i ], '\0' };

    SDL_Texture* letter_texture =
      renderer -> render_letter_texture( font, letter_singleton, color );

    letter_textures.push_back( letter_texture );
  }
  return letter_textures;
}
  
