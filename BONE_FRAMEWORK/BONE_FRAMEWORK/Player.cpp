#include "Common.h"
#include "Player.h"
#include "RenderManager.h"

namespace BONE_FRAMEWORK
{
	CPlayer::CPlayer()
		:mario(NULL)
	{

	}

	CPlayer::~CPlayer()
	{
	}

	BOOL CPlayer::Initialize()
	{
		mario = new CTexture();
		mario->SetType("texture");
		mario->Create(_T("Texture/mario_all.png"));
		mario->GetImageRect(&(mario->imgRect));

		// 마리오를 그린다.
		FLOAT		fX1 = mario->imgInfo.Width / 18.f  * (7 + 0);
		FLOAT		fY1 = mario->imgInfo.Height / 2.f * (0 + 0);

		FLOAT		fX2 = mario->imgInfo.Width / 18.f  * (7 + 1);
		FLOAT		fY2 = mario->imgInfo.Height / 2.f * (0 + 1);

		mario->imgRect = { LONG(fX1), LONG(fY1), LONG(fX2), LONG(fY2) };
		mario->imgPos = D3DXVECTOR3(500, 362, 0);
		
		this->AddComponent(mario);

		return TRUE;
	}

	VOID CPlayer::Reference()
	{

	}

	VOID CPlayer::Update(double _timeDelta)
	{
		//back->SetOriginRect();
	}

	VOID CPlayer::Render(double _timeDelta)
	{
		mario->Render();
	}

	VOID CPlayer::LateRender(double _timeDelta)
	{
		
	}
}