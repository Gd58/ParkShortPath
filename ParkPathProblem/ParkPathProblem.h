// ParkPathProblem.h : main header file for the PARKPATHPROBLEM application
//

#if !defined(AFX_PARKPATHPROBLEM_H__C96C74AE_F4FF_4D76_B50C_52215FDD2D67__INCLUDED_)
#define AFX_PARKPATHPROBLEM_H__C96C74AE_F4FF_4D76_B50C_52215FDD2D67__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CParkPathProblemApp:
// See ParkPathProblem.cpp for the implementation of this class
//

class CParkPathProblemApp : public CWinApp
{
public:
	CParkPathProblemApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CParkPathProblemApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CParkPathProblemApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PARKPATHPROBLEM_H__C96C74AE_F4FF_4D76_B50C_52215FDD2D67__INCLUDED_)
