#pragma once
#include "afxcmn.h"


// CRequery 对话框

class CRequery : public CDialogEx
{
	DECLARE_DYNAMIC(CRequery)

public:
	CRequery(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CRequery();

// 对话框数据
	enum { IDD = IDD_DIALOG7 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_re_list;
	virtual BOOL OnInitDialog();
};
