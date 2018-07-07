#if !defined(AFX_CLIENTSOCK_H__7CFF06D0_14C3_427B_92A4_2DD2AF08D14E__INCLUDED_)
#define AFX_CLIENTSOCK_H__7CFF06D0_14C3_427B_92A4_2DD2AF08D14E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif

#include "Afxsock.h"

class CClientSock : public CSocket
{
public:

public:
	CClientSock();
	virtual ~CClientSock();


public:

	CDialogEx * pDlg;
	//{{AFX_VIRTUAL(CClientSocket)
public:
	virtual void OnReceive(int nErrorCode);
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CClientSocket)
	// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
protected:
};


//{{AFX_INSERT_LOCATION}}

#endif 
