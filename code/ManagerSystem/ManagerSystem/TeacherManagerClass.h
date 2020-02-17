#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// CTeacherManagerClass 对话框

class CTeacherManagerClass : public CDialogEx
{
	DECLARE_DYNAMIC(CTeacherManagerClass)

public:
	CTeacherManagerClass(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CTeacherManagerClass();

// 对话框数据
	enum { IDD = IDD_DIALOG16 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_list;
	virtual BOOL OnInitDialog();
	CListCtrl m_list_2;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnNMClickList4(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	CComboBox m_comboBox;
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnNMClickList2(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();

};
