#pragma once


// CAddNormalUser �Ի���

class CAddNormalUser : public CDialogEx
{
	DECLARE_DYNAMIC(CAddNormalUser)

public:
	CAddNormalUser(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CAddNormalUser();

// �Ի�������
	enum { IDD = IDD_DIALOG4 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	int m_normal_user;
	CString m_normal_password;
};
