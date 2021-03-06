
/* Quark Chat is covered under MIT License for open source project. Please give
credits in case you decide to use this project or its components anywhere.
Developed by Sidhant Chadha at San Marcos, Texas in 2018. */ 

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols

class CClientApp : public CWinApp
{
public:
	CClientApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CClientApp theApp;
