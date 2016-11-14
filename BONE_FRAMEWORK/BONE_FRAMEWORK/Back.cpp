#include "Common.h"
#include "Back.h"

namespace BONE_FRAMEWORK
{
	CBack::CBack()
		:back(NULL)
	{
	}


	CBack::~CBack()
	{

	}

	BOOL CBack::Initialize()
	{
		back = new CTexture();
		back->SetType("texture");
		back->Create(_T("Texture/mario_back.png"));
		back->GetImageRect(&(back->imgRect));
		this->AddComponent(back);

		return TRUE;
	}

	VOID CBack::Reference()
	{

	}

	VOID CBack::Update(double _timeDelta)
	{
		//back->SetOriginRect();
	}

	VOID CBack::Render(double _timeDelta)
	{
		back->Render();
	}

	VOID CBack::LateRender(double _timeDelta)
	{

	}
}