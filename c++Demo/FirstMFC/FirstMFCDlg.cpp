
// FirstMFCDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "FirstMFC.h"
#include "FirstMFCDlg.h"
#include "afxdialogex.h""

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CFirstMFCDlg 对话框



CFirstMFCDlg::CFirstMFCDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_FIRSTMFC_DIALOG, pParent)
	, txtFirstParam(0)
	, txtSecParam(0)
	, m_opearCombobox(_T(""))
	, m_txtResult(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFirstMFCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT5, txtFirstParam);
	DDX_Text(pDX, IDC_EDIT3, txtSecParam);
	DDX_CBString(pDX, IDC_COMBO1, m_opearCombobox);
	DDX_Text(pDX, IDC_EDIT4, m_txtResult);
	DDX_Control(pDX, IDC_COMBO1, m_operaCombobox);
}

BEGIN_MESSAGE_MAP(CFirstMFCDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CFirstMFCDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CFirstMFCDlg 消息处理程序

BOOL CFirstMFCDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	m_operaCombobox.InsertString(0, _T("+"));
	m_operaCombobox.InsertString(1,_T("-"));
	m_operaCombobox.InsertString(2,_T("*"));
	m_operaCombobox.InsertString(3,_T("/"));

	m_operaCombobox.SelectString(0, _T("+"));


		/*((CComboBox*)GetDlgItem(IDC_COMBO1))->AddString();*/

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CFirstMFCDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CFirstMFCDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CFirstMFCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CFirstMFCDlg::OnBnClickedButton1()
{

	int selectIndex=m_operaCombobox.GetCurSel();

	UpdateData(TRUE);

	switch (selectIndex)
	{
	case 0:
		m_txtResult = txtFirstParam + txtSecParam;
		break;
	case 1:
		m_txtResult = txtFirstParam - txtSecParam;
		break;
	case 2:
		m_txtResult = txtFirstParam * txtSecParam;
		break;
	case 3:
		m_txtResult = txtFirstParam / txtSecParam;
		break;
	default:
		break;
	}
	UpdateData(FALSE);
}
