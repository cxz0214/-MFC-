
// ManagerSystemView.h : CManagerSystemView ��Ľӿ�
//

#pragma once

#include "resource.h"
#include "afxwin.h"


class CManagerSystemView : public CFormView
{
protected: // �������л�����
	CManagerSystemView();
	DECLARE_DYNCREATE(CManagerSystemView)

public:
	enum{ IDD = IDD_MANAGERSYSTEM_FORM };

// ����
public:
	CManagerSystemDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~CManagerSystemView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
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

#ifndef _DEBUG  // ManagerSystemView.cpp �еĵ��԰汾
inline CManagerSystemDoc* CManagerSystemView::GetDocument() const
   { return reinterpret_cast<CManagerSystemDoc*>(m_pDocument); }
#endif

