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


	BOOL CCamera::Create()
	{
		D3DXMatrixIdentity(&identityMatrix);

		D3DXMatrixOrthoOffCenterLH(&projMatrix, 0, 800, 0, 600, 0.0f, 1.0f);

		GETSINGLE(CRenderManager)->d3dDevice->SetTransform(D3DTS_PROJECTION, &projMatrix);
		GETSINGLE(CRenderManager)->d3dDevice->SetTransform(D3DTS_WORLD, &identityMatrix);

		return TRUE;
	}

	VOID CCamera::FollowPlayer(CTexture *player)
	{

		identityMatrix._41 = player->imgPos.x - 400;
		identityMatrix._42 = player->imgPos.y - 300;
		identityMatrix._43 = player->imgPos.z;

		D3DXMatrixInverse(&viewMatrix, 0, &identityMatrix);

		GETSINGLE(CRenderManager)->d3dDevice->SetTransform(D3DTS_VIEW, &viewMatrix);
	}
}