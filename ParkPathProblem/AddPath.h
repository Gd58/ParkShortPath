#if !defined(AFX_ADDPATH_H__402EBF2F_BD06_4AAB_8DE8_1B11CE448015__INCLUDED_)
#define AFX_ADDPATH_H__402EBF2F_BD06_4AAB_8DE8_1B11CE448015__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AddPath.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// AddPath dialog

class AddPath : public CDialog
{
// Construction
public:
	AddPath(CWnd* pParent = NULL);   // standard constructor
	long a[10][10];
// Dialog Data
	//{{AFX_DATA(AddPath)
	enum { IDD = IDD_DIALOG2 };
	CString	m_OrigalPath;
	CString	m_EndPath;
	long	m_LengthPath;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(AddPath)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(AddPath)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADDPATH_H__402EBF2F_BD06_4AAB_8DE8_1B11CE448015__INCLUDED_)
