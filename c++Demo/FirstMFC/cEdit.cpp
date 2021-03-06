// cEdit.cpp: 实现文件
//

#include "stdafx.h"
#include "FirstMFC.h"
#include "cEdit.h"
#include "afxdialogex.h"


// cEdit 对话框

IMPLEMENT_DYNAMIC(cEdit, CDialogEx)

cEdit::cEdit(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG2, pParent)
	, m_txtNo(_T(""))
	, m_txtPrice(0)
	, m_txtUser(_T(""))
	, m_txtPhone(_T(""))
{

}

cEdit::~cEdit()
{
}

CString add_change_caption;


void cEdit::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_txtNo);
	DDX_Text(pDX, IDC_EDIT7, m_txtDateTime);
	DDX_Text(pDX, IDC_EDIT6, m_txtPrice);
	DDX_Text(pDX, IDC_EDIT2, m_txtUser);
	DDX_Text(pDX, IDC_EDIT8, m_txtPhone);
}



BOOL cEdit::OnInitDialog()
{
	CDialog::OnInitDialog();


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


	UpdateData(true);
	// TODO:  在此添加额外的初始化
		///将按钮标题设置为添加/修改
	GetDlgItem(IDOK)->SetWindowTextW(add_change_caption);
	//添加此句的原因是点击“修改”按钮时可以将选中数据变为编辑框初始数据
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}



void cEdit::OnSysCommand(UINT nID, LPARAM lParam)
{
	CDialogEx::OnSysCommand(nID, lParam);
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void cEdit::OnPaint()
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
HCURSOR cEdit::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



BEGIN_MESSAGE_MAP(cEdit, CDialogEx)
END_MESSAGE_MAP()


// cEdit 消息处理程序
