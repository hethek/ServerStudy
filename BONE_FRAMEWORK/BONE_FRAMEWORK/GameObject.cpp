#include "GameObject.h"

namespace BONE_FRAMEWORK
{

	CGameObject::CGameObject(VOID)
	{
		tag = "";
		isActive = TRUE;
	}

	CGameObject::~CGameObject(VOID)
	{
		Release();
	}

	VOID CGameObject::SetTag(std::string _tag)
	{
		tag = _tag;
	}

	std::string CGameObject::GetTag()
	{
		return tag;
	}

	BOOL CGameObject::AddComponent(CComponent* _component)
	{
		if (_component == NULL)
			return FALSE;

		components.push_back(_component);

		return TRUE;
	}

	CComponent* CGameObject::GetComponent(std::string _typeName)
	{
		for (auto iter = components.begin(); iter != components.end(); iter++)
		{
			if ((*iter)->GetType() == _typeName)
				return (*iter);
		}

		return NULL;
	}

	BOOL CGameObject::Initialize()
	{
		return TRUE;
	}

	BOOL CGameObject::LoadContents()
	{
		for (auto iter = components.begin(); iter != components.end(); iter++)
		{
			//if ((*iter)->GetType() == "CTexture")
				//(*iter)->LoadContent;
		}

		return TRUE;
	}

	VOID CGameObject::Reference()
	{

	}

	VOID CGameObject::Update(double _timeDelta)
	{

	}

	VOID CGameObject::Render(double _timeDelta)
	{
		if (!isActive)
			return;

		for (auto iter = components.begin(); iter != components.end(); iter++)
		{
			if ((*iter)->GetType() == "texture")
			{
				(*iter)->Render();
			}
		}
	}

	VOID CGameObject::LateRender(double _timeDelta)
	{
		if (!isActive)
			return;
	}

	BOOL CGameObject::Release()
	{
		for (auto iter = components.begin(); iter != components.end(); iter++)
		{
			delete *iter;
		}

		components.clear();
		
		return TRUE;
	}

	BOOL CGameObject::GetActive()
	{
		return isActive;
	}
	
	VOID CGameObject::SetActive(BOOL _isActive)
	{
		isActive = _isActive;
	}
}