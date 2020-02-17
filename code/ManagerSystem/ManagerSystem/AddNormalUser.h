#pragma once


// CAddNormalUser 对话框

class CAddNormalUser : public CDialogEx
{
	DECLARE_DYNAMIC(CAddNormalUser)

public:
	CAddNormalUser(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CAddNormalUser();

// 对话框数据
	enum { IDD = IDD_DIALOG4 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	int m_normal_user;
	CString m_normal_password;
};
