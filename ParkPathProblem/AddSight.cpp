// AddSight.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ParkPathProblem.h"
#include "AddSight.h"
#include "afxdialogex.h"


// CAddSight �Ի���

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


// CAddSight ��Ϣ�������


void CAddSight::OnBnClickedConfirm()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	bool b_flat = TRUE;
	if (m_CurSight <m_Sight){
	if (m_SightName == ""){
		AfxMessageBox(_T("��������е�����"));
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
				AfxMessageBox(_T("������ӳɹ�"));
				++m_CurSight;
			}
			else{
				AfxMessageBox(_T("�벻Ҫ�ظ�����"));
			}

		}
	}
	}
	else
	{
		AfxMessageBox(_T("������ľ��㳬��"));
	}
}


void CAddSight::OnOK()
{
	// TODO:  �ڴ����ר�ô����/����û���
	if (m_CurSight == m_Sight){
		CDialogEx::OnOK();
	}
	else if(m_CurSight < m_Sight){
		AfxMessageBox(_T("������ľ���������"));
	}
	else{
		AfxMessageBox(_T("������ľ���������"));
	}
}


void CAddSight::OnBnClickedYes()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	if (m_CurSight == m_Sight){
		AfxMessageBox(_T("��Ӿ���ɹ�"));
		b_AddSuccess = TRUE;
		EndDialog(TRUE);
	}
	else{
		AfxMessageBox(_T("��Ӿ���ʧ�������¼������"));
	}
}


void CAddSight::OnBnClickedReadd()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	l_Sight.RemoveAll();
	m_CurSight = 0;
}
