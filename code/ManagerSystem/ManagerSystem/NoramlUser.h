#pragma once


// CNoramlUser �Ի���

class CNoramlUser : public CDialogEx
{
	DECLARE_DYNAMIC(CNoramlUser)

public:
	CNoramlUser(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CNoramlUser();

// �Ի�������
	enum { IDD = IDD_DIALOG20 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	int m_GUIUser;
	CString m_GUIPassword;
	afx_msg void OnBnClickedButton1();
};
