#pragma once


// CTeacherADDGUI 对话框

class CTeacherADDGUI : public CDialogEx
{
	DECLARE_DYNAMIC(CTeacherADDGUI)

public:
	CTeacherADDGUI(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CTeacherADDGUI();

// 对话框数据
	enum { IDD = IDD_DIALOG13 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton3();
	int m_GUInumber;
	CString m_GUIname;
	CString m_GUIsex;
	CString m_GUIdepart;
	afx_msg void OnBnClickedButton4();
};
