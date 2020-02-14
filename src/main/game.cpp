#include "game.h"

void Game::initialize()
{  
  if (SDL_Init(SDL_INIT_VIDEO) != 0)
  {
    logSDLError( std::cout, "SDL_Init" );
  }

  int window_width = 1000;
  int window_height = 500;
  SDL_Window *win = SDL_CreateWindow("Labyrinth sketch 1",
                                     SDL_WINDOWPOS_CENTERED,
                                     SDL_WINDOWPOS_CENTERED,
                                     window_width, window_height,
                                     SDL_WINDOW_SHOWN);
  if (win == nullptr)
  {
    logSDLError( std::cout, "CreateWindow" );
    SDL_Quit();
  }

  renderer = new GameRenderer( win );
  input_handler = new InputHandler();
}

void Game::render( vector< GameComponent* > components )
{
  renderer -> render( components );
}

void Game::update( vector< GameComponent* > components )
{
  for( uint i = 0; i < components.size(); i++ )
  {
    components.at( i ) -> update();
  }
}

void Game::handle_input()
{
  CharacterState* state = input_handler -> handle_input();
  main_character -> set_state( state );
}

Sprite* Game::initialize_sprite(
  uint x,
  uint y,
  std::string resource)
{
  SDL_Texture* sprite_texture =
    renderer -> create_texture( resource );

  Sprite* sprite = new Sprite( x, y, sprite_texture );

  sprite -> set_position( x, y - sprite -> get_h() );
  
  return sprite;
}

Character* Game::create_main_character( CharacterConfig configuration )
{
  Character* character = create_character( configuration );
  main_character = character;
  return main_character;
}

Character* Game::create_character( CharacterConfig configuration )
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

  return new Character( body,
                        walking_clips,
                        face,
                        talking_clips );
}

