#include "Component.h"

namespace BONE_FRAMEWORK
{
	CComponent::CComponent(VOID)
	{
	}

	CComponent::~CComponent(VOID)
	{
	}

	std::string CComponent::GetType()
	{
		return type;
	}

	VOID CComponent::SetType(std::string _type)
	{
		type = _type;
	}

	VOID CComponent::Render()
	{

	}
}