// Anti_SleepDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Anti_Sleep.h"
#include "Anti_SleepDlg.h"
#include "ShutdownDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAnti_SleepDlg dialog

CAnti_SleepDlg::CAnti_SleepDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAnti_SleepDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAnti_SleepDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	t=CTime::GetCurrentTime();
	shut_time=CTime(t.GetYear(),t.GetMonth(),t.GetDay(),17,32,0);
}

void CAnti_SleepDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAnti_SleepDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAnti_SleepDlg, CDialog)
	//{{AFX_MSG_MAP(CAnti_SleepDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_MESSAGE(WM_SHOWTASK,onShowTask)
	ON_WM_DESTROY()
	ON_WM_NCHITTEST()
	ON_BN_CLICKED(ID_TIMESHUTDOWN, OnShutdown)
	ON_BN_CLICKED(ID_TOTRAY, OnToTray)
	ON_WM_ERASEBKGND()
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAnti_SleepDlg message handlers

BOOL CAnti_SleepDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	SetWindowText("阻止屏保开启/计算机休眠");
	long val=GetWindowLong(this->GetSafeHwnd(),GWL_STYLE);   
	val|= WS_SYSMENU; //需要系统菜单
	SetWindowLong(this->GetSafeHwnd(),GWL_STYLE,val);
	m_brush.CreateSolidBrush(RGB(0,0,255));
	//ModifyStyle(0,WS_SYSMENU,0);
	
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);	
	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;	
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_STRING, IDM_MINIWND, "隐藏到托盘");
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX,"关于.." );			
		}
		pSysMenu->RemoveMenu(0,MF_BYPOSITION);
		//pSysMenu->RemoveMenu(1,MF_BYPOSITION);
		pSysMenu->RemoveMenu(2,MF_BYPOSITION);
		pSysMenu->RemoveMenu(3,MF_BYPOSITION);
		pSysMenu->RemoveMenu(SC_SIZE,MF_BYCOMMAND);
		pSysMenu->RemoveMenu(SC_MAXIMIZE,MF_BYCOMMAND);
	}
	GetDlgItem(IDC_WORKSTATIC)->ShowWindow(FALSE);
	quitBBT.AutoLoad(IDCANCEL,this);
	quitBBT.LoadBitmaps(IDB_BITMAP3);
	shutBBT.AutoLoad(ID_TIMESHUTDOWN,this);
	shutBBT.LoadBitmaps(IDB_SHUTDOWNBMP);
	hideBBT.AutoLoad(ID_TOTRAY,this);
	hideBBT.LoadBitmaps(IDB_BITMAP2);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CAnti_SleepDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	
	if ((nID) == IDM_ABOUTBOX)
	 {
		CAboutDlg dlg;
		dlg.DoModal();
	}
	if (nID== IDM_MINIWND)
	{
		
		ToTray();
	}
	CDialog::OnSysCommand(nID, lParam);
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CAnti_SleepDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

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
		CDialog::OnPaint();
	}
	
	SetTimer(1,1000,NULL);
	
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CAnti_SleepDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}


void CAnti_SleepDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	
	
	t=CTime::GetCurrentTime();
	CString strTime;
	strTime=t.Format(" %Y/%m/%d-%H:%M:%S");
	SetDlgItemText(IDC_TIMESTATIC,strTime);
	Invalidate();
	BOOL bSrcActive;
	SystemParametersInfo(SPI_GETSCREENSAVEACTIVE,0,&bSrcActive,0);
	if (bSrcActive)
	{
		SystemParametersInfo(SPI_SETSCREENSAVEACTIVE,0,NULL,0);
	}
	GetDlgItem(IDC_WORKSTATIC)->ShowWindow(TRUE);
	
	if (t.GetHour()==shut_time.GetHour()&&t.GetMinute()==shut_time.GetMinute()&&t.GetSecond()==shut_time.GetSecond())
	{
		Shutdown();
	}
	CDialog::OnTimer(nIDEvent);
	
}

BOOL CAnti_SleepDlg::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	TCHAR nChar=pMsg->wParam;
	if (pMsg->message==WM_KEYDOWN&&nChar==VK_RETURN)
	{
		return TRUE;
	}
	
	return CDialog::PreTranslateMessage(pMsg);
}

void CAnti_SleepDlg::ToTray()
{
	//MessageBox("1123");
	
	nid.cbSize=(DWORD)sizeof(NOTIFYICONDATA);
	nid.hWnd=this->m_hWnd;
	nid.uID=IDR_MAINFRAME;
	nid.uFlags=NIF_ICON|NIF_MESSAGE|NIF_TIP ;
	nid.uCallbackMessage=WM_SHOWTASK;
	nid.hIcon=LoadIcon(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDR_MAINFRAME));
	strcpy(nid.szTip,"阻止屏保程序正在运行");	
	Shell_NotifyIcon(NIM_ADD,&nid);
	ShowWindow(SW_HIDE);	
}



LRESULT CAnti_SleepDlg::onShowTask(WPARAM wParam,LPARAM lParam)

{
	if(wParam!=IDR_MAINFRAME)
		return 1;
//	CMenu *sysMenu=GetSystemMenu(FALSE);
//	POINT rpoint; 
	switch(lParam)
	{
	case WM_RBUTTONUP:		
		{ 
			LPPOINT lpoint=new tagPOINT;
			::GetCursorPos(lpoint);
			CMenu menu;
			menu.CreatePopupMenu();
			menu.AppendMenu(MF_STRING,WM_DESTROY,"退出程序");
			//menu.AppendMenu(MF_STRING,IDM_ABOUTBOX,"关于");
			menu.TrackPopupMenu(TPM_LEFTALIGN,lpoint->x,lpoint->y,this);
			HMENU hmenu=menu.Detach();
			menu.DestroyMenu();
			delete lpoint;
		}
		break;
	case WM_LBUTTONDBLCLK:
	case WM_LBUTTONDOWN:
		{
			Shell_NotifyIcon(NIM_DELETE, &nid);
			this->ShowWindow(SW_SHOW);
		}
		break;
	}
	return 0;
}

void CAnti_SleepDlg::OnDestroy() 
{
	CDialog::OnDestroy();
	
	// TODO: Add your message handler code here
	Shell_NotifyIcon(NIM_DELETE, &nid);
	
}


UINT CAnti_SleepDlg::OnNcHitTest(CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
  CRect rc;
  GetClientRect(&rc);
  ClientToScreen(&rc);
  return rc.PtInRect(point) ? HTCAPTION : CDialog::OnNcHitTest(point);
}

void CAnti_SleepDlg::OnShutdown() 
{
	// TODO: Add your control notification handler code here
	CShutdownDlg shutDlg;
	if (shutDlg.DoModal()==IDOK)
	{
		shut_time=shutDlg.m_timepicker;
		CString strTime=shut_time.Format("系统将在%H:%M:%S关闭!");		
		MessageBox(strTime,"系统提示");

	}
	else return;
	
}

void CAnti_SleepDlg::Shutdown()
{
	HANDLE hToken;
	TOKEN_PRIVILEGES tkp;
	if (OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES|TOKEN_QUERY, &hToken))
	{
		LookupPrivilegeValue(NULL, SE_SHUTDOWN_NAME, &tkp.Privileges[0].Luid);
		tkp.PrivilegeCount = 1;
	    tkp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
		AdjustTokenPrivileges(hToken, FALSE, &tkp, 0, (PTOKEN_PRIVILEGES)NULL, 0);
		ExitWindowsEx(EWX_SHUTDOWN|EWX_POWEROFF, 0);
	}
	//Win9x实现的代码
	ExitWindowsEx(EWX_SHUTDOWN|EWX_POWEROFF,0);

}

void CAnti_SleepDlg::OnToTray() 
{
	// TODO: Add your control notification handler code here
	ToTray();
	
}

BOOL CAnti_SleepDlg::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
	
	CDC MemDC; 	
	CBitmap Bitmap,*pOldBitmap; 
	BITMAP bm; 
	Bitmap.LoadBitmap(IDB_BITMAP1); 
	Bitmap.GetObject(sizeof(BITMAP),&bm); 	
	MemDC.CreateCompatibleDC(pDC); 
	pOldBitmap=(CBitmap*)(MemDC.SelectObject(&Bitmap)); 
	CRect rcClient;
	GetClientRect(&rcClient); 
	pDC->BitBlt(0,0,rcClient.Width(),rcClient.Height(),&MemDC,0,0,SRCCOPY);
	MemDC.SelectObject(pOldBitmap);
	MemDC.DeleteDC(); 
	return TRUE; 
} 

HBRUSH CAnti_SleepDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
	
	if(pWnd==this)
	{ 
        return  hbr;
	}
	if (pWnd->GetDlgCtrlID()==IDC_WORKSTATIC)
	{
		pDC->SetTextColor(RGB(255,255,255));
		pDC->SetBkMode(TRANSPARENT);
		return (HBRUSH) GetStockObject(NULL_BRUSH);
	}
	else if(pWnd->GetDlgCtrlID()==IDC_TIMESTATIC)
	{
		pDC->SetTextColor(RGB(125,225,255));
		pDC->SetBkMode(TRANSPARENT);
		return (HBRUSH) GetStockObject(NULL_BRUSH);
		
	}
	else
	{
		return hbr;
	}
	
}
