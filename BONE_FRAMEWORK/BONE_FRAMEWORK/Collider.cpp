#include "Collider.h"
#include "Transform2D.h"
namespace BONE_FRAMEWORK
{
	Collider::Collider()
		:distance(0.0f),check(true),position(Vector2(0, 0))
	{
		this->SetType("Collider");
	}

	Collider::~Collider()
	{
		objList.clear();
	}

	bool Collider::RegisterColliderObject(CGameObject* _object)
	{
		if (_object != NULL)
		{
			if (((Collider*)_object->GetComponent("Collider")) != NULL)
			{
				for each (CGameObject* obj in objList)
				{
					if (obj == _object)
						return false;
				}
				objList.push_back(_object);
				return true;
			}
		}
		return false;
	}

	void Collider::SetPosition(Vector2 _position)
	{
		position = _position;
	}

	Vector2 Collider::GetPosition()
	{
		return position;
	}

	void Collider::SetDistance(float _distance)
	{
		distance = _distance;
	}

	float Collider::GetDistance()
	{
		return distance;
	}

	void Collider::SetActive(bool _check)
	{
		check = _check;
	}

	bool Collider::GetActvie()
	{
		return check;
	}

	void Collider::UpdateCollider()
	{
		if (check)
		{
			Vector2 Position = ((Transform2D*)parent->GetComponent("Transform2D"))->GetPosition() + position;

			for each (CGameObject* obj in objList)
			{
				Vector2 DistanceVector(0, 0);
				Vector2 ObjectPosition;

				//지정된 행렬에 의해 2D 벡터를 변환 해, 그 결과를 w = 1 에 투영 한다.
				D3DXVec2TransformCoord(&ObjectPosition,
					&((Transform2D*)obj->GetComponent("Transform2D"))->GetPosition(),
					&((Transform2D*)obj->GetComponent("Transform2D"))->GetTransform());

				ObjectPosition += ((Collider*)obj->GetComponent("Collider"))->GetPosition();

				//2 개의 2D 벡터를 뺄셈 한다.
				D3DXVec2Subtract(&DistanceVector, &Position, &ObjectPosition);

				//거리계산
				float Distance = D3DXVec2Length(&DistanceVector);
				float Distance2 = distance + ((Collider*)obj->GetComponent("Collider"))->GetDistance();

				if (Distance2 >= Distance)
					parent->CrashObject(obj);
			}
		}
	}
}