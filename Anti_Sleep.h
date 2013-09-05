// Anti_Sleep.h : main header file for the ANTI_SLEEP application
//

#if !defined(AFX_ANTI_SLEEP_H__72044070_DF06_454F_AE92_208BA6094666__INCLUDED_)
#define AFX_ANTI_SLEEP_H__72044070_DF06_454F_AE92_208BA6094666__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CAnti_SleepApp:
// See Anti_Sleep.cpp for the implementation of this class
//

class CAnti_SleepApp : public CWinApp
{
public:
	CAnti_SleepApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAnti_SleepApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CAnti_SleepApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ANTI_SLEEP_H__72044070_DF06_454F_AE92_208BA6094666__INCLUDED_)
