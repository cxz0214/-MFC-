#pragma once


// AddAdmin �Ի���

class AddAdmin : public CDialogEx
{
	DECLARE_DYNAMIC(AddAdmin)

public:
	AddAdmin(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~AddAdmin();

// �Ի�������
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_ui_admin_user;
	CString m_ui_password;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnClose();
};
