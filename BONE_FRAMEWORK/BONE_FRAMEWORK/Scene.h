#pragma once
#include "Common.h"
#include "GameObject.h"
#include "SmartPointer.h"

namespace BONE_FRAMEWORK
{
	class CScene
	{
	private:
		std::vector<CGameObject*> objectList;
		std::vector<CGameObject*> staticObjectList;

	public:
		VOID RegisterGameObject(CGameObject* _gameObject, BOOL _isStatic);
		CGameObject* FindObjectByTag(std::string _tag);

		BOOL InitializeMembers();
		BOOL LoadContents();

		VOID Reference();
		VOID Update(double _timeDelta);

		VOID Render(double _timeDelta);
		VOID LateRender(double _timeDelta);

		BOOL ReleaseMembers();
	};
}