
// ManagerSystem.h : ManagerSystem Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CManagerSystemApp:
// �йش����ʵ�֣������ ManagerSystem.cpp
//

class CManagerSystemApp : public CWinApp
{
public:
	CManagerSystemApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CManagerSystemApp theApp;
