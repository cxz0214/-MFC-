#pragma once
#include "atltime.h"


// CBasicStuAdd 对话框

class CBasicStuAdd : public CDialogEx
{
	DECLARE_DYNAMIC(CBasicStuAdd)

public:
	CBasicStuAdd(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CBasicStuAdd();
	void AddStudentBasic();
// 对话框数据
	enum { IDD = IDD_DIALOG6 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int m_uisnumber;
	CString m_uisname;
	CString m_uissex;
//	CString m_uibirthday;
	CString m_uination;
	CString m_uisID;
	CString m_uiplot;
	CString m_uiplace;
//	CString m_uientertime;
	afx_msg void OnBnClickedButton12();
	int m_bir_year;
	int m_birth_month;
	int m_birth_day;
	int m_enter_year;
	int m_enter_month;
	int m_enter_day;
	afx_msg void OnBnClickedButton2();
};
