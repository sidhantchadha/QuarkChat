
#include "stdafx.h"
#include "Client.h"
#include "ClientDlg.h"

using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);   

protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CClientDlg dialog



CClientDlg::CClientDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CLIENT_DIALOG, pParent)
	, inUsername(_T(""))
	, inIP(_T(""))
	, inP(_T(""))
	, inMessage(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, dispCntrl);
	DDX_Text(pDX, IDC_EDIT1, inUsername);
	DDX_Text(pDX, IDC_EDIT2, inIP);
	DDX_Text(pDX, IDC_EDIT3, inP);
	DDX_Text(pDX, IDC_EDIT5, inMessage);
	DDX_Control(pDX, IDC_LIST2, usrCntrl);
}

BEGIN_MESSAGE_MAP(CClientDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT5, &CClientDlg::OnEnChangeEdit5)
	ON_BN_CLICKED(IDCANCEL, &CClientDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDOK, &CClientDlg::OnBnClickedOk)
	ON_EN_CHANGE(IDC_EDIT3, &CClientDlg::OnEnChangeEdit3)
	ON_LBN_SELCHANGE(IDC_LIST1, &CClientDlg::OnLbnSelchangeList1)
	ON_BN_CLICKED(IDC_BUTTON1, &CClientDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CClientDlg message handlers

BOOL CClientDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CClientDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CClientDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CClientDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CClientDlg::OnEnChangeEdit5()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CClientDlg::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	CString getUsername;
	GetDlgItem(IDC_EDIT1)->GetWindowText(getUsername);
	CString makeMsg;
	CString t = CTime::GetCurrentTime().Format("%H:%M");
	makeMsg = getUsername + " is offline now.";
	char *ptr = 0;
	int sof = makeMsg.GetLength();
	ptr = makeMsg.GetBuffer(sof);
	makeMsg.ReleaseBuffer();
	m_Client.Send(ptr, sof + 1);
	AfxMessageBox(_T("Client Disconnected. "));
	CDialogEx::OnCancel();
}

void CClientDlg::messageMaker(CString sDisplay) {

	dispCntrl.AddString(sDisplay);
	
}


void CClientDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	int port = _ttoi((inP));



	if (AfxSocketInit() == FALSE)
	{
		AfxMessageBox(_T("Socket initialization failed."));
		return;
	}

	if (m_Client.Create() == FALSE)
	{
		AfxMessageBox(_T("Socket creation failed."));
		return;

	}

	if (m_Client.Connect(inIP, port) == FALSE)
	{
		AfxMessageBox(_T("Connection unsuccessful."));
		return;

	}
	m_Client.pDlg = this;

	GetDlgItem(IDOK)->EnableWindow(false);
	GetDlgItem(IDCANCEL)->EnableWindow(true);

	CString getUsername;
	GetDlgItem(IDC_EDIT1)->GetWindowText(getUsername);
	CString connInfo = getUsername + " is online now.";
	usrCntrl.AddString(getUsername);
	AfxMessageBox(connInfo);
	int soStr = connInfo.GetLength();
	char *ptr = 0;
	ptr = connInfo.GetBuffer(soStr);
	connInfo.ReleaseBuffer();
	m_Client.Send(ptr, soStr+1);
	

}


void CClientDlg::OnEnChangeEdit3()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CClientDlg::OnLbnSelchangeList1()
{
	// TODO: Add your control notification handler code here
}


void CClientDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	CString getUsername;
	GetDlgItem(IDC_EDIT1)->GetWindowText(getUsername);
	CString makeMsg;
	GetDlgItem(IDC_EDIT5)->GetWindowText(makeMsg);
	CString t = CTime::GetCurrentTime().Format("%H:%M");
	makeMsg = getUsername +" (@" + t + ") : " + makeMsg ;
	char *ptr = 0;
	int sof = makeMsg.GetLength();
	ptr = makeMsg.GetBuffer(sof);
	makeMsg.ReleaseBuffer();
	m_Client.Send(ptr, sof+1);
	GetDlgItem(IDC_EDIT5)->SetWindowText("");
}


