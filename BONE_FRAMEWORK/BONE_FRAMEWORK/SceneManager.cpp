#include "SceneManager.h"

namespace BONE_FRAMEWORK
{
	BOOL CSceneManager::InitializeMembers()
	{
		timeDelta = 0;
		endFlag = FALSE;

		return TRUE;
	}

	BOOL CSceneManager::ReleaseMembers()
	{
		sceneList.clear();

		return TRUE;
	}

	CScene* CSceneManager::GetCurrentScene()
	{
		auto iter = sceneList.find(currentScene);

		if (iter != sceneList.end())
			return iter->second;

		return NULL;
	}

	VOID CSceneManager::EndScene()
	{
		endFlag = TRUE;
	}

	VOID CSceneManager::RegisterScene(CScene* _scene, std::string _name)
	{
		sceneList.insert(std::make_pair(_name, _scene));
	}

	double CSceneManager::GetTimeDelta()
	{
		return timeDelta;
	}

	BOOL CSceneManager::Start(std::string _name)
	{
		currentScene = _name;

		if (!sceneList[_name]->InitializeMembers())
			return FALSE;

		if (!sceneList[_name]->LoadContents())
			return FALSE;

		double lastTime = (double)timeGetTime();;

		while (!endFlag)
		{
			double curTime = (double)timeGetTime();
			timeDelta = (lastTime - curTime) / 1000;

			sceneList[_name]->Update(timeDelta);
			sceneList[_name]->Render(timeDelta);
			sceneList[_name]->LateRender(timeDelta);

			lastTime = (double)timeGetTime();
		}

		sceneList[_name]->ReleaseMembers();
		endFlag = FALSE;
	}
}