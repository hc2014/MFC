#pragma once


// cEdit 对话框

class cEdit : public CDialogEx
{
	DECLARE_DYNAMIC(cEdit)

public:
	cEdit(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~cEdit();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
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
	CString add_change_caption;
	CString m_txtNo;
	CString m_txtDateTime;
	double m_txtPrice;
	CString m_txtUser;
	CString m_txtPhone;
};
