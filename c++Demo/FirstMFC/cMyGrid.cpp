// cMyGrid.cpp: 实现文件
//

#include "stdafx.h"
#include "FirstMFC.h"
#include "cMyGrid.h"
#include "afxdialogex.h"
#include "cEdit.h"

// cMyGrid 对话框

IMPLEMENT_DYNAMIC(cMyGrid, CDialogEx)

cMyGrid::cMyGrid(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

cMyGrid::~cMyGrid()
{
}

void cMyGrid::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST2, m_grid);
	DDX_Control(pDX, IDC_BUTTON1, m_addBtn);
	DDX_Control(pDX, IDC_BUTTON2, m_editBtn);
	DDX_Control(pDX, IDC_BUTTON3, m_delBtn);
}


BOOL cMyGrid::OnInitDialog()
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

	// TODO: 在此添加额外的初始化代码

	//添加表格网络线  选中高亮
	m_grid.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES| LVS_EX_CHECKBOXES);

	m_grid.InsertColumn(0,_T("订单编号"), LVCFMT_CENTER,100);
	m_grid.InsertColumn(1, _T("订单时间"), LVCFMT_CENTER,180);
	m_grid.InsertColumn(2, _T("订单价格"), LVCFMT_RIGHT,80);
	m_grid.InsertColumn(3, _T("收件人"), LVCFMT_LEFT,120);
	m_grid.InsertColumn(4, _T("电话"), LVCFMT_LEFT,140);


	m_grid.InsertItem(0, _T("1001"));
	m_grid.SetItemText(0,1, _T("2018-01-01 11:11:11"));
	m_grid.SetItemText(0, 2,_T("15.5"));
	m_grid.SetItemText(0, 3,_T("王大麻子"));
	m_grid.SetItemText(0, 4,_T("13088888888"));


	m_grid.InsertItem(1, _T("1002"));
	m_grid.SetItemText(1, 1, _T("2018-01-01 00:00:01"));
	m_grid.SetItemText(1, 2, _T("23.5"));
	m_grid.SetItemText(1, 3, _T("王二麻子"));
	m_grid.SetItemText(1, 4, _T("13188888888"));

	GetDlgItem(IDC_BUTTON2)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON3)->EnableWindow(FALSE);


	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}



void cMyGrid::OnSysCommand(UINT nID, LPARAM lParam)
{
	CDialogEx::OnSysCommand(nID, lParam);
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void cMyGrid::OnPaint()
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
HCURSOR cMyGrid::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



BEGIN_MESSAGE_MAP(cMyGrid, CDialogEx)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST2, &cMyGrid::OnLvnItemchangedList2)
	ON_BN_CLICKED(IDC_BUTTON1, &cMyGrid::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &cMyGrid::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON2, &cMyGrid::OnBnClickedButton2)
END_MESSAGE_MAP()


// cMyGrid 消息处理程序


void cMyGrid::OnLvnItemchangedList2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码

	GetDlgItem(IDC_BUTTON2)->EnableWindow(TRUE);     //使修改按钮为可选状态
	GetDlgItem(IDC_BUTTON3)->EnableWindow(TRUE);
	*pResult = 0;
}


void cMyGrid::OnBnClickedButton1()
{
	cEdit dlg;
	dlg.add_change_caption = L"新增";
	if (dlg.DoModal() == IDOK)
	{

		int i = m_grid.GetItemCount();
		CString m_c_price;
		double m_d_price = dlg.m_txtPrice;
		m_c_price.Format(_T("%.4lf"), m_d_price);

		m_grid.InsertItem(i, dlg.m_txtNo);     //插入一行，并设置该行第一个数据
		m_grid.SetItemText(i, 1, dlg.m_txtDateTime); //设置第0行第1列数据
		m_grid.SetItemText(i, 2, m_c_price);
		m_grid.SetItemText(i, 3, dlg.m_txtUser);
		m_grid.SetItemText(i, 4, dlg.m_txtPhone);
	}
}


void cMyGrid::OnBnClickedButton3()
{
	int index = m_grid.GetNextItem(-1, LVNI_SELECTED);
	m_grid.DeleteItem(index);
}


void cMyGrid::OnBnClickedButton2()
{
	cEdit dlg;
	dlg.add_change_caption = L"修改";

	int index = m_grid.GetNextItem(-1, LVNI_SELECTED);


	dlg.m_txtNo = m_grid.GetItemText(index, 0);
	dlg.m_txtDateTime = m_grid.GetItemText(index, 1);
	dlg.m_txtPrice = _ttof(m_grid.GetItemText(index, 2));
	dlg.m_txtUser = m_grid.GetItemText(index, 3);
	dlg.m_txtPhone = m_grid.GetItemText(index, 4);

	if (dlg.DoModal() == IDOK)
	{
		int i = m_grid.GetItemCount();

		CString m_c_price;
		double m_d_price = dlg.m_txtPrice;
		m_c_price.Format(_T("%.4lf"), m_d_price);

		m_grid.InsertItem(i, dlg.m_txtNo);     //插入一行，并设置该行第一个数据
		m_grid.SetItemText(i, 1, dlg.m_txtDateTime); //设置第0行第1列数据
		m_grid.SetItemText(i, 2, m_c_price);
		m_grid.SetItemText(i, 3, dlg.m_txtUser);
		m_grid.SetItemText(i, 4, dlg.m_txtPhone);
	}
}
