#pragma once
#include "Singleton.h"

namespace BONE_FRAMEWORK
{
	class CRenderManager : public ISingleton<CRenderManager>
	{
	public:
		BOOL showCusor;			// Show Cusor
		BOOL window;			// Window mode

		LPDIRECT3D9				d3d9;			// D3D
		LPDIRECT3DDEVICE9		d3dDevice;		// Device
		LPD3DXSPRITE			d3dSprite;		// Sprite

		FLOAT fFps;

		LPCWSTR winClassName;

		int winWidth;
		int winHeight;

	public:
		BOOL Create(HWND hWnd);
		void Cleanup();
		BOOL RenderStatr();					// 메시지 루프
		void RenderEnd();					// 메시지 루프

	public:
		virtual BOOL InitializeMembers();
		virtual BOOL ReleaseMembers();
	
	};
}
