#pragma once
#ifndef __AFXTEMPL__
#define __AFXTEMPL__
#include<afxtempl.h>
#endif
// CAddSight 对话框

class CAddSight : public CDialogEx
{
	DECLARE_DYNAMIC(CAddSight)

public:
	CAddSight(UINT sight,CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CAddSight();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CList<CString> l_Sight;
	UINT I_ALLSIGHT;
	UINT m_Sight;
	bool b_AddSuccess;
	afx_msg void OnBnClickedConfirm();
	CString m_SightName;
	UINT m_CurSight;
	virtual void OnOK();
	afx_msg void OnBnClickedYes();
	afx_msg void OnBnClickedReadd();
};
