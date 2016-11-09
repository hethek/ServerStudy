#include "Common.h"
#include "Collision.h"

namespace BONE_FRAMEWORK
{
	CCollision::CCollision()
	{
	}


	CCollision::~CCollision()
	{
	}

	BOOL CCollision::GetCollision(Type _type, RECT _r1, RECT _r2)
	{
		switch (_type)
		{
		case AABB:
			if (_r1.left <= _r2.right &&
				_r1.right >= _r2.left  &&

				_r1.top <= _r2.bottom &&
				_r1.bottom >= _r2.top)
				return TRUE;
			else
				return FALSE;

		default:
			return FALSE;
		}

		return FALSE;
	}
}