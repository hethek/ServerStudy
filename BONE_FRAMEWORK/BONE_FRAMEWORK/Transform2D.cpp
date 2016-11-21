#include "Common.h"
#include "Transform2D.h"

namespace BONE_FRAMEWORK
{
	Transform2D::Transform2D()
	{
		SetType("Transform2D");
		position = Vector2(GETSINGLE(CRenderManager)->GetWidth() / 2, GETSINGLE(CRenderManager)->GetHeight() / 2, 0);
		pivotCenter = Vector2(0.5f, 0.5f);
		rotAngle = 0;
		scale = Vector2(1, 1);

		D3DXMatrixIdentity(&transform);

		parent = NULL;
	}

	Transform2D::~Transform2D()
	{

	}

	void Transform2D::SetPosition(Vector2 _position)
	{
		position = _position;
	}

	void Transform2D::SetPosition(float _x, float _y, float _z)
	{
		position.x = _x;
		position.y = _y;
		position.z = _z;
	}

	void Transform2D::Translate(Vector2 _position)
	{
		position += _position;
	}

	void Transform2D::Translate(float _x, float _y, float _z)
	{
		position.x += _x;
		position.y += _y;
		position.z += _z;
	}

	Vector2 Transform2D::GetPosition()
	{
		return position;
	}

	void Transform2D::Scale(Vector2 _scale)
	{
		scale += _scale;
	}

	void Transform2D::Scale(float _x, float _y)
	{
		scale.x += _x;
		scale.y += _y;
	}
	
	void Transform2D::SetScale(Vector2 _scale)
	{
		scale = _scale;
	}

	void Transform2D::SetScale(float _x, float _y)
	{
		scale.x = _x;
		scale.y = _y;
	}

	Vector2 Transform2D::GetScale()
	{
		return scale;
	}

	void Transform2D::Rotate(float _rotAngle)
	{
		rotAngle += _rotAngle;
	}	

	void Transform2D::SetRotate(float _rotAngle)
	{
		rotAngle = _rotAngle;
	}
	
	float Transform2D::GetRotateAngle()
	{
		return rotAngle;
	}

	void Transform2D::SetPivotCenter(Vector2 _pivotCenter)
	{
		pivotCenter = _pivotCenter;
	}
	
	void Transform2D::SetPivotCenter(float _x, float _y)
	{
		pivotCenter.x = _x;
		pivotCenter.y = _y;
	}

	Vector2 Transform2D::GetPivotCenter()
	{
		return pivotCenter;
	}
	
	Matrix Transform2D::GetTransform()
	{
		CGameObject* parentPtr = parent;

		Vector2 Scale = GetScale();
		Vector2 Position = GetPosition();
		float RotAngle = GetRotateAngle();

		while (parentPtr != NULL)
		{
			Scale.x *= ((Transform2D*)parentPtr->GetComponent("Transform2D"))->GetScale().x;
			Scale.y *= ((Transform2D*)parentPtr->GetComponent("Transform2D"))->GetScale().y;

			Position += ((Transform2D*)parentPtr->GetComponent("Transform2D"))->GetPosition();

			RotAngle *= ((Transform2D*)parentPtr->GetComponent("Transform2D"))->GetRotateAngle();

			parentPtr = parentPtr->GetParent();
		}

		D3DXMatrixIdentity(&transform);
		D3DXMatrixTransformation2D(&transform, &pivotCenter, NULL, &Scale, &pivotCenter, RotAngle, &Vector2(Posit.x, Posit.y));

		return transform;
	}

	void Transform2D::AttachObject(GameObject* _parent)
	{
		parent = _parent;
	}
}