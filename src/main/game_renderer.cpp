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

void GameRenderer::render( std::vector< GameComponent* > gameComponents )
{
  SDL_RenderClear( renderer );
  for( uint i = 0; i < gameComponents.size(); i++ )
  {
    vector< RenderComponent* > subRenderComponents =
      gameComponents.at( i ) -> get_render_components();

    for( uint j = 0; j < subRenderComponents.size(); j++ )
    {
      render( subRenderComponents.at( j ) );
    }
  }

  SDL_RenderPresent( renderer );
}

SDL_Texture* GameRenderer::create_texture( std::string image_path )
{
  return loadTexture( image_path, renderer );
}

SDL_Texture* GameRenderer::render_letter_texture( TTF_Font* font,
                                                  char letter_singleton[],
                                                  SDL_Color color )
{
  SDL_Surface *letter_surface = TTF_RenderText_Solid( font, letter_singleton, color );
  SDL_Texture *letter_texture = SDL_CreateTextureFromSurface( renderer, letter_surface );
  cleanup( letter_surface );
  return letter_texture;
}

void GameRenderer::render( RenderComponent* renderComponent )
{
  SDL_Texture* texture = renderComponent -> getTexture();
  SDL_Rect* destination = renderComponent -> getDestination();
  SDL_Rect* source = renderComponent -> getClip();

  if( renderComponent -> is_flipped() )
  {
    renderTextureFlip( texture, renderer, destination, source );
  }
  else
  {
    renderTexture( texture, renderer, destination, source ); 
  }
}
