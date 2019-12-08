// ������Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "������.h"
#include "������Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

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
// CMyDlg dialog

CMyDlg::CMyDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMyDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMyDlg)
	m_value1 = 0;
	m_value2 = 0;
	m_result = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMyDlg)
	DDX_Control(pDX, IDC_EDIT3, m_CResult);
	DDX_Control(pDX, IDC_BUTTON15, m_equal);
	DDX_Control(pDX, IDC_BUTTON14, m_divide);
	DDX_Control(pDX, IDC_BUTTON13, m_times);
	DDX_Control(pDX, IDC_BUTTON12, m_minus);
	DDX_Control(pDX, IDC_BUTTON11, m_plus);
	DDX_Control(pDX, IDC_BUTTON10, m_0);
	DDX_Control(pDX, IDC_BUTTON9, m_9);
	DDX_Control(pDX, IDC_BUTTON8, m_8);
	DDX_Control(pDX, IDC_BUTTON7, m_7);
	DDX_Control(pDX, IDC_BUTTON6, m_6);
	DDX_Control(pDX, IDC_BUTTON5, m_5);
	DDX_Control(pDX, IDC_BUTTON4, m_4);
	DDX_Control(pDX, IDC_BUTTON2, m_2);
	DDX_Control(pDX, IDC_BUTTON1, m_1);
	DDX_Control(pDX, IDC_BUTTON3, m_3);
	DDX_Text(pDX, IDC_EDIT1, m_value1);
	DDV_MinMaxInt(pDX, m_value1, 0, 99999);
	DDX_Text(pDX, IDC_EDIT2, m_value2);
	DDV_MinMaxInt(pDX, m_value2, 0, 99999);
	DDX_Text(pDX, IDC_EDIT3, m_result);
	DDV_MinMaxInt(pDX, m_result, 0, 999999);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMyDlg, CDialog)
	//{{AFX_MSG_MAP(CMyDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON11, OnButton11)
	ON_BN_CLICKED(IDC_BUTTON12, OnButton12)
	ON_BN_CLICKED(IDC_BUTTON13, OnButton13)
	ON_BN_CLICKED(IDC_BUTTON14, OnButton14)
	ON_EN_CHANGE(IDC_EDIT1, OnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT3, OnChangeEdit3)
	ON_EN_SETFOCUS(IDC_EDIT1, OnSetfocusEdit1)
	ON_EN_SETFOCUS(IDC_EDIT2, OnSetfocusEdit2)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyDlg message handlers

BOOL CMyDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
    nEditFlag=0;//���
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

void CMyDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMyDlg::OnPaint() 
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
HCURSOR CMyDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMyDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	if( nEditFlag==1)
	{
		m_1=m_1*10+1;
	}
    else if( nEditFlag==2)
	{
		m_1=m_1*10+1;
	}
    UpdateData(false)

}

void CMyDlg::OnButton11() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
int n_result;
n_result = m_value1 + m_value2;
m_result = n_result;
char sz[20];
sprintf(sz,"%d",m_result);
m_CResult.SetWindowText(sz);
}

void CMyDlg::OnButton12() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
int n_result;
n_result = m_value1 - m_value2;
m_result = n_result;
m_CResult.SetWindowText(sz);
char sz[20];
sprintf(sz,"%d",m_result);
}

void CMyDlg::OnButton13() 
{
	// TODO: Add your control notification handler code here
		UpdateData(true);
int n_result;
n_result = m_value1 * m_value2;
m_result = n_result;
m_CResult.SetWindowText(sz);
char sz[20];
sprintf(sz,"%d",m_result);
}

void CMyDlg::OnButton14() 
{
	// TODO: Add your control notification handler code here
		UpdateData(true);
int n_result;
n_result = m_value1 / m_value2;
m_result = n_result;
m_CResult.SetWindowText(sz);
char sz[20];
sprintf(sz,"%d",m_result);
}





void CMyDlg::OnSetfocusEdit1() 
{
	// TODO: Add your control notification handler code here
	nEditFlag=1;
}

void CMyDlg::OnSetfocusEdit2() 
{
	// TODO: Add your control notification handler code here
	nEditFlag=2;
}
void CMyDlg::OnLButtonDown(UINT nFlags,CPoint point)
{
	this->SetFocus();
	nEditFlag=0;
	CDialog::OnLButtonDown(nFlags,point);
}








void CMyDlg::OnButton2() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	if( nEditFlag==1)
	{
		m_1=m_1*10+2;
	}
    else if( nEditFlag==2)
	{
		m_2=m_2*10+2;
	}
    UpdateData(false)	
}
