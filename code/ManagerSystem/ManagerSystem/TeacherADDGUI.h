#pragma once


// CTeacherADDGUI �Ի���

class CTeacherADDGUI : public CDialogEx
{
	DECLARE_DYNAMIC(CTeacherADDGUI)

public:
	CTeacherADDGUI(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CTeacherADDGUI();

// �Ի�������
	enum { IDD = IDD_DIALOG13 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton3();
	int m_GUInumber;
	CString m_GUIname;
	CString m_GUIsex;
	CString m_GUIdepart;
	afx_msg void OnBnClickedButton4();
};
