#pragma once

namespace BONE_FRAMEWORK 
{
	class CTexture
	{
	public:
		CTexture();
		~CTexture();

		LPDIRECT3DDEVICE9	m_pDev;
		D3DXIMAGE_INFO		m_Img;
		LPDIRECT3DTEXTURE9	m_pTx;

		RECT			m_lmgRect;

	public:
		INT		Create(LPDIRECT3DDEVICE9 pDev, LPTSTR sFile);
		void	Destroy();

	public:
		INT		GetImageWidth();
		INT		GetImageHeight();
		void	GetImageRect(RECT* pRc);

		LPDIRECT3DTEXTURE9	GetTexture();
	};
}

