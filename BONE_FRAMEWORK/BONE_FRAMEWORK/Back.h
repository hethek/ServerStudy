#pragma once
#include "GameObject.h"
#include "Texture.h"

namespace BONE_FRAMEWORK
{
	class CBack : public CGameObject
	{
	public:
		CBack();
		~CBack();

	public:
		virtual BOOL Initialize();
		virtual VOID Reference();
		virtual VOID Update(double _timeDelta);
		VOID Render(double _timeDelta);
		virtual VOID LateRender(double _timeDelta);

	private:
		CTexture *back;
	};
}