#pragma once
#include "afxcmn.h"


// CStudentStudy �Ի���

class CStudentStudy : public CDialogEx
{
	DECLARE_DYNAMIC(CStudentStudy)

public:
	CStudentStudy(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CStudentStudy();

// �Ի�������
	enum { IDD = IDD_DIALOG10 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_studyGUI;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnNMClickList2(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
};
