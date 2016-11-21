#pragma once
#include "Common.h"
#include "RenderManager.h"
#include "Component.h"
#include "GameObject.h"

namespace BONE_FRAMEWORK
{
	class Camera : public CComponent
	{
	private:
		Vector3 targetPosition;
		Vector3 cameraUp;
		Matrix viewMatrix;
		Matrix projectionMatrix;
	
	private:
		int ID;
		float nearDistance;
		float farDistance;
		float fov;
		int mode;
		int width;
		int height;

	public:
		Camera(int _ID, Vector3 _cameraUp, int _width, int _height, float _far, float _near, float _fov);

		int GetID();

		void SetFov(float _fov);
		float GetFov();

		void SetNearDistance(float _near);
		float GetNearDistance();

		void SetFarDistance(float _far);
		float GetFarDistance();

		Vector3 GetCameraUp();
		void SetTargetPosition(Vector3 _targetPosition);
		void SetTargetPosition(float x, float y, float z);
		Vector3 GetTargetPosition();
		Matrix GetViewMatrix(CGameObject* _obj);
	};
}