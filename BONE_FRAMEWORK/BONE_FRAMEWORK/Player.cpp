#include "Common.h"
#include "Player.h"
#include "RenderManager.h"

namespace BONE_FRAMEWORK
{
	CPlayer::CPlayer()
	{
	}


	CPlayer::~CPlayer()
	{
	}

	BOOL CPlayer::Initialize()
	{
		back = new CTexture;
		if (FAILED(back->Create(_T("Texture/mario_back.png"))))
			return -1;

		back->GetImageRect(&(back->imgRect));

		return TRUE;
	}

	VOID CPlayer::Reference()
	{

	}

	VOID CPlayer::Update(double _timeDelta)
	{

	}

	VOID CPlayer::Render(double _timeDelta)
	{
	}

	VOID CPlayer::LateRender(double _timeDelta)
	{
		GETSINGLE(CRenderManager)->d3dSprite->Draw(back->GetTexture()
			, &(back->imgRect)
			, NULL
			, NULL
			, D3DXCOLOR(1, 1, 1, 1));
	}
}