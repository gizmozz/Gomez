#ifndef GFXRECT_H
#define GFXRECT_H

#include "GfxElement.h"

class GfxRect : public GfxElement
{
	private :
	
		float m_width, m_height;
	
	public :
	
		GfxRect(int layer);
		GfxRect(int layer, float posX, float posY);
		~GfxRect();
	
		virtual bool VInit(SDL_Renderer *pRenderer);
		virtual void VRender(SDL_Renderer* pRenderer);
		virtual bool VIsVisible() const;
		
		void SetDimensions(float w, float h);
		float GetWidth() const{ return m_width; }
		float GetHeight() const{ return m_height; }
};

#endif
