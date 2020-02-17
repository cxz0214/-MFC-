#pragma once


// CclassAdd 对话框

class CclassAdd : public CDialogEx
{
	DECLARE_DYNAMIC(CclassAdd)

public:
	CclassAdd(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CclassAdd();

// 对话框数据
	enum { IDD = IDD_DIALOG17 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

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
