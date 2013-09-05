#if !defined(AFX_SHUTDOWNDLG_H__574E7E50_93C8_4ECE_9A56_717AE2B89399__INCLUDED_)
#define AFX_SHUTDOWNDLG_H__574E7E50_93C8_4ECE_9A56_717AE2B89399__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ShutdownDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CShutdownDlg dialog

class CShutdownDlg : public CDialog
{
// Construction
public:
	CShutdownDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CShutdownDlg)
	enum { IDD = IDD_SHUTDOWNDIALOG };
	CTime	m_timepicker;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShutdownDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CShutdownDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHUTDOWNDLG_H__574E7E50_93C8_4ECE_9A56_717AE2B89399__INCLUDED_)
