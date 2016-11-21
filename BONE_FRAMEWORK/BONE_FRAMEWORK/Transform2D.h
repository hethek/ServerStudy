#pragma once
#include "Common.h"
#include "Component.h"
#include "GameObject.h"
#include "RenderManager.h"

namespace BONE_FRAMEWORK
{
	class Transform2D : public CComponent {
	private:
		Vector2 position;
		Vector2 scale;
		Vector2 pivotCenter;
		Matrix transform;
	private:		
		CGameObject *parent;
	private:
		float rotAngle;
	public:
		Transform2D();
		virtual ~Transform2D();

		void SetPosition(Vector2 _position);
		void SetPosition(float _x, float _y, float _z);
		void Translate(Vector2 _position);
		void Translate(float _x, float _y, float _z);
		Vector2 GetPosition();

		void Scale(Vector2 _scale);
		void Scale(float _x, float _y);
		void SetScale(Vector2 _scale);
		void SetScale(float _x, float _y);
		Vector2 GetScale();

		void Rotate(float _rotAngle);
		void SetRotate(float _rotAngle);
		float GetRotateAngle();
		
		void SetPivotCenter(Vector2 _pivotCenter);
		void SetPivotCenter(float _x, float _y);
		Vector2 GetPivotCenter();

		Matrix GetTransform();

		void AttachObject(CGameObject* _parent);
	};
}