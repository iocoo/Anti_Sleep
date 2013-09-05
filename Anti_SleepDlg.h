// Anti_SleepDlg.h : header file
//

#if !defined(AFX_ANTI_SLEEPDLG_H__88E33C39_8E18_4D2D_A340_47C81436A50B__INCLUDED_)
#define AFX_ANTI_SLEEPDLG_H__88E33C39_8E18_4D2D_A340_47C81436A50B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CAnti_SleepDlg dialog

class CAnti_SleepDlg : public CDialog
{
// Construction
public:
	void Shutdown();
	void ToTray();
	CAnti_SleepDlg(CWnd* pParent = NULL);	// standard constructor
	CTime t;
	CTime shut_time;
	CBitmapButton shutBBT;
	CBitmapButton hideBBT;
	CBitmapButton quitBBT;

// Dialog Data
	//{{AFX_DATA(CAnti_SleepDlg)
	enum { IDD = IDD_ANTI_SLEEP_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAnti_SleepDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	NOTIFYICONDATA nid;
	CBrush m_brush;
	// Generated message map functions
	//{{AFX_MSG(CAnti_SleepDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg LRESULT onShowTask(WPARAM wParam,LPARAM lParam); 
	afx_msg void OnDestroy();
	afx_msg UINT OnNcHitTest(CPoint point);
	afx_msg void OnShutdown();
	afx_msg void OnToTray();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ANTI_SLEEPDLG_H__88E33C39_8E18_4D2D_A340_47C81436A50B__INCLUDED_)
