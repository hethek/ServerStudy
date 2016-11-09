#pragma once
#include "Common.h"
#include "Singleton.h"

typedef struct Vector2 {
	float x;
	float y;
	float z;
} Vector2;

namespace BONE_FRAMEWORK
{
	class InputManager : public ISingleton<InputManager> {
	public:
		enum MOUSE_STATUS { MOUSE_NONE, MOUSE_DOWN, MOUSE_UP };

	public:
		virtual BOOL InitializeMembers();
		virtual BOOL ReleaseMembers();

		VOID SetMouseLBStatus(MOUSE_STATUS& _mouseStatus);
		VOID SetMouseRBStatus(MOUSE_STATUS& _mouseStatus);

		MOUSE_STATUS GetMouseLBStatus();
		MOUSE_STATUS GetMouseRBStatus();

		VOID SetMousePositon(Vector2& _position);
		Vector2 GetMousePosition();

		BOOL KeyDown(char _keycode, BOOL _isLoop);
		BOOL KeyUp(char _keycode);

	private:
		Vector2 mousePosition;
		MOUSE_STATUS mouseLBStatus;
		MOUSE_STATUS mouseRBStatus;
		char currentKeycode;
	};
}