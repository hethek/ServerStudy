#include "Camera.h"
#include "RenderManager.h"

namespace BONE_FRAMEWORK
{
	CCamera::CCamera()
	{
	}


	CCamera::~CCamera()
	{
	}

	BOOL CCamera::Create(LPDIRECT3DDEVICE9 pDev)
	{
		pDev = pDev;
		vcEye = D3DXVECTOR3(0, 0, -10);
		vcLook = D3DXVECTOR3(0, 0, 0);
		vcUp = D3DXVECTOR3(0, -1, 0);

		D3DXMatrixPerspectiveFovLH(&mPrj, D3DX_PI / 4.f, 800.f / 600.f, 1.f, 5000.f);
		D3DXMatrixLookAtLH(&mView, &vcEye, &vcLook, &vcUp);

		return TRUE;
	}

	VOID CCamera::FrameMove()
	{
	}
		
}