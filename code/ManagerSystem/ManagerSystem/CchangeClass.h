#pragma once
#include "afxcmn.h"


// CchangeClass 对话框

class CchangeClass : public CDialogEx
{
	DECLARE_DYNAMIC(CchangeClass)

public:
	CchangeClass(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CchangeClass();

// 对话框数据
	enum { IDD = IDD_DIALOG15 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_waitchange;
	CListCtrl m_changed;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnNMClickList3(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButton6();
};
