#pragma once


// CStudyModify �Ի���

class CStudyModify : public CDialogEx
{
	DECLARE_DYNAMIC(CStudyModify)

public:
	CStudyModify(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CStudyModify();

// �Ի�������
	enum { IDD = IDD_DIALOG11 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	int m_GUInumber;
	CString m_GUIname;
	int m_GUIclass;
	short m_GUIseril;
	CString m_GUIdepartment;
	CString m_GUImajor;
	float m_GUIgpa;
	afx_msg void OnBnClickedButton5();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton7();
};
