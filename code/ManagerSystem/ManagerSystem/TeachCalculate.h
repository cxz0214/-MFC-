#pragma once


// CTeachCalculate 对话框

class CTeachCalculate : public CDialogEx
{
	DECLARE_DYNAMIC(CTeachCalculate)

public:
	CTeachCalculate(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CTeachCalculate();

// 对话框数据
	enum { IDD = IDD_DIALOG19 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
};
