#pragma once
#include "Common.h"

namespace BONE_FRAMEWORK
{
	class CComponent
	{
	private:
		std::string type;

	public:
		std::string GetType();
		VOID SetType(std::string _type);

	public:
		CComponent(VOID);
		~CComponent(VOID);
	};
}

