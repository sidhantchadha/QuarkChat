
#include "stdafx.h"
#include "Client.h"
#include "ClientSock.h"
#include "ClientDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CClientSock::CClientSock()
{
}

CClientSock::~CClientSock()
{
}


#if 0
BEGIN_MESSAGE_MAP(CClientSock, CSocket)
	//{{AFX_MSG_MAP(CClientSocket)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0


void CClientSock::OnReceive(int nErrorCode)
{
	char inMsg[1024];
	int stlen;
	CString strData;
	stlen = Receive(inMsg, 1024);
	inMsg[stlen] = '\0';
	strData = inMsg;
	((CClientDlg*)pDlg)->messageMaker(strData);
}
