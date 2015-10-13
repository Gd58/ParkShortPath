// ParkPathProblemDlg.cpp : implementation file
//
#include "stdafx.h"
#include "ParkPathProblem.h"
#include "ParkPathProblemDlg.h"
#include "AddSight.h"
#include "AddSightPath.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About
int GetKeyByValue1(CMap<int, int, CString, CString>& lhs, CString str){
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
class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CParkPathProblemDlg dialog

CParkPathProblemDlg::CParkPathProblemDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CParkPathProblemDlg::IDD, pParent)
	, m_OrigalSightName(_T(""))
	, m_EndName(_T(""))
{
	//{{AFX_DATA_INIT(CParkPathProblemDlg)
	double Max = 97654;
	for (int i = 0; i < 7;++i)
	for (int j = 0; j < 7; ++j)
		a[i][j] = Max;
	m_SumPath = 0;
	m_SumSight = 0;
	b_OrigalEndSuccess = false;
	m_bAddPath = false;
	m_bAddSight = false;
	point1.x = 300; point1.y = 145;
	point2.x = 550; point2.y = 175;
	point3.x = 123; point3.y = 257;
	point4.x = 350; point4.y = 200;
	point5.x = 650; point5.y = 280;
	point6.x = 230; point6.y = 330;
	point7.x = 480; point7.y = 380;
	//}}AFX_DATA_INIT
	IndexToPoint.SetAt(0, point1);
	IndexToPoint.SetAt(1, point2);
	IndexToPoint.SetAt(2, point3);
	IndexToPoint.SetAt(3, point4);
	IndexToPoint.SetAt(4, point5);
	IndexToPoint.SetAt(5, point6);
	IndexToPoint.SetAt(6, point7);

	memset(Path, 0, sizeof(Path));

	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	//  m_BeginName = _T("");
	OriginIndex = 0;
	EndIndex = 0;
}

void CParkPathProblemDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CParkPathProblemDlg)
	DDX_Text(pDX, IDC_SUMPATH, m_SumPath);
	DDX_Text(pDX, IDC_SUMSIGHT, m_SumSight);
	//}}AFX_DATA_MAP
	DDX_CBString(pDX, IDC_COMBO1, m_OrigalSightName);
	DDX_CBString(pDX, IDC_COMBO2, m_EndName);
}

BEGIN_MESSAGE_MAP(CParkPathProblemDlg, CDialog)
	//{{AFX_MSG_MAP(CParkPathProblemDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ADDPATH, OnAddpath)
	ON_BN_CLICKED(IDC_ADDSIGHT, OnAddsight)
	ON_BN_CLICKED(IDC_DRAW, OnDraw)
	//}}AFX_MSG_MAP
	ON_WM_MOUSEMOVE()
	ON_BN_CLICKED(IDC_STARTEND, &CParkPathProblemDlg::OnBnClickedStartend)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CParkPathProblemDlg message handlers

BOOL CParkPathProblemDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);


	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CParkPathProblemDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CParkPathProblemDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CParkPathProblemDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CParkPathProblemDlg::OnAddpath() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	double Max = 97654;
	
	if (m_bAddSight == TRUE){
		if (m_SumPath){
		AddSightPath addsightpath(l_SightName,m_SumPath);
		addsightpath.DoModal();
		//Get Data 
		for (int i = 0; i < 7;++i)
			for (int j = 0; j < 7; ++j){
				if (addsightpath.a[i][j])
				a[i][j] = addsightpath.a[i][j];

		}
			m_bAddPath = addsightpath.b_AddSucess;
		}
		else{
			AfxMessageBox(_T("路径总数不能为零"));
		}
	}
	else{
		AfxMessageBox(_T("请先添加景点"));
	}

}

void CParkPathProblemDlg::OnAddsight()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if (m_SumSight){
	CAddSight addsight(m_SumSight);
	addsight.DoModal();
	m_bAddSight = addsight.b_AddSuccess;
	POSITION head = addsight.l_Sight.GetHeadPosition();
	int i = 0;
	while (head){
		l_SightName.AddTail(addsight.l_Sight.GetAt(head));
		
		((CComboBox*)(GetDlgItem(IDC_COMBO1)))->AddString(addsight.l_Sight.GetAt(head));
		((CComboBox*)(GetDlgItem(IDC_COMBO2)))->AddString(addsight.l_Sight.GetAt(head));
		IndexToSight[i] = addsight.l_Sight.GetAt(head);
			addsight.l_Sight.GetNext(head);
			++i;
	}
	
}
else{
	AfxMessageBox(_T("景点数不能为0"));
}

}

void CParkPathProblemDlg::OnDraw() 
{
	//Invalidate(TRUE);
	CClientDC dc(this);

	for (int i = 0; i < 7;++i)
	for (int j = 0; j < 7; ++j)
		b[i][j] = 0;
	double Max = 97654;
	// TODO: Add your control notification handler code here
	if (m_bAddPath&&m_bAddSight&&b_OrigalEndSuccess)
	{
		//To do Draw
		for (int i = 0; i < m_SumSight; ++i){
			
			dc.TextOut(IndexToPoint[i].x,IndexToPoint[i].y,l_SightName.GetAt(l_SightName.FindIndex(i)));
			for (int j = i + 1; j < m_SumSight; ++j){
				if (a[i][j] != Max){
					dc.MoveTo(IndexToPoint[i]);
					dc.LineTo(IndexToPoint[j]);
				}
			}
		}

		ShortPath();
		CPen newPen;
		CPen* oldPen;
		newPen.CreatePen(PS_SOLID, 3, RGB(255, 0, 0));
		oldPen = dc.SelectObject(&newPen);
		for (int i = 0; i < m_SumSight;++i)
		for (int j = 0; j < m_SumSight; ++j){
			if (b[i][j]){
				dc.MoveTo(IndexToPoint[i]);
				dc.LineTo(IndexToPoint[j]);
			}
		}

		dc.SelectObject(&oldPen);

	}
	else{
		AfxMessageBox(_T("路径信息或者景点信息不完整！！！"));
	}
}


void CParkPathProblemDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值

	CClientDC dc(this);
	CString CurStr;
	CurStr.Format("x = %d, y = %d", point.x, point.y);
	dc.TextOut(650, 10, CurStr);
	CDialog::OnMouseMove(nFlags, point);
}


void CParkPathProblemDlg::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码
	
}


void CParkPathProblemDlg::OnBnClickedStartend()
{
	// TODO:  在此添加控件通知处理程序代码

	UpdateData(TRUE);
	
	if (m_bAddSight){
		if (m_OrigalSightName == m_EndName){
			AfxMessageBox(_T("起始终点不能一致请重新设置"));

			}
		else{
			b_OrigalEndSuccess = TRUE;
			OriginIndex = GetKeyByValue1(IndexToSight, m_OrigalSightName);
			EndIndex = GetKeyByValue1(IndexToSight, m_EndName);
			AfxMessageBox(_T("起终点设置成功！！！！"));
			Invalidate();
		}
	}

	else{
		AfxMessageBox(_T("请先添加景点在设置初始位置"));
	}

	

}


void CParkPathProblemDlg::ShortPath()
{
	for (int i = 0; i < 7;++i)
	for (int j = 0; j < 7; ++j)
		b[i][j] = 0;
	BOOL b_s[7];
	double dest[7];
	double Max = 97654;
	for (int i = 0; i < m_SumSight; ++i){
		
			dest[i] = a[OriginIndex][i];
			b_s[i] = FALSE;
			if (dest[i] == Max)
				Path[i] = -1;
			else
				Path[i] = OriginIndex;
	}
	dest[OriginIndex] = 0;
	b_s[OriginIndex] = TRUE;

	for (int i = 1; i < m_SumSight; ++i){
		double mindist = Max;
		int midSight = OriginIndex;
		for (int j = 0; j < m_SumSight; ++j){
			if (!b_s[j] && dest[j] < mindist){
				midSight = j;
				mindist = dest[j];
			}
			b_s[midSight] = TRUE;
			if (midSight == EndIndex)
				break;
			
			for (int t = 0; t < m_SumSight; ++t){
				if (!b_s[t] && a[midSight][t] < Max){

					if (dest[midSight] + a[midSight][t] < dest[t]){
						dest[t] = a[midSight][t] + dest[midSight];
						Path[t] = midSight;
					}
				}
			}

		}
	}		
	int record[7];
	memset(record, 0, sizeof(record));
	int start;
	int end = EndIndex;
	int i = 0;
	while (Path[end] != -1){
		start = end;
		end = Path[end];
		b[start][end] = b[end][start] = 1;
	}
}
