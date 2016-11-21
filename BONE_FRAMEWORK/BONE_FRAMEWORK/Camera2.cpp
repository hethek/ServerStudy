#include "Common.h"
#include "RenderManager.h"
#include "InputManager.h"
#include "Camera.h"
#include "Transform3D.h"
#include "SceneManager.h"

namespace BONE_FRAMEWORK
{
	Camera::Camera(int _ID, Vector3 _cameraUp, int _width, int _height, float _far, float _near, float _fov)
		:ID(_ID), cameraUp(_cameraUp), width(_width), height(_height), farDistance(_far), nearDistance(_near), fov(_fov)
	{
		SetType("Camera");
		Transform3D Transform;
	}

	Vector3 Camera::GetTargetPosition()
	{
		return targetPosition;
	}

	void Camera::SetTargetPosition(Vector3 _targetPosition)
	{
		targetPosition = _targetPosition;
	}
	
	void Camera::SetTargetPosition(float x, float y, float z)
	{
		targetPosition.x = x;
		targetPosition.y = y;
		targetPosition.z = z;
	}

	Matrix Camera::GetViewMatrix(CGameObject* _obj)
	{
		Transform3D* trans = ((Transform3D*)_obj->GetComponent("Transform3D"));

		if (trans != NULL)
		{
			Vector3 Position = trans->GetPosition();

			D3DXMatrixLookAtLH(&viewMatrix, &Position, &targetPosition, &cameraUp);
		}
		else
		{
			D3DXMatrixIdentity(&viewMatrix);
		}

		return viewMatrix;
	}

	void Camera::SetFov(float _fov)
	{
		fov = _fov;
	}
	
	float Camera::GetFov()
	{
		return fov;
	}

	void Camera::SetNearDistance(float _near)
	{
		nearDistance = _near;
	}
	
	float Camera::GetNearDistance()
	{
		return nearDistance;
	}

	void Camera::SetFarDistance(float _far)
	{
		farDistance = _far;
	}
	
	float Camera::GetFarDistance()
	{
		return farDistance;
	}

	Vector3 Camera::GetCameraUp()
	{
		return cameraUp;
	}

	int Camera::GetID()
	{
		return ID;
	}
}