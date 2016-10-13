#pragma once
#include "Common.h"

namespace BONE_FRAMEWORK
{
	template<class T>
	class ISingleton abstract
	{
	private:
		static T* instance;

		ISingleton(VOID)
		{
		}

	public:
		virtual ~ISingleton(VOID)
		{

		}

		static T* GetInstance()
		{
			if(instance == NULL)
				instance = new T();

			return instance;
		}

		virtual BOOL InitializeMembers() = 0;
		virtual BOOL ReleaseMembers() = 0;
	};

	template<class T>
	T* ISingleton<T>::instance = NULL;
}

