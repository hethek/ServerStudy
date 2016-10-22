#include "Common.h"
#include "Scene.h"

namespace BONE_FRAMEWORK
{
	VOID CScene::RegisterGameObject(CGameObject* _gameObject, BOOL _isStatic)
	{
		if (_isStatic)
			staticObjectList.push_back(_gameObject);
		else
			objectList.push_back(_gameObject);
	}

	CGameObject* CScene::FindObjectByTag(std::string _tag)
	{
		for (auto iter = objectList.begin(); iter != objectList.end(); iter++)
		{
			if ((*iter)->GetTag() == _tag)
				return (*iter);
		}

		for (auto iter = staticObjectList.begin(); iter != staticObjectList.end(); iter++)
		{
			if ((*iter)->GetTag() == _tag)
				return (*iter);
		}

		return NULL;
	}

	BOOL CScene::InitializeMembers()
	{
		for (auto iter = objectList.begin(); iter != objectList.end(); iter++)
		{
			if ((*iter)->Initialize() == FALSE)
				return FALSE;
		}

		for (auto iter = staticObjectList.begin(); iter != staticObjectList.end(); iter++)
		{
			if ((*iter)->Initialize() == FALSE)
				return FALSE;
		}

		return TRUE;
	}

	BOOL CScene::LoadContents()
	{
		for (auto iter = objectList.begin(); iter != objectList.end(); iter++)
		{
			if ((*iter)->LoadContents() == FALSE)
				return FALSE;
		}

		for (auto iter = staticObjectList.begin(); iter != staticObjectList.end(); iter++)
		{
			if ((*iter)->LoadContents() == FALSE)
				return FALSE;
		}

		return TRUE;
	}

	VOID CScene::Reference()	//LoadContents가 끝나고 참조할 때 사용
	{
		for (auto iter = objectList.begin(); iter != objectList.end(); iter++)
		{
			(*iter)->Reference();
		}

		for (auto iter = staticObjectList.begin(); iter != staticObjectList.end(); iter++)
		{
			(*iter)->Reference();
		}
	}

	VOID CScene::Update(double _timeDelta)
	{
		for (auto iter = objectList.begin(); iter != objectList.end(); iter++)
		{
			if ((*iter)->GetActive())
				(*iter)->Update(_timeDelta);
		}

		for (auto iter = staticObjectList.begin(); iter != staticObjectList.end(); iter++)
		{
			if ((*iter)->GetActive())
				(*iter)->Update(_timeDelta);
		}

	}

	VOID CScene::Render(double _timeDelta)
	{
		for (auto iter = objectList.begin(); iter != objectList.end(); iter++)
		{
			if ((*iter)->GetActive())
				(*iter)->Render(_timeDelta);
		}

		for (auto iter = staticObjectList.begin(); iter != staticObjectList.end(); iter++)
		{
			if ((*iter)->GetActive())
				(*iter)->Render(_timeDelta);
		}
	}

	VOID CScene::LateRender(double _timeDelta)
	{
		for (auto iter = objectList.begin(); iter != objectList.end(); iter++)
		{
			if ((*iter)->GetActive())
				(*iter)->LateRender(_timeDelta);
		}

		for (auto iter = staticObjectList.begin(); iter != staticObjectList.end(); iter++)
		{
			if ((*iter)->GetActive())
				(*iter)->LateRender(_timeDelta);
		}
	}

	BOOL CScene::ReleaseMembers()
	{
		for (auto iter = objectList.begin(); iter != objectList.end(); iter++)
		{
			if ((*iter)->Release() == FALSE)
				return FALSE;
		}

		for (auto iter = staticObjectList.begin(); iter != staticObjectList.end(); iter++)
		{
			if ((*iter)->Release() == FALSE)
				return FALSE;
		}

		return TRUE;
	}
}