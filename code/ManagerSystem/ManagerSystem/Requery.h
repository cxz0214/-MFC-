#pragma once
#include "afxcmn.h"


// CRequery �Ի���

class CRequery : public CDialogEx
{
	DECLARE_DYNAMIC(CRequery)

public:
	CRequery(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CRequery();

// �Ի�������
	enum { IDD = IDD_DIALOG7 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_re_list;
	virtual BOOL OnInitDialog();
};
