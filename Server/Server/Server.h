
/* Quark Chat is covered under MIT License for open source project. Please give
credits in case you decide to use this project or its components anywhere.
Developed by Sidhant Chadha at San Marcos, Texas in 2018. */ 

#if !defined(AFX_SERVER_H__7AA7D190_8407_49A5_A315_FB3E228E6F80__INCLUDED_)
#define AFX_SERVER_H__7AA7D190_8407_49A5_A315_FB3E228E6F80__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		


class CServerApp : public CWinApp
{
public:
	CServerApp();

public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
#endif

