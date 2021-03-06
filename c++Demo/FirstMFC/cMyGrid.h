#pragma once


// cMyGrid 对话框

class cMyGrid : public CDialogEx
{
	DECLARE_DYNAMIC(cMyGrid)

public:
	cMyGrid(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~cMyGrid();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	HICON m_hIcon;

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_grid;
	CButton m_addBtn;
	CButton m_editBtn;
	CButton m_delBtn;
	afx_msg void OnLvnItemchangedList2(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton2();
};
