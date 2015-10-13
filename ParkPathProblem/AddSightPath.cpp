// AddSightPath.cpp : 实现文件
//

#include "stdafx.h"
#include "ParkPathProblem.h"
#include "AddSightPath.h"
#include "afxdialogex.h"


// AddSightPath 对话框

IMPLEMENT_DYNAMIC(AddSightPath, CDialog)

AddSightPath::AddSightPath(CList<CString,CString>& lhs,UINT iPath,CWnd* pParent /*=NULL*/)
	: CDialog(AddSightPath::IDD, pParent)
	, m_Sight1(_T(""))
	, m_Sight2(_T(""))
	, m_CurPath(0)
	, m_distance(_T(""))
{
	b_AddSucess = FALSE;
	m_SumPath = iPath;
	POSITION head = lhs.GetHeadPosition();
	int i = 0;
	memset(a, 0, sizeof(a));
	l_SightName.RemoveAll();
	SightNameToIndex.RemoveAll();
	if (head){
		while (head){
			l_Sight.AddTail(lhs.GetAt(head));
			SightNameToIndex.SetAt(i,lhs.GetAt(head));
			lhs.GetNext(head);
			++i;

		}
	}
	
}

AddSightPath::~AddSightPath()
{
}

void AddSightPath::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_CBString(pDX, IDC_COMBO1, m_Sight1);
	DDX_CBString(pDX, IDC_COMBO2, m_Sight2);
	DDX_Text(pDX, IDC_EDIT1, m_distance);
}


BEGIN_MESSAGE_MAP(AddSightPath, CDialog)
	ON_BN_CLICKED(IDC_CONFRIM, &AddSightPath::OnBnClickedConfrim)
	ON_BN_CLICKED(IDC_READDPATH, &AddSightPath::OnBnClickedReaddpath)
	ON_BN_CLICKED(IDC_PATHYES, &AddSightPath::OnBnClickedPathyes)
END_MESSAGE_MAP()


// AddSightPath 消息处理程序
int GetKeyByValue(CMap<int, int, CString, CString>& lhs, CString str){
	int count = lhs.GetCount();
	--count;
	while (count >= 0){
		if (lhs[count] == str){
			break;
			
		}
		--count;

	}
	return count;
}

void AddSightPath::OnBnClickedConfrim()
{
	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
	int SourRoute = GetKeyByValue(SightNameToIndex, m_Sight1);
	int DestRoute = GetKeyByValue(SightNameToIndex, m_Sight2);
	if (atof(m_distance.GetBuffer())){
	
	if (m_CurPath < m_SumPath){
	if (SourRoute == DestRoute){ AfxMessageBox(_T("起点不能与终点一致")); }
	else{
		if (a[SourRoute][DestRoute]||a[DestRoute][SourRoute]){
			AfxMessageBox(_T("您已经输入过了这两个地点距离"));

		}
		else{
			a[SourRoute][DestRoute] = atof(m_distance.GetBuffer());
			a[DestRoute][SourRoute] = atof(m_distance.GetBuffer());
			++m_CurPath;
			CString str = "你添加" + m_Sight1+"到"+m_Sight2+"路径成功";
			
			AfxMessageBox(str);
		}
	}
	}
	else{
		AfxMessageBox(_T("你添加的路径已经超了"));
	}
	}
	else{
		AfxMessageBox(_T("路径长度不能为0"));
	}
}


BOOL AddSightPath::OnInitDialog()
{

	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	POSITION head = l_Sight.GetHeadPosition();

	while (head){
	((CComboBox*)GetDlgItem(IDC_COMBO1))->AddString(l_Sight.GetAt(head));
	((CComboBox*)GetDlgItem(IDC_COMBO2))->AddString(l_Sight.GetAt(head));
	l_Sight.GetNext(head);
	}
		
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}


void AddSightPath::OnBnClickedReaddpath()
{
	// TODO:  在此添加控件通知处理程序代码
	m_CurPath = 0;
	memset(a, 0, sizeof(a));
}


void AddSightPath::OnBnClickedPathyes()
{
	// TODO:  在此添加控件通知处理程序代码
	if (m_CurPath == m_SumPath){
		AfxMessageBox(_T("路径添加成功"));
		b_AddSucess = TRUE;
		EndDialog(TRUE);
	}
	else{
		AfxMessageBox(_T("路径添加失败请继续添加"));
	}
}