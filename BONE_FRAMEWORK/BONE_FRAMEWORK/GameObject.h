#pragma once
#include "Common.h"
#include "Component.h"

namespace BONE_FRAMEWORK
{
	class CGameObject abstract
	{
	private:
		std::string tag;
		BOOL isActive;
		BOOL isStatic;

		std::vector<CComponent*> components;

	public:
		CGameObject(VOID);
		~CGameObject(VOID);

	public:
		VOID SetTag(std::string _tag);
		std::string GetTag();

		BOOL AddComponent(CComponent* _component);
		CComponent* GetComponent(std::string _typeName);

	public:
		virtual BOOL Initialize();
		BOOL LoadContents();

		virtual VOID Reference();	//LoadContents가 끝나고 참조할 때 사용
		virtual VOID Update(double _timeDelta);
		VOID Render(double _timeDelta);
		virtual VOID LateRender(double _timeDelta);

		BOOL Release();

	public:
		BOOL GetActive();
		VOID SetActive(BOOL _isActive);
	};
}