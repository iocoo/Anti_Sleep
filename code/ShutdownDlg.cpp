// ShutdownDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Anti_Sleep.h"
#include "ShutdownDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CShutdownDlg dialog


CShutdownDlg::CShutdownDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CShutdownDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CShutdownDlg)
	m_timepicker = 0;
	//}}AFX_DATA_INIT

}


void CShutdownDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CShutdownDlg)
	DDX_DateTimeCtrl(pDX, IDC_TIMEPICKER, m_timepicker);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CShutdownDlg, CDialog)
	//{{AFX_MSG_MAP(CShutdownDlg)
	ON_WM_TIMER()
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CShutdownDlg message handlers

BOOL CShutdownDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	GetDlgItem(IDC_STATICTIME)->ShowWindow(FALSE);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


void CShutdownDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	CString strTime;
	CTime t=CTime::GetCurrentTime();
	strTime=t.Format("现在时间:%H时%M分%S秒");
	SetDlgItemText(IDC_STATICTIME,strTime);
	CDialog::OnTimer(nIDEvent);
}

void CShutdownDlg::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
			
	GetDlgItem(IDC_STATICTIME)->ShowWindow(TRUE);
	SetTimer(1,1000,NULL);
	
}
