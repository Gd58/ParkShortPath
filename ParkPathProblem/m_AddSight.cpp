// m_AddSight.cpp : implementation file
//

#include "stdafx.h"
#include "ParkPathProblem.h"
#include "m_AddSight.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// m_AddSight dialog


m_AddSight::m_AddSight(unsigned sight,CWnd* pParent /*=NULL*/)
	: CDialog(m_AddSight::IDD, pParent)
{
	//{{AFX_DATA_INIT(m_AddSight)
	m_SightName = _T("");
	m_ISight = sight;
	m_CurSight = 0;
	//}}AFX_DATA_INIT
}


void m_AddSight::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(m_AddSight)
	DDX_Text(pDX, IDC_EDIT1, m_SightName);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(m_AddSight, CDialog)
	//{{AFX_MSG_MAP(m_AddSight)
	ON_BN_CLICKED(IDC_CONFIRM, OnConfirm)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// m_AddSight message handlers

void m_AddSight::OnConfirm() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	bool b_c = true;
	POSITION head = l_Sight.GetHeadPosition();
	if(m_CurSight <= m_ISight){
		while(head){
			if(l_Sight.GetAt(head) == m_SightName){
				b_c = false;
				break;
			}
			l_Sight.GetNext(head);
			}
			if(b_c){
				l_Sight.AddTail(m_SightName);
				AfxMessageBox("添加成功");
			}
			else{
				AfxMessageBox("你的地点已经输过一次了请不要再重复输入");
			}
		}
			
		
	
	else{
		AfxMessageBox("你的输入地点已经超了");
	}
}

