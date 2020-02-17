#pragma once
#include "afxcmn.h"
#include "admin_login.h"

// CDeleteAdmin 对话框

class CDeleteAdmin : public CDialogEx
{
	DECLARE_DYNAMIC(CDeleteAdmin)

public:
	CDeleteAdmin(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDeleteAdmin();
	void DeleteCount(Cadmin_login* set, CString username);

// 对话框数据
	enum { IDD = IDD_DIALOG3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_re_user;
	CListCtrl m_reult_list;
	afx_msg void OnBnClickedButton1();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
};
