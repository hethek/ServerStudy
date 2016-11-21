#pragma once
#include "Common.h"
#include "Component.h"
#include "GameObject.h"
#include <list>

namespace BONE_FRAMEWORK
{
	class Collider : public CComponent {	
	private:
		float distance;			 
		bool check;
		Vector2 position;
		GameObject* parent;
		std::list<CGameObject*> objList;
		
	public:
		Collider();
		virtual ~Collider();

		void SetDistance(float _distance);
		float GetDistance();

		void SetPosition(Vector2 _position);
		Vector2 GetPosition();

		void SetActive(bool _check);
		bool GetActvie();

		void UpdateCollider();
		bool RegisterColliderObject(CGameObject* _object);
	};
};
