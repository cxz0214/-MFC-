#pragma once
#include "afxcmn.h"
#include "admin_login.h"

// CDeleteAdmin �Ի���

class CDeleteAdmin : public CDialogEx
{
	DECLARE_DYNAMIC(CDeleteAdmin)

public:
	CDeleteAdmin(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDeleteAdmin();
	void DeleteCount(Cadmin_login* set, CString username);

// �Ի�������
	enum { IDD = IDD_DIALOG3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_re_user;
	CListCtrl m_reult_list;
	afx_msg void OnBnClickedButton1();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
};
