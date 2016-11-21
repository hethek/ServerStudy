#pragma once
#include "ConnectedSession.h"

class CConnectedSessionManager : public CMultiThreadSync<CConnectedSessionManager>
{
public:
	CConnectedSessionManager(VOID);
	virtual ~CConnectedSessionManager(VOID);

	// 시작하는 함수
	BOOL Begin(SOCKET hListenSocket);
	// 종료하는 함수
	VOID End(VOID);

	// 접속된 모든 ConnectedSession에 패킷을 전송하는 함수
	VOID WriteAll(DWORD dwProtocol, BYTE *pData, DWORD dwLength);

private:
	// 생성된 ConnectedSession개체의 포인터를 관리하는 Vector
	std::vector<CConnectedSession*> m_vConnectedSessions;
};

