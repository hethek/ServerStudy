#include "Common.h"
#include "MainCamera.h"
#include "RenderManager.h"
namespace BONE_FRAMEWORK
{
	CMainCamera::CMainCamera()
		:camera(NULL)
	{
	}


	CMainCamera::~CMainCamera()
	{
	}

	BOOL CMainCamera::Initialize()
	{
		camera = new CCamera();
		camera->SetType("camera");
		camera->Create(GETSINGLE(CRenderManager)->d3dDevice);

		return TRUE;
	}

	VOID CMainCamera::Reference()
	{

	}

	VOID CMainCamera::Update(double _timeDelta)
	{
		//camera->FrameMove();
	}

	VOID CMainCamera::Render(double _timeDelta)
	{
	}

	VOID CMainCamera::LateRender(double _timeDelta)
	{

	}
}