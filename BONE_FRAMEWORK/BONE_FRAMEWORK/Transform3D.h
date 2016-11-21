#pragma once
#include "Common.h"
#include "Component.h"
#include "GameObject.h"

namespace BONE_FRAMEWORK
{
	class Transform3D : public CComponent {
	private:
		Vector3 position;
		Quaternion rotAngle;
		Vector3 scale;
		Vector3 forward;
		Vector3 up;

		Matrix transform;
		Matrix rotateTransform;
		Matrix translateTransform;
		Matrix scaleTransform;
		Matrix* boneTransform;
		Matrix parentTransform;

		GameObject *parent;

	public:
		Transform3D();
		virtual ~Transform3D();

		void SetForward(Vector3 _forward);
		void SetForward(float _x, float _y, float _z);
		Vector3 GetForward();
		Vector3 GetLeft();

		void SetPosition(Vector3 _position);
		void SetPosition(float _x, float _y, float _z);		
		void Translate(Vector3 _position);
		void Translate(float _x, float _y, float _z);
		Vector3 GetPosition();

		void Scale(Vector3 _scale);
		void Scale(float _x, float _y, float _z);
		void SetScale(Vector3 _scale);
		void SetScale(float _x, float _y, float _z);
		Vector3 GetScale();

		void Rotate(Quaternion _rotateAngle);
		void Rotate(float _x, float _y, float _z);
		void SetRotate(Quaternion _rotateAngle);
		void SetRotate(float _x, float _y, float _z);
		Quaternion GetRotateAngle();

		Matrix GetTransform();
	};
}