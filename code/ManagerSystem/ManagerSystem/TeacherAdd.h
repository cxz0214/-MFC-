#pragma once
#include "afxcmn.h"


// CTeacherAdd �Ի���

class CTeacherAdd : public CDialogEx
{
	DECLARE_DYNAMIC(CTeacherAdd)

public:
	CTeacherAdd(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CTeacherAdd();

// �Ի�������
	enum { IDD = IDD_DIALOG12 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_GUITeacher;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
};
