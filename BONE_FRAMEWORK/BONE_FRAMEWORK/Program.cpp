#include "Common.h"
#include "Interface.h"
#include "SmartPointer.h"
#include "SceneManager.h"
#include "InputManager.h"
#include "RenderManager.h"
#include "Player.h"
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

		//������Ʈ

		//���� ������Ʈ
		SmartPointer<CPlayer> player;
		player->Initialize();

		//�� ���
		SmartPointer<CScene> scene;
		scene->RegisterGameObject(player, false);

		GETSINGLE(CSceneManager)->RegisterScene(scene, "mainScene");
		GETSINGLE(CSceneManager)->Start("mainScene");
	}
	GETSINGLE(CRenderManager)->ReleaseMembers();
	GETSINGLE(CSceneManager)->ReleaseMembers();

	return 0;
}

