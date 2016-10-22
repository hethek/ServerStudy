#include "Common.h"
#include "Interface.h"
#include "SceneManager.h"
#include "InputManager.h"
#include "RenderManager.h"
using namespace BONE_FRAMEWORK;

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance
	, LPSTR lpszCmdParam, int nCmdShow)
{
	HWND hWnd = FastCreateWindow(hInstance, "SPACE_WAR", 1280, 1024);


	 //매니저 초기화
	CSceneManager::GetInstance()->InitializeMembers();
	InputManager::GetInstance()->InitializeMembers();
	{
		//SmartPointer<CScene> scene = new CScene();
		//SmartPointer<Player> player = new Player();

		//scene->RegisterGameObjec(*player);

		//CSceneManager::GetInstance()->RegisterScene(*scene, "mainScene");
		//CSceneManager::GetInstance()->Start("mainScene");
	}

	CSceneManager::GetInstance()->ReleaseMembers();
	InputManager::GetInstance()->ReleaseMembers();

	return 0;
}