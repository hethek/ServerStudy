#include "Common.h"

#define READ_PACKET(PROTOCOL)\
	S_##PROTOCOL Data;\
	READ_##PROTOCOL(Packet, Data);

class CTestClientSession : public CClientSession
{
protected:
	VOID OnIoConnected(VOID)
	{
		_tprintf(_T("OnIoConnected\n"));
	}

	VOID OnIoDisconnected(VOID)
	{
		_tprintf(_T("OnIoDisconnected\n"));
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	WSADATA WsaData;
	WSAStartup(MAKEWORD(2, 2), &WsaData);

	CTestClientSession *pClientSession = new CTestClientSession();
	
	if (pClientSession->BeginTcp("127.0.0.1", DEFAULT_PORT))
	{
		// 한개의 명령어씩 계속 처리하기 위한 while문입니다.  
		while (TRUE)
		{
			// 패킷을 보낼때 사용하는 버퍼  
			BYTE WriteBuffer[MAX_BUFFER_LENGTH] = { 0, };
			// 패킷을 받을때 사용하는 프로토콜, 길이, 패킷 변수  
			DWORD dwProtocol = 0, dwPacketLength = 0;
			BYTE Packet[MAX_BUFFER_LENGTH] = { 0, };

			// 화면을 한번 지워줍니다.  
			system("cls");

			// 키보드로 입력한 내용을 저장하는 변수  
			// 앞으로 모든 키보드로 입력한 내용이 이곳에 저장됩니다.  
			TCHAR szCommand[32] = { 0, };
			// USER, COMPUTER, PROGRAM의 선택을 받습니다.  
			_tprintf(_T("Enter command (USER/COMPUTER/PROGRAM) : "));
			ZeroMemory(szCommand, sizeof(szCommand));
			_getts_s(szCommand);

			// 키보드로 입력받은 내용을 소문자로 바꾸어 비교를 합니다.  
			if (!_tcscmp(_tcslwr(szCommand), _T("user")))
			{
				_tprintf(_T("=== USER ===\n"));
				// REG인지 QUERY인지를 선택합니다.  
				_tprintf(_T("Enter command (REG/QUERY) : "));
				ZeroMemory(szCommand, sizeof(szCommand));
				_getts_s(szCommand);

				// REG일 경우  
				if (!_tcscmp(_tcslwr(szCommand), _T("reg")))
				{
					WCHAR szUserID[32] = { 0, };
					WCHAR szUserName[32] = { 0, };
					DWORD dwAge = 0;
					BYTE cSex = 0;
					WCHAR szAddress[64] = { 0, };

					// USER_ID를 입력받습니다.  
					_tprintf(_T("Enter USER_ID : "));
					ZeroMemory(szCommand, sizeof(szCommand));
					_getts_s(szCommand);
					_tcscpy(szUserID, szCommand);

					// USER_NAME을 입력 받습니다.  
					_tprintf(_T("Enter USER_NAME : "));
					ZeroMemory(szCommand, sizeof(szCommand));
					_getts_s(szCommand);
					_tcscpy(szUserName, szCommand);

					// AGE를 입력 받습니다.  
					_tprintf(_T("Enter AGE : "));
					ZeroMemory(szCommand, sizeof(szCommand));
					_getts_s(szCommand);
					dwAge = _ttoi(szCommand);

					// SEX를 입력 받습니다.  
					_tprintf(_T("Enter SEX : "));
					ZeroMemory(szCommand, sizeof(szCommand));
					_getts_s(szCommand);
					cSex = _ttoi(szCommand);

					// ADDRESS를 입력 받습니다.  
					_tprintf(_T("Enter ADDRESS : "));
					ZeroMemory(szCommand, sizeof(szCommand));
					_getts_s(szCommand);
					_tcscpy(szAddress, szCommand);

					// 패킷을 전송합니다.  
					pClientSession->WritePacket(PT_REG_USER,
						WriteBuffer,
						WRITE_PT_REG_USER(WriteBuffer, // WRITE 함수  
							szUserID,
							szUserName,
							dwAge,
							cSex,
							szAddress));

					_tprintf(_T("Press any key..."));
					getchar();
				}
				// QUERY일 경우  
				else if (!_tcscmp(_tcslwr(szCommand), _T("query")))
				{
					WCHAR szUserID[32] = { 0, };

					// 검색할 USER_ID를 입력 받습니다.  
					_tprintf(_T("Enter USER_ID : "));
					ZeroMemory(szCommand, sizeof(szCommand));
					_getts_s(szCommand);
					_tcscpy(szUserID, szCommand);

					// 검색 패킷을 전송합니다.  
					pClientSession->WritePacket(PT_QUERY_USER,
						WriteBuffer,
						WRITE_PT_QUERY_USER(WriteBuffer,
							szUserID));

					// 전송할 패킷의 결과가 올 때까지 계속 패킷을 읽습니다.  
					// 계속 읽는 이유는 Server에 추가했던 KeepAlive 패킷 때문입니다.  
					while (TRUE) if (!pClientSession->ReadPacket(dwProtocol, Packet, dwPacketLength)) if (dwProtocol == PT_QUERY_USER_RESULT) break;

					// 패킷을 읽습니다.  
					READ_PACKET(PT_QUERY_USER_RESULT);

					// 읽은 패킷을 출력합니다.  
					_tprintf(_T("QUERY : USER_ID(%s), USER_NAME(%s), AGE(%d), SEX(%d), ADDRESS(%s)\n"), Data.USER_ID, Data.USER_NAME, Data.AGE, Data.SEX, Data.ADDRESS);

					_tprintf(_T("Press any key..."));
					getchar();
				}
			}
			// 키보드로 입력받은 내용을 소문자로 바꾸어 비교를 합니다.  
			else if (!_tcscmp(_tcslwr(szCommand), _T("computer")))
			{
				// COMPUTER일 경우 REG, QUERY를 입력 받습니다.  
				_tprintf(_T("=== COMPUTER ===\n"));
				_tprintf(_T("Enter command (REG/QUERY) : "));
				ZeroMemory(szCommand, sizeof(szCommand));
				_getts_s(szCommand);

				// REG일 경우 입력 방식만 바뀌고 USER와 동일하게 진행됩니다.  
				if (!_tcscmp(_tcslwr(szCommand), _T("reg")))
				{
					WCHAR szComputerName[32] = { 0, };
					WCHAR szIPAddress[32] = { 0, };
					BYTE cCPUType = 0;
					DWORD dwRAM = 0;
					DWORD dwHDD = 0;

					_tprintf(_T("Enter COMPUTER_NAME : "));
					ZeroMemory(szCommand, sizeof(szCommand));
					_getts_s(szCommand);
					_tcscpy(szComputerName, szCommand);

					_tprintf(_T("Enter IP_ADDRESS : "));
					ZeroMemory(szCommand, sizeof(szCommand));
					_getts_s(szCommand);
					_tcscpy(szIPAddress, szCommand);

					_tprintf(_T("Enter CPU_TYPE : "));
					ZeroMemory(szCommand, sizeof(szCommand));
					_getts_s(szCommand);
					cCPUType = _ttoi(szCommand);

					_tprintf(_T("Enter RAM : "));
					ZeroMemory(szCommand, sizeof(szCommand));
					_getts_s(szCommand);
					dwRAM = _ttoi(szCommand);

					_tprintf(_T("Enter HDD : "));
					ZeroMemory(szCommand, sizeof(szCommand));
					_getts_s(szCommand);
					dwHDD = _ttoi(szCommand);

					pClientSession->WritePacket(PT_REG_COMPUTER,
						WriteBuffer,
						WRITE_PT_REG_COMPUTER(WriteBuffer,
							szComputerName,
							szIPAddress,
							cCPUType,
							dwRAM,
							dwHDD));

					_tprintf(_T("Press any key..."));
					getchar();
				}
				// QUERY일 경우 USER와 동일하게 진행됩니다.  
				else if (!_tcscmp(_tcslwr(szCommand), _T("query")))
				{
					WCHAR szComputerName[32] = { 0, };

					_tprintf(_T("Enter COMPUTER_NAME : "));
					ZeroMemory(szCommand, sizeof(szCommand));
					_getts_s(szCommand);
					_tcscpy(szComputerName, szCommand);

					pClientSession->WritePacket(PT_QUERY_COMPUTER,
						WriteBuffer,
						WRITE_PT_QUERY_COMPUTER(WriteBuffer,
							szComputerName));

					while (TRUE) if (!pClientSession->ReadPacket(dwProtocol, Packet, dwPacketLength)) if (dwProtocol == PT_QUERY_COMPUTER_RESULT) break;

					READ_PACKET(PT_QUERY_COMPUTER_RESULT);

					_tprintf(_T("QUERY : COMPUTER_NAME(%s), IP_ADDRESS(%s), CPU_TYPE(%d), RAM(%d), HDD(%d)\n"), Data.COMPUTER_NAME, Data.IP_ADDRESS, Data.CPU_TYPE, Data.RAM, Data.HDD);

					_tprintf(_T("Press any key..."));
					getchar();
				}
			}
			// 키보드로 입력받은 내용을 소문자로 바꾸어 비교를 합니다.  
			else if (!_tcscmp(_tcslwr(szCommand), _T("program")))
			{
				_tprintf(_T("=== PROGRAM ===\n"));
				_tprintf(_T("Enter command (REG/QUERY) : "));
				ZeroMemory(szCommand, sizeof(szCommand));
				_getts_s(szCommand);

				// REG일 경우 입력 방식만 바뀌고 USER와 동일하게 진행됩니다.  
				if (!_tcscmp(_tcslwr(szCommand), _T("reg")))
				{
					WCHAR szProgramName[32] = { 0, };
					DWORD dwCOST = 0;
					WCHAR szComment[32] = { 0, };

					_tprintf(_T("Enter PROGRAM_NAME : "));
					ZeroMemory(szCommand, sizeof(szCommand));
					_getts_s(szCommand);
					_tcscpy(szProgramName, szCommand);

					_tprintf(_T("Enter COST : "));
					ZeroMemory(szCommand, sizeof(szCommand));
					_getts_s(szCommand);
					dwCOST = _ttoi(szCommand);

					_tprintf(_T("Enter COMMENT : "));
					ZeroMemory(szCommand, sizeof(szCommand));
					_getts_s(szCommand);
					_tcscpy(szComment, szCommand);

					pClientSession->WritePacket(PT_REG_PROGRAM,
						WriteBuffer,
						WRITE_PT_REG_PROGRAM(WriteBuffer,
							szProgramName,
							dwCOST,
							szComment));

					_tprintf(_T("Press any key..."));
					getchar();
				}
				// QUERY일 경우 USER와 동일하게 진행됩니다.  
				else if (!_tcscmp(_tcslwr(szCommand), _T("query")))
				{
					WCHAR szProgramName[32] = { 0, };

					_tprintf(_T("Enter PROGRAM_NAME : "));
					ZeroMemory(szCommand, sizeof(szCommand));
					_getts_s(szCommand);
					_tcscpy(szProgramName, szCommand);

					pClientSession->WritePacket(PT_QUERY_PROGRAM,
						WriteBuffer,
						WRITE_PT_QUERY_PROGRAM(WriteBuffer,
							szProgramName));

					while (TRUE) if (!pClientSession->ReadPacket(dwProtocol, Packet, dwPacketLength)) if (dwProtocol == PT_QUERY_PROGRAM_RESULT) break;

					READ_PACKET(PT_QUERY_PROGRAM_RESULT);

					_tprintf(_T("QUERY : PROGRAM_NAME(%s), COST(%d), COMMENT(%s)\n"), Data.PROGRAM_NAME, Data.COST, Data.COMMENT);

					_tprintf(_T("Press any key..."));
					getchar();
				}
			}
		}
	}


	pClientSession->End();

	delete pClientSession;

	WSACleanup();

	return 0;
}