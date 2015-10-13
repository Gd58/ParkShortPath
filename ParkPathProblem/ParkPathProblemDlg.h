// ParkPathProblemDlg.h : header file
//
#ifndef __AFXTEMPl__
#define __AFXTEMPl__
#include<Afxtempl.h>
#endif


#if !defined(AFX_PARKPATHPROBLEMDLG_H__06F75C16_A1F4_4078_889F_11A31E84A438__INCLUDED_)
#define AFX_PARKPATHPROBLEMDLG_H__06F75C16_A1F4_4078_889F_11A31E84A438__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CParkPathProblemDlg dialog

class CParkPathProblemDlg : public CDialog
{
// Construction
public:
	bool m_bAddSight;
	bool m_bAddPath;
	double a[7][7];
	double b[7][7];
    CList<CString,CString> l_SightName;
	CParkPathProblemDlg(CWnd* pParent = NULL);
	// standard constructor
	CMap<int,int,CString,CString> IndexToSight;
	CMap<int, int, CPoint, CPoint> IndexToPoint;

// Dialog Data
	//{{AFX_DATA(CParkPathProblemDlg)
	enum { IDD = IDD_PARKPATHPROBLEM_DIALOG };
	UINT	m_SumPath;
	UINT	m_SumSight;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CParkPathProblemDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions 
	//{{AFX_MSG(CParkPathProblemDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnAddpath();
	afx_msg void OnAddsight();
	afx_msg void OnDraw();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
//	CList<CString> l_SightName;
	CString m_OrigalSightName;
	CString m_EndName;
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedStartend();
//	CString m_BeginName;
	bool b_OrigalEndSuccess;
	void ShortPath();
	CPoint point1;
	CPoint point2;
	CPoint point3;
	CPoint point4;
	CPoint point5;
	CPoint point6;
	CPoint point7;
	int OriginIndex;
	int EndIndex;
	int Path[7];
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PARKPATHPROBLEMDLG_H__06F75C16_A1F4_4078_889F_11A31E84A438__INCLUDED_)
