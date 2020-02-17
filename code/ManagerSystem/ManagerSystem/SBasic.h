#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// CSBasic 对话框

class CSBasic : public CDialogEx
{
	DECLARE_DYNAMIC(CSBasic)

public:
	CSBasic(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSBasic();

// 对话框数据
	enum { IDD = IDD_DIALOG8 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CListCtrl m_SBGUI_list;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	CComboBox m_combox;
	afx_msg void OnCbnSelchangeCombo1();
	CString m_sname;
	int m_snumber;
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton17();
	afx_msg void OnBnClickedButton8();
};
