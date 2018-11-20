
// FirstMFCDlg.h: 头文件
//

#pragma once


// CFirstMFCDlg 对话框
class CFirstMFCDlg : public CDialogEx
{
// 构造
public:
	CFirstMFCDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FIRSTMFC_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	double txtFirstParam;
	double txtSecParam;
	CString m_opearCombobox;
	double m_txtResult;
	CComboBox m_operaCombobox;
};
