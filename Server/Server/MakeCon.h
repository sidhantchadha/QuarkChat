
#pragma once
#pragma comment (lib, "Ws2_32.lib")
class CServerDlg;


class MakeCon
{
public:
	MakeCon(CServerDlg* pDlg);
	~MakeCon(void);

	SOCKET srvSock;
	SOCKET clntSock;
	WSADATA wsa;
	CServerDlg* m_pDialog;
	CWinThread *cTh;
	HANDLE m_Thread_handle[20];

	void MakeConnection(int nPort);
	static UINT __cdecl childThreadFunc(LPVOID pParam);
};

