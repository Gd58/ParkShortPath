#pragma once

#ifndef __AFXTEMPL__
#define __AFXTEMPL__
#include<afxtempl.h>
#endif

// AddSightPath 对话框

class AddSightPath : public CDialog
{
	DECLARE_DYNAMIC(AddSightPath)

public:
	AddSightPath(CList<CString,CString>& l_Sight,UINT iPath,CWnd* pParent = NULL);   // 标准构造函数
	virtual ~AddSightPath();

// 对话框数据
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_Sight1;
	CString m_Sight2;
	UINT m_SumPath;
	UINT m_CurPath;
	bool b_AddSucess;
	double a[7][7];
	CList<CString> l_Sight;
	afx_msg void OnBnClickedConfrim();
	virtual BOOL OnInitDialog();
	CMap<int,int,CString,CString> SightNameToIndex;
	CList<CString> l_SightName;
//	CList<CString> m_SightName;
	afx_msg void OnBnClickedReaddpath();
	CString m_distance;
	afx_msg void OnBnClickedPathyes();
};
