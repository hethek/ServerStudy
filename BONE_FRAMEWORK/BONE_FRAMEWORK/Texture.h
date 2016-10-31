#pragma once

namespace BONE_FRAMEWORK 
{
	class CTexture
	{
	public:
		D3DXIMAGE_INFO		imgInfo;
		LPDIRECT3DTEXTURE9	texture;

		RECT imgRect;

	public:
		INT		Create(LPTSTR sFile);
		void	Destroy();

	public:
		INT		GetImageWidth();
		INT		GetImageHeight();
		void	GetImageRect(RECT* pRc);

	public:
		CTexture();
		~CTexture();

		LPDIRECT3DTEXTURE9	GetTexture();
	};
}

