// AddSight.cpp : 实现文件
//

#include "stdafx.h"
#include "ParkPathProblem.h"
#include "AddSight.h"
#include "afxdialogex.h"


// CAddSight 对话框

IMPLEMENT_DYNAMIC(CAddSight, CDialogEx)

CAddSight::CAddSight(UINT sight,CWnd* pParent /*=NULL*/)
	: CDialogEx(CAddSight::IDD, pParent)
	, m_SightName(_T(""))
{
	m_Sight = sight;
	I_ALLSIGHT = 0;
	m_CurSight = 0;
	b_AddSuccess = false;
	l_Sight.RemoveAll();
}

CAddSight::~CAddSight()
{
}

void CAddSight::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_SightName);
}


BEGIN_MESSAGE_MAP(CAddSight, CDialogEx)
	ON_BN_CLICKED(IDC_CONFIRM, &CAddSight::OnBnClickedConfirm)
	ON_BN_CLICKED(IDC_YES, &CAddSight::OnBnClickedYes)
	ON_BN_CLICKED(IDC_ReAdd, &CAddSight::OnBnClickedReadd)
END_MESSAGE_MAP()


// CAddSight 消息处理程序


void CAddSight::OnBnClickedConfirm()
{
	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
	bool b_flat = TRUE;
	if (m_CurSight <m_Sight){
	if (m_SightName == ""){
		AfxMessageBox(_T("请输入城市的名字"));
	}
	else{
		if (m_CurSight < m_Sight){
			POSITION head = l_Sight.GetHeadPosition();
			while (head){
				if (l_Sight.GetAt(head) == m_SightName){
					b_flat = false;
					break;
				}
				l_Sight.GetNext(head);
			}
			if (b_flat){
				l_Sight.AddTail(m_SightName);
				AfxMessageBox(_T("景点添加成功"));
				++m_CurSight;
			}
			else{
				AfxMessageBox(_T("请不要重复输入"));
			}

		}
	}
	}
	else
	{
		AfxMessageBox(_T("您输入的景点超了"));
	}
}


void CAddSight::OnOK()
{
	// TODO:  在此添加专用代码和/或调用基类
	if (m_CurSight == m_Sight){
		CDialogEx::OnOK();
	}
	else if(m_CurSight < m_Sight){
		AfxMessageBox(_T("您输入的景点数不足"));
	}
	else{
		AfxMessageBox(_T("您输入的景点数过多"));
	}
}


void CAddSight::OnBnClickedYes()
{
	// TODO:  在此添加控件通知处理程序代码
	if (m_CurSight == m_Sight){
		AfxMessageBox(_T("添加景点成功"));
		b_AddSuccess = TRUE;
		EndDialog(TRUE);
	}
	else{
		AfxMessageBox(_T("添加景点失败请重新继续添加"));
	}
}


void CAddSight::OnBnClickedReadd()
{
	// TODO:  在此添加控件通知处理程序代码
	l_Sight.RemoveAll();
	m_CurSight = 0;
}
