#pragma once
#include "Singleton.h"

namespace BONE_FRAMEWORK
{
	class CRenderManager : public ISingleton<CRenderManager>
	{
	private:
		BOOL showCusor;			// Show Cusor
		BOOL window;			// Window mode

		LPDIRECT3D9				d3d9;			// D3D
		LPDIRECT3DDEVICE9		d3dDevice;		// Device
	public:
		FLOAT fFps;

		LPCWSTR winClassName;

		int winWidth;
		int winHeight;

	public:
		virtual BOOL InitializeMembers();
		virtual BOOL ReleaseMembers();
		
		BOOL Create(HWND hWnd);
		void Cleanup();
		BOOL RenderFrame();// 메시지 루프
	};
}
