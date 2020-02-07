#include "game_renderer.h"

GameRenderer::GameRenderer( SDL_Window* win )
{
  SDL_Renderer *ren =
    SDL_CreateRenderer(win, -1,
                       SDL_RENDERER_ACCELERATED
                       | SDL_RENDERER_PRESENTVSYNC);
  if (ren == nullptr)
  {
    cleanup( win );
    logSDLError( std::cout, "CreateRenderer" );
    SDL_Quit();
  }
  renderer = ren;
}

void GameRenderer::render( std::vector<RenderComponent*> renderComponents )
{
  SDL_RenderClear( renderer );
  for( uint i = 0; i < renderComponents.size(); i++ )
  {
    render( renderComponents.at( i ) );
  }
  SDL_RenderPresent( renderer );
}

SDL_Texture* GameRenderer::create_texture( std::string image_path )
{
  return loadTexture( image_path, renderer );
}

void GameRenderer::render( RenderComponent* renderComponent )
{
  SDL_Texture* texture = renderComponent -> getTexture();
  SDL_Rect* destination = renderComponent -> getDestination();
  SDL_Rect* source = renderComponent -> getClip();

  renderTexture( texture, renderer, destination, source );
}
