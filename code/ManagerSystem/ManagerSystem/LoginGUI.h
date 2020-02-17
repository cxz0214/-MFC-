#pragma once
#include "afxwin.h"
#include "admin_login.h"

// CLoginGUI 对话框

class CLoginGUI : public CDialogEx
{
	DECLARE_DYNAMIC(CLoginGUI)

public:
	CLoginGUI(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CLoginGUI();
private:

	

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CComboBox m_change;
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnClose();
	CString m_uiAdmin;
	CString m_uiAdminPassword;
};
