#pragma once
#include "Component.h"

namespace BONE_FRAMEWORK 
{
	class CTexture : public CComponent
	{
	public:
		CTexture();
		~CTexture();

	public:
		INT		Create(LPTSTR sFile);
		VOID	Render();
		void	Destroy();

	public:
		INT		GetImageWidth();
		INT		GetImageHeight();
		void	GetImageRect(RECT* pRc);
		LPDIRECT3DTEXTURE9	GetTexture();

	public:
		D3DXIMAGE_INFO		imgInfo;
		LPDIRECT3DTEXTURE9	texture;

		RECT		imgRect;
		D3DXVECTOR3 imgPos;
	};
}

