#pragma once
#include "afxcmn.h"


// CDeleteNormalGUI �Ի���

class CDeleteNormalGUI : public CDialogEx
{
	DECLARE_DYNAMIC(CDeleteNormalGUI)

public:
	CDeleteNormalGUI(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDeleteNormalGUI();
	void ReQueryGUI(int type);          //��ͨ�û���ѯ
	void DeleteNormal(int type);        //��ͨ�û�ɾ��

// �Ի�������
	enum { IDD = IDD_DIALOG5 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	int m_username;
	CListCtrl m_listctrl;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
};
