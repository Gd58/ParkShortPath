// AddSightPath.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ParkPathProblem.h"
#include "AddSightPath.h"
#include "afxdialogex.h"


// AddSightPath �Ի���

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


// AddSightPath ��Ϣ�������
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
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	int SourRoute = GetKeyByValue(SightNameToIndex, m_Sight1);
	int DestRoute = GetKeyByValue(SightNameToIndex, m_Sight2);
	if (atof(m_distance.GetBuffer())){
	
	if (m_CurPath < m_SumPath){
	if (SourRoute == DestRoute){ AfxMessageBox(_T("��㲻�����յ�һ��")); }
	else{
		if (a[SourRoute][DestRoute]||a[DestRoute][SourRoute]){
			AfxMessageBox(_T("���Ѿ���������������ص����"));

		}
		else{
			a[SourRoute][DestRoute] = atof(m_distance.GetBuffer());
			a[DestRoute][SourRoute] = atof(m_distance.GetBuffer());
			++m_CurPath;
			CString str = "�����" + m_Sight1+"��"+m_Sight2+"·���ɹ�";
			
			AfxMessageBox(str);
		}
	}
	}
	else{
		AfxMessageBox(_T("����ӵ�·���Ѿ�����"));
	}
	}
	else{
		AfxMessageBox(_T("·�����Ȳ���Ϊ0"));
	}
}


BOOL AddSightPath::OnInitDialog()
{

	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	POSITION head = l_Sight.GetHeadPosition();

	while (head){
	((CComboBox*)GetDlgItem(IDC_COMBO1))->AddString(l_Sight.GetAt(head));
	((CComboBox*)GetDlgItem(IDC_COMBO2))->AddString(l_Sight.GetAt(head));
	l_Sight.GetNext(head);
	}
		
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}


void AddSightPath::OnBnClickedReaddpath()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_CurPath = 0;
	memset(a, 0, sizeof(a));
}


void AddSightPath::OnBnClickedPathyes()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	if (m_CurPath == m_SumPath){
		AfxMessageBox(_T("·����ӳɹ�"));
		b_AddSucess = TRUE;
		EndDialog(TRUE);
	}
	else{
		AfxMessageBox(_T("·�����ʧ����������"));
	}
}