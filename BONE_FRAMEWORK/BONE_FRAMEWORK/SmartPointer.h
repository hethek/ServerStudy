#pragma once
#include "Common.h"

namespace BONE_FRAMEWORK
{
	template<class T>
	class SmartPointer
	{
	public:
		SmartPointer(VOID) { Class = new T(); }
		~SmartPointer(VOID) { delete Class; }

		T* operator->(VOID) { return Class; }
		operator T*(VOID) { return Class; }

	private:
		T *Class;
	};
}