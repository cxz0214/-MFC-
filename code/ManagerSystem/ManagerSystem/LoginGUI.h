#pragma once
#include "afxwin.h"
#include "admin_login.h"

// CLoginGUI �Ի���

class CLoginGUI : public CDialogEx
{
	DECLARE_DYNAMIC(CLoginGUI)

public:
	CLoginGUI(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CLoginGUI();
private:

	

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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
