#pragma once
#include "Component.h"
#include "Texture.h"

namespace BONE_FRAMEWORK
{
	typedef enum _TYPE
	{
		AABB = 1,
	}Type;

	class CCollision : public CComponent
	{
	public:
		CCollision();
		~CCollision();

	public:
		BOOL GetCollision(Type _type, RECT _r1, RECT _r2);
	};
}

