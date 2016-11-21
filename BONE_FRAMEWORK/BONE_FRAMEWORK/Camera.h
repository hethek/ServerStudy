#pragma once
#include "Component.h"
#include "Texture.h"

namespace BONE_FRAMEWORK
{
	class CCamera : public CComponent
	{
	public:
		CCamera();
		~CCamera();

	public:
		BOOL Create();
		VOID FollowPlayer(CTexture *player);

	private:
		D3DXMATRIX		viewMatrix;
		D3DXMATRIX		identityMatrix;
		D3DXMATRIX		projMatrix;

		D3DXVECTOR3		eyeVector;
		D3DXVECTOR3		lookVector;
		D3DXVECTOR3		upVector;
	};
}