#pragma once
#include "Common.h"
#include "Singleton.h"
#include "Scene.h"

namespace BONE_FRAMEWORK
{
	class CSceneManager : public ISingleton<CSceneManager>
	{
	private:
		std::map<std::string, CScene*> sceneList;
		std::string currentScene;
		
		double timeDelta;
		BOOL endFlag;

	public:
		virtual BOOL InitializeMembers();
		virtual BOOL ReleaseMembers();

		CScene* GetCurrentScene();

		VOID EndScene();
		VOID RegisterScene(CScene* _scene, std::string _name);

		double GetTimeDelta();

		BOOL Start(std::string _name);
	};
}

