#include "Common.h"
#include "Interface.h"
#include "RenderManager.h"

namespace BONE_FRAMEWORK
{
	BOOL CRenderManager::InitializeMembers()
	{
		d3d9 = NULL;		
		d3dDevice = NULL;		
		d3dSprite = NULL;		

		return TRUE;
	}

	BOOL CRenderManager::ReleaseMembers()
	{
		return TRUE;
	}

	BOOL CRenderManager::Create(HWND hWnd)
	{
		// D3D생성
		if (NULL == (d3d9 = Direct3DCreate9(D3D_SDK_VERSION)))
			return FALSE;

		// D3D장치를 생성하는데 필요한 구조체를 채워넣는다.
		D3DPRESENT_PARAMETERS	d3dPP;
		ZeroMemory(&d3dPP, sizeof(d3dPP));

		RECT ClientRect;
		GetClientRect(hWnd, &ClientRect);

		int width = ClientRect.right;
		int height = ClientRect.bottom;

		d3dPP.BackBufferWidth = width;
		d3dPP.BackBufferHeight = height;
		d3dPP.BackBufferFormat = D3DFMT_A8R8G8B8;
		d3dPP.BackBufferCount = 1;
		d3dPP.MultiSampleType = D3DMULTISAMPLE_NONE;
		d3dPP.MultiSampleQuality = 0;
		d3dPP.SwapEffect = D3DSWAPEFFECT_DISCARD;
		d3dPP.hDeviceWindow = hWnd;
		d3dPP.Windowed = true;
		d3dPP.EnableAutoDepthStencil = true;
		d3dPP.AutoDepthStencilFormat = D3DFMT_D24S8;
		d3dPP.Flags = 0;
		d3dPP.FullScreen_RefreshRateInHz = D3DPRESENT_RATE_DEFAULT;
		d3dPP.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;

		int vp = FAILED(d3d9->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd,
			D3DCREATE_HARDWARE_VERTEXPROCESSING,
			&d3dPP, &d3dDevice));

		// D3D장치를 생성한다.
		if (vp != S_OK)
		{
			return E_FAIL;
		}

		// DX의 스프라이트는 디바이스가 생성된 후에 만들어야 한다.
		if (FAILED(D3DXCreateSprite(d3dDevice, &d3dSprite)))
		{
			SAFE_RELEASE(d3dDevice);
			SAFE_RELEASE(d3dSprite);
			return -1;
		}

		return TRUE;
	}

	void CRenderManager::Cleanup()
	{
		SAFE_RELEASE(d3dSprite);
		SAFE_RELEASE(d3dDevice);
		SAFE_RELEASE(d3d9);
	}

	BOOL CRenderManager::RenderStatr()
	{
		d3dDevice->Clear(
			0, 
			NULL, 
			(D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER),
			D3DCOLOR_XRGB(0, 120, 160), 
			1.0f, 0);

		d3dDevice->BeginScene();

		d3dSprite->Begin(D3DXSPRITE_ALPHABLEND);

		return TRUE;
	}

	void CRenderManager::RenderEnd()
	{
		d3dSprite->End();

		d3dDevice->EndScene();

		d3dDevice->Present(NULL, NULL, NULL, NULL);
	}
}
