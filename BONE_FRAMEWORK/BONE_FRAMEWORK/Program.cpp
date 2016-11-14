#include "Common.h"
#include "Interface.h"
#include "SmartPointer.h"
#include "SceneManager.h"
#include "InputManager.h"
#include "RenderManager.h"
#include "Player.h"
#include "Back.h"
#include "MainCamera.h"

using namespace BONE_FRAMEWORK;

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance
	, LPSTR lpszCmdParam, int nCmdShow)
{

	HWND hWnd;
	FastCreateWindow(hInstance, hWnd, "asd", 800, 600);

	//int a = GetLastError();

	//�Ŵ��� �ʱ�ȭ
	GETSINGLE(CRenderManager)->InitializeMembers();
	GETSINGLE(CSceneManager)->InitializeMembers();
	{
		//����̽� ���
		if (GETSINGLE(CRenderManager)->Create(hWnd))
			FALSE;

		//���� ������Ʈ
		SmartPointer<CBack> back;

		SmartPointer<CPlayer> player;

		SmartPointer<CMainCamera> mainCamera;

		//�� ���
		SmartPointer<CScene> scene;
		scene->RegisterGameObject(back, false);
		scene->RegisterGameObject(player, false);
		scene->RegisterGameObject(mainCamera, false);

		GETSINGLE(CSceneManager)->RegisterScene(scene, "mainScene");
		GETSINGLE(CSceneManager)->Start("mainScene");
	}
	GETSINGLE(CRenderManager)->ReleaseMembers();
	GETSINGLE(CSceneManager)->ReleaseMembers();

	return 0;
}

