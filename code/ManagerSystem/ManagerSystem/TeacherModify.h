#pragma once


// CTeacherModify 对话框

class CTeacherModify : public CDialogEx
{
	DECLARE_DYNAMIC(CTeacherModify)

public:
	CTeacherModify(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CTeacherModify();

// 对话框数据
	enum { IDD = IDD_DIALOG14 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	int m_MOD_number;
	CString m_EDIT_name;
	CString m_MOD_sex;
	CString m_MOD_department;
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
};
