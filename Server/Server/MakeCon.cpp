
#include "StdAfx.h"
#include "MakeCon.h"
#include "Server.h"
#include "ServerDlg.h"
#include "unordered_map"

static SOCKET nCLientSock[100];
static int nClients;
MakeCon::MakeCon(CServerDlg* pDlg)
{
	m_pDialog = pDlg;
	
}


MakeCon::~MakeCon()
{

	closesocket(srvSock);
	WSACleanup();
}

void MakeCon::MakeConnection(int nPort)
{

	int res;
	struct sockaddr_in srvInfo;

	res = WSAStartup(MAKEWORD(2, 2), &wsa);
	if (res != 0)
	{
		AfxMessageBox(_T("Failed."));
		return;
	}

	if ((srvSock = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
	{
		AfxMessageBox(_T("Could not create socket"));
	}

	srvInfo.sin_family = AF_INET;
	srvInfo.sin_addr.s_addr = INADDR_ANY;
	srvInfo.sin_port = htons(nPort);

	if (bind(srvSock, (struct sockaddr *)&srvInfo, sizeof(srvInfo)) == SOCKET_ERROR)
	{
		AfxMessageBox(_T("Failed to bind."));
		exit(EXIT_FAILURE);
	}

	listen(srvSock, 20);
	struct sockaddr_in clntInfo;
	int inAddsize = sizeof(struct sockaddr_in);
	nClients = 0;

	//Accept will break the listening loop and create a thread with client socket//

	while ((clntSock = accept(srvSock, (struct sockaddr *)&clntInfo, &inAddsize)) != INVALID_SOCKET)
	{
		
		struct sockaddr_storage addr;
		char inIPad[INET6_ADDRSTRLEN];
		socklen_t len = sizeof(addr);
		getpeername(clntSock, (struct sockaddr*)&addr, &len);
		struct sockaddr_in *cCon = (struct sockaddr_in *)&addr;
		inet_ntop(AF_INET, &cCon->sin_addr, inIPad, sizeof(inIPad));
		CString IPadv(inIPad);
		CString portVal;
		m_pDialog->GetDlgItem(IDC_EDIT2)->GetWindowText(portVal);
		CString t = CTime::GetCurrentTime().Format("%H:%M");
		CString stat = IPadv + " is connected on " + portVal + " [Time stamp: " + t + "]";
		m_pDialog->screenUpdate(stat);

	//Starting child thread whenever client connection is accepted//

		cTh= AfxBeginThread(childThreadFunc,(LPVOID)clntSock);
		++nClients;
		nCLientSock[nClients] = clntSock;

	}

	if (!clntSock)
	{
		AfxMessageBox(_T("Failed to accept client."));
		return;
	}
}

UINT __cdecl MakeCon::childThreadFunc(LPVOID pParam)
{
	SOCKET pYourSocket = reinterpret_cast<SOCKET>(pParam);
	char *sendBuff;
	char recvBuff[1025];
	sendBuff = "Initializing Quark chat.";
	send(pYourSocket, sendBuff, strlen(sendBuff), 0);
	while ((recv(pYourSocket, recvBuff, 1025, 0)) != SOCKET_ERROR)
	{
		recvBuff[strlen(recvBuff)] = '\0';
	//Broadcast to all clients//
		for (int brdcst = 1; brdcst <= nClients; brdcst++)
			(send(nCLientSock[brdcst], recvBuff, strlen(recvBuff), 0));
	}
	return 0;
}



