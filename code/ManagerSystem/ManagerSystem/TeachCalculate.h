#pragma once


// CTeachCalculate �Ի���

class CTeachCalculate : public CDialogEx
{
	DECLARE_DYNAMIC(CTeachCalculate)

public:
	CTeachCalculate(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CTeachCalculate();

// �Ի�������
	enum { IDD = IDD_DIALOG19 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
};
