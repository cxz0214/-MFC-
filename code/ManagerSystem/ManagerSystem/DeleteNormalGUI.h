#pragma once
#include "afxcmn.h"


// CDeleteNormalGUI 对话框

class CDeleteNormalGUI : public CDialogEx
{
	DECLARE_DYNAMIC(CDeleteNormalGUI)

public:
	CDeleteNormalGUI(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDeleteNormalGUI();
	void ReQueryGUI(int type);          //普通用户查询
	void DeleteNormal(int type);        //普通用户删除

// 对话框数据
	enum { IDD = IDD_DIALOG5 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	int m_username;
	CListCtrl m_listctrl;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
};
