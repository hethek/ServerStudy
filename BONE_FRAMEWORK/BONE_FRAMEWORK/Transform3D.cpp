#include "Common.h"
#include "Transform3D.h"

namespace BONE_FRAMEWORK
{
	Transform3D::Transform3D()
	{
		position = Vector3(0, 0, 0);
		rotAngle = Quaternion(0, 0, 0, 1);
		scale = Vector3(1, 1, 1);
		forward = Vector3(0, 0, -1);
		up = Vector3(0, 1, 0);
		
		D3DXMatrixIdentity(&transform);
		D3DXMatrixIdentity(&rotateTransform);
		D3DXMatrixIdentity(&translateTransform);
		D3DXMatrixIdentity(&scaleTransform);
		boneTransform = NULL;
		D3DXMatrixIdentity(&parentTransform);

		parent = NULL;

		SetTypeName("Transform3D");
	}

	Transform3D::~Transform3D()
	{

	}

	void Transform3D::SetForward(Vector3 _forward)
	{
		forward = _forward;
		D3DXVec3Normalize(&forward, &forward);
	}

	void Transform3D::SetForward(float _x, float _y, float _z)
	{
		forward.x = _x;
		forward.y = _y;
		forward.z = _z;

		D3DXVec3Normalize(&forward, &forward);
	}

	Vector3 Transform3D::GetForward()
	{
		Vector3 Forward = forward;

		D3DXVec3TransformNormal(&Forward, &Forward, &transform);
		D3DXVec3Normalize(&Forward, &Forward);

		return Forward;
	}

	Vector3 Transform3D::GetLeft()
	{
		Vector3 Left;
		Vector3 Forward = forward;
		Vector3 Up = up;

		D3DXVec3TransformNormal(&Up, &Up, &transform);
		D3DXVec3Normalize(&Up, &Up);

		D3DXVec3TransformNormal(&Forward, &Forward, &transform);
		D3DXVec3Normalize(&Forward, &Forward);

		D3DXVec3Cross(&Left, &Forward, &Up);
		D3DXVec3Normalize(&Left, &Left);
		
		return Left;
	}

	void Transform3D::SetPosition(Vector3 _position)
	{
		position = _position;
	}

	void Transform3D::SetPosition(float _x, float _y, float _z)
	{
		position.x = _x;
		position.y = _y;
		position.z = _z;
	}

	void Transform3D::Translate(Vector3 _position)
	{
		position += _position;
	}

	void Transform3D::Translate(float _x, float _y, float _z)
	{
		position.x += _x;
		position.y += _y;
		position.z += _z;
	}

	Vector3 Transform3D::GetPosition()
	{
		return position;
	}

	void Transform3D::Scale(Vector3 _scale)
	{
		scale.x += _scale.x;
		scale.y += _scale.y;
		scale.z += _scale.z;
	}

	void Transform3D::Scale(float _x, float _y, float _z)
	{
		scale.x += _x;
		scale.y += _y;
		scale.z += _z;
	}

	void Transform3D::SetScale(Vector3 _scale)
	{
		scale = _scale;
	}

	void Transform3D::SetScale(float _x, float _y, float _z)
	{
		scale.x = _x;
		scale.y = _y;
		scale.z = _z;
	}

	Vector3 Transform3D::GetScale()
	{
		return scale;
	}

	void Transform3D::Rotate(Quaternion _rotateAngle)
	{
		D3DXQuaternionMultiply(&rotAngle, &rotAngle, &_rotateAngle);
	}

	void Transform3D::Rotate(float _x, float _y, float _z)
	{
		Quaternion Quater;
		D3DXQuaternionRotationYawPitchRoll(&Quater, _y, _x, _z);
		
		D3DXQuaternionMultiply(&rotAngle, &rotAngle, &Quater);
	}

	void Transform3D::SetRotate(Quaternion _rotateAngle)
	{
		rotAngle = _rotateAngle;
	}

	void Transform3D::SetRotate(float _x, float _y, float _z)
	{
		Quaternion Quater;
		D3DXQuaternionRotationYawPitchRoll(&Quater, _y, _x, _z);

		rotAngle = Quater;
	}

	Quaternion Transform3D::GetRotateAngle()
	{
		return rotAngle;
	}
	
	Matrix Transform3D::GetTransform()
	{
		GameObject* parentPtr = parent;

		Vector3 Scale = scale;
		Vector3 Posit = position;
		Quaternion RotAngle = rotAngle;

		if (boneTransform != NULL)
		{
			D3DXMatrixRotationQuaternion(&rotateTransform, &RotAngle);

			D3DXMatrixTranslation(&translateTransform, Posit.x, Posit.y, Posit.z);
			D3DXMatrixScaling(&scaleTransform, Scale.x, Scale.y, Scale.z);

			transform = scaleTransform * rotateTransform * translateTransform;

			D3DXMatrixMultiply(&transform, &transform, &parentTransform);

			return transform;
		}

		while (parentPtr != NULL)
		{
			Scale.x *= ((Transform3D*)parentPtr->GetComponent("Transform3D"))->GetScale().x;
			Scale.y *= ((Transform3D*)parentPtr->GetComponent("Transform3D"))->GetScale().y;
			Scale.z *= ((Transform3D*)parentPtr->GetComponent("Transform3D"))->GetScale().z;

			Posit += ((Transform3D*)parentPtr->GetComponent("Transform3D"))->GetPosition();

			RotAngle *= ((Transform3D*)parentPtr->GetComponent("Transform3D"))->GetRotateAngle();

			parentPtr = parentPtr->GetParent();
		}

		D3DXMatrixRotationQuaternion(&rotateTransform, &RotAngle);
		
		D3DXMatrixTranslation(&translateTransform, Posit.x, Posit.y, Posit.z);
		D3DXMatrixScaling(&scaleTransform, Scale.x, Scale.y, Scale.z);
		
		transform = scaleTransform * rotateTransform * translateTransform;

		return transform;
	}
}