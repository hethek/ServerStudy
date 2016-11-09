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
		virtual VOID Render();

	public:
		CComponent(VOID);
		~CComponent(VOID);
	};
}

