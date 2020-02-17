
// ManagerSystemView.h : CManagerSystemView 类的接口
//

#pragma once

#include "resource.h"
#include "afxwin.h"


class CManagerSystemView : public CFormView
{
protected: // 仅从序列化创建
	CManagerSystemView();
	DECLARE_DYNCREATE(CManagerSystemView)

public:
	enum{ IDD = IDD_MANAGERSYSTEM_FORM };

// 特性
public:
	CManagerSystemDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~CManagerSystemView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_MainFormChange;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton23();
	afx_msg void OnBnClickedButton25();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton30();
};

#ifndef _DEBUG  // ManagerSystemView.cpp 中的调试版本
inline CManagerSystemDoc* CManagerSystemView::GetDocument() const
   { return reinterpret_cast<CManagerSystemDoc*>(m_pDocument); }
#endif

