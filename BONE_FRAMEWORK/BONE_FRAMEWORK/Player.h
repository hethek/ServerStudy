#pragma once
#include "GameObject.h"
#include "Texture.h"
#include "Camera.h"

namespace BONE_FRAMEWORK
{
	class CPlayer : public CGameObject
	{
	public:
		CPlayer();
		~CPlayer();

	public:
		virtual BOOL Initialize();
		virtual VOID Reference();
		virtual VOID Update(double _timeDelta);
		virtual VOID LateRender(double _timeDelta);

	private:
		CTexture *mario;
		CCamera *camera;
	};
}

