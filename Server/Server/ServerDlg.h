
#if !defined(AFX_SERVERDLG_H__91CEEDDC_5EB4_4AE7_8175_D8A85EA9CA07__INCLUDED_)
#define AFX_SERVERDLG_H__91CEEDDC_5EB4_4AE7_8175_D8A85EA9CA07__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif
#include "MakeCon.h"


class CServerDlg : public CDialog
{

public:
	MakeCon * svrCon;
	CListBox dispCntrl;
	CEdit inPort;

	CServerDlg(CWnd* pParent = nullptr);
    static UINT __cdecl ParentThreadHelper(LPVOID pParam);
	UINT ParentThreadFunc();
	void screenUpdate(CString str);
	
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnLbnSelchangeList1();

	enum { IDD = IDD_SERVER_DIALOG };

protected:
	HICON m_hIcon;

	virtual BOOL OnInitDialog();
	virtual void DoDataExchange(CDataExchange* pDX);

	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();

	DECLARE_MESSAGE_MAP()

private:

	HANDLE th_Handler;
	CWinThread *cTh;
};

#endif