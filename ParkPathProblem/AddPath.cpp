// AddPath.cpp : implementation file
//

#include "stdafx.h"
#include "ParkPathProblem.h"
#include "AddPath.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// AddPath dialog


AddPath::AddPath(CWnd* pParent /*=NULL*/)
	: CDialog(AddPath::IDD, pParent)
{
	memset(a,0,sizeof(a));
	//{{AFX_DATA_INIT(AddPath)
	m_OrigalPath = _T("");
	m_EndPath = _T("");
	m_LengthPath = 0;
	//}}AFX_DATA_INIT
}


void AddPath::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(AddPath)
	DDX_CBString(pDX, IDC_COMBO1, m_OrigalPath);
	DDX_CBString(pDX, IDC_COMBO2, m_EndPath);
	DDX_Text(pDX, IDC_EDIT1, m_LengthPath);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(AddPath, CDialog)
	//{{AFX_MSG_MAP(AddPath)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// AddPath message handlers
