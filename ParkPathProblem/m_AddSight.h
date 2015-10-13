#if !defined(AFX_M_ADDSIGHT_H__024BE57D_B3CA_4D97_A429_1167B9BDBD92__INCLUDED_)
#define AFX_M_ADDSIGHT_H__024BE57D_B3CA_4D97_A429_1167B9BDBD92__INCLUDED_

#ifndef __AFXTEMPl__
#define __AFXTEMPl__
#include<Afxtempl.h>
#endif

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// m_AddSight.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// m_AddSight dialog

class m_AddSight : public CDialog
{
// Construction
public:
	UINT m_CurSight;
	UINT m_ISight;
	m_AddSight(unsigned sight,CWnd* pParent = NULL);   // standard constructor
	CList<CString,CString> l_Sight;
// Dialog Data
	//{{AFX_DATA(m_AddSight)
	enum { IDD = IDD_DIALOG1 };
	CString	m_SightName;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(m_AddSight)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(m_AddSight)
	afx_msg void OnConfirm();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_M_ADDSIGHT_H__024BE57D_B3CA_4D97_A429_1167B9BDBD92__INCLUDED_)
