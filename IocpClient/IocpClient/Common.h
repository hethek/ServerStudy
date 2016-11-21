#pragma once

#define MAX_USER 100
#define DEFAULT_PORT 1820

#include "Global.h"

typedef struct _USER
{
	WCHAR szUserID[32];
	WCHAR szUserName[32];
	DWORD dwAge;
	BYTE cSex;
	WCHAR szAddress[32];
} USER;

typedef struct _COMPUTER
{
	WCHAR szComputerName[32];
	WCHAR szIPAddress[32];
	BYTE cCPUType;
	DWORD dwRam;
	DWORD dwHDD;
} COMPUTER;

typedef struct _PROGRAM
{
	WCHAR szProgramName[32];
	DWORD dwCost;
	WCHAR szComment[32];
} PROGRAM;


#include "CriticalSection.h"
#include "MultiThreadSync.h"
#include "MemoryPool.h"
#include "CircularQueue.h"
#include "NetworkSession.h"
#include "PacketSession.h"
#include "EventSelect.h"
#include "Iocp.h"
#include "Stream.h"
#include "MiniDump.h"
#include "IniFile.h"
#include "ClientSession.h"

#include "../IocpServer/Protocol.h"
#include "../IocpServer/PT_Structure.h"
#include "../IocpServer/PT_ReadPacket.h"
#include "../IocpServer/PT_WritePacket.h"

#include "../IocpServer/ConnectedSession.h"
#include "../IocpServer/ConnectedSessionManager.h"
#include "../IocpServer/ServerIocp.h"
