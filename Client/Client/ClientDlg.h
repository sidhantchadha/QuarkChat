#include "ClientSock.h"
#pragma once


class CClientDlg : public CDialogEx
{

public:
	CClientDlg(CWnd* pParent = nullptr);	
	void messageMaker(CString sDisplay);
	afx_msg void OnEnChangeEdit5();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedOk();
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnLbnSelchangeList1();
	afx_msg void OnBnClickedButton1();
	CComboBox comboCntrl;
	CClientSock m_Client;
	CListBox dispCntrl;
	CString inUsername;
	CString inIP;
	CString inP;
	CString inMessage;
	CListBox usrCntrl;


#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CLIENT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	HICON m_hIcon;
	
};
