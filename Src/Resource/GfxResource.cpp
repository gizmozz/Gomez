#include <SDL2/SDL_image.h>

#include "GfxResource.h"
#include "../GameStd.h"

GfxResource::GfxResource(const std::string &fileName):
m_pSurface(NULL),
m_fileName(fileName)
{
}

GfxResource::~GfxResource()
{
	if(m_pSurface)
	{
		SDL_FreeSurface(m_pSurface);
		m_pSurface = NULL;
	}
}

bool GfxResource::VLoad()
{
	if(m_pSurface)
	{
		ERROR("GfxResource \"" << m_fileName << "\" already loaded");
		return false;
	}
	
	if((m_pSurface = IMG_Load(m_fileName.c_str())) == NULL)
	{
		ERROR("Failed to load \"" << m_fileName << "\"");
		return false;
	}
	
	return true;
}

const SDL_Texture* GfxResource::GetTexture(SDL_Renderer *pRenderer) const
{	
	SDL_Texture *pTexture = SDL_CreateTextureFromSurface(pRenderer, m_pSurface);
	
	if(!pTexture)
	{
		ERROR("Failed to create texture from file \"" << m_fileName << "\"");
		return NULL;
	}
	
	return pTexture;
}
