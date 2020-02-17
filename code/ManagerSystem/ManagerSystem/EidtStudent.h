#pragma once


// CEidtStudent 对话框

class CEidtStudent : public CDialogEx
{
	DECLARE_DYNAMIC(CEidtStudent)

public:
	CEidtStudent(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CEidtStudent();

// 对话框数据
	enum { IDD = IDD_DIALOG9 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int m_eidt_number;
	CString m_edit_name;
	CString m_edit_sex;
	int m_year;
	int m_month;
	int m_day;
	CString m_nation;
	CString m_id;
	CString m_plot;
	CString m_place;
	int m_enter_year;
	int m_enter_month;
	int m_enter_day;
	afx_msg void OnBnClickedButton12();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton2();
};
