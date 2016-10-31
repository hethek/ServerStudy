#include "Common.h"
#include "Texture.h"
#include "RenderManager.h"

namespace BONE_FRAMEWORK
{
	CTexture::CTexture()
	{
		texture = NULL;
		ZeroMemory(&imgInfo, sizeof(imgInfo));
	}


	CTexture::~CTexture()
	{
		Destroy();

	}

	void CTexture::Destroy()
	{
		SAFE_RELEASE(texture);
	}

	INT CTexture::Create(LPTSTR sFile)
	{
		DWORD	dColorKey = 0x00FFFFFF;

		if (FAILED(D3DXCreateTextureFromFileEx(
			GETSINGLE(CRenderManager)->d3dDevice,
			sFile,
			D3DX_DEFAULT,
			D3DX_DEFAULT,
			1,
			0,
			D3DFMT_UNKNOWN,
			D3DPOOL_MANAGED,
			D3DX_FILTER_NONE,
			D3DX_FILTER_NONE,
			dColorKey,
			&imgInfo,
			NULL,
			&texture
			)))
		{
			texture = NULL;
			MessageBoxW(
				GetActiveWindow(),
				_T("Create Texture Failed"),
				_T("Err"),
				MB_ICONEXCLAMATION);

			return -1;
		}

		return 0;
	}

	INT CTexture::GetImageWidth()
	{
		return imgInfo.Width;
	}


	INT CTexture::GetImageHeight()
	{
		return imgInfo.Height;
	}

	void CTexture::GetImageRect(RECT* pRc)
	{
		pRc->left = 0;
		pRc->top = 0;
		pRc->right = imgInfo.Width;
		pRc->bottom = imgInfo.Height;
	}

	LPDIRECT3DTEXTURE9 CTexture::GetTexture()
	{
		return texture;
	}
}