#pragma once


// CGrade �Ի���

class CGrade : public CDialogEx
{
	DECLARE_DYNAMIC(CGrade)

public:
	CGrade(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CGrade();

// �Ի�������
	enum { IDD = IDD_DIALOG18 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	int m_number;
	CString m_name;
	CString m_department;
	CString m_classname;
	int m_grade;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();
	void updatelist();
};
