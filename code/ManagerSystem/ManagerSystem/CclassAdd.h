#pragma once


// CclassAdd �Ի���

class CclassAdd : public CDialogEx
{
	DECLARE_DYNAMIC(CclassAdd)

public:
	CclassAdd(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CclassAdd();

// �Ի�������
	enum { IDD = IDD_DIALOG17 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton4();
	int m_classnum;
	int m_tnum;
	CString m_classname_G;
	CString m_opendepart;
	float m_credit;
	afx_msg void OnBnClickedButton5();
};
