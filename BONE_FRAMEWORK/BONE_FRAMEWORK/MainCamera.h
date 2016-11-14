#pragma once
#include "GameObject.h"
#include "Camera.h"

namespace BONE_FRAMEWORK
{
	class CMainCamera : public CGameObject
	{
	public:
		CMainCamera();
		~CMainCamera();

	public:
		virtual BOOL Initialize();
		virtual VOID Reference();
		virtual VOID Update(double _timeDelta);
		VOID Render(double _timeDelta);
		virtual VOID LateRender(double _timeDelta);

	private:
		CCamera *camera;
	};
}

