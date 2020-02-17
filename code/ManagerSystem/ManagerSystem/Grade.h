#pragma once


// CGrade 对话框

class CGrade : public CDialogEx
{
	DECLARE_DYNAMIC(CGrade)

public:
	CGrade(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CGrade();

// 对话框数据
	enum { IDD = IDD_DIALOG18 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

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
