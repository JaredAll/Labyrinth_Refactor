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

  TTF_Init();

  clipper = new SpriteClipper();
  renderer = new GameRenderer( win );
  input_handler = new InputHandler();
  gameComponentFactory = new GameComponentFactory( renderer, clipper );

  speed = 2;
}

void Game::set_components( vector< GameComponent* > param_components )
{
  components = param_components;
}

void Game::render()
{
  renderer -> render( components );
}

void Game::update( InputEvent* event )
{
  update_game_state();
  for( uint i = 0; i < components.size(); i++ )
  {
    components.at( i ) -> update( event );
  }
}

void Game::update_game_state()
{
  GameState* next_state = state -> update();
  if( next_state != state )
  {
    state = next_state;
    components.clear();
    state -> get_scene() -> load_into_game( this );
  }
}

InputEvent* Game::handle_input()
{
  return input_handler -> handle_input();
}

void Game::add_component( GameComponent* gameComponent )
{
  components.push_back( gameComponent );
}

void Game::play()
{
  uint frames_per_second = 60;
  uint milliseconds = 1000 / frames_per_second;

  while( true )
  {
    InputEvent* event = handle_input();
    update( event );
    render();
    free( event );
    usleep( milliseconds * 1000 );
  }
}

uint Game::get_speed()
{
  return speed;
}

void Game::set_state( GameState* state )
{
  this -> state = state;
  state -> get_scene() -> load_into_game( this );
}

Scene* Game::create_scene( SceneConfig configuration )
{
  return gameComponentFactory -> create_scene( configuration );
}

void Game::load_scene( SceneConfig configuration )
{
  Scene* scene = gameComponentFactory -> create_scene( configuration );
  scene -> load_into_game( this );
}

Character* Game::create_character( CharacterConfig configuration )
{
  return gameComponentFactory -> create_character( configuration );
}

Scenery* Game::create_scenery( SceneryConfig configuration )
{
  return gameComponentFactory -> create_scenery( configuration );
}

TextBox* Game::create_text_box( TextBoxConfig configuration )
{
  return gameComponentFactory -> create_text_box( configuration );
}
