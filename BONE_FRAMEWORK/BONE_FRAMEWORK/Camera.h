#pragma once
#include "Component.h"

namespace BONE_FRAMEWORK
{
	class CCamera : public CComponent
	{
	public:
		CCamera();
		~CCamera();

	public:
		BOOL Create(LPDIRECT3DDEVICE9 _pDev);
		VOID FrameMove();

	private:

		D3DXMATRIX		mView;
		D3DXMATRIX		mPrj;
		D3DXVECTOR3		vcEye;
		D3DXVECTOR3		vcLook;
		D3DXVECTOR3		vcUp;
	};
}