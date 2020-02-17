#pragma once


// AddAdmin 对话框

class AddAdmin : public CDialogEx
{
	DECLARE_DYNAMIC(AddAdmin)

public:
	AddAdmin(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~AddAdmin();

// 对话框数据
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_ui_admin_user;
	CString m_ui_password;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnClose();
};
