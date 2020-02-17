// AddAdmin.cpp : 实现文件
//

#include "stdafx.h"
#include "ManagerSystem.h"
#include "AddAdmin.h"
#include "afxdialogex.h"
#include "MainFrm.h"
#include "ManagerSystemDoc.h"
#include "Admin.h"

// AddAdmin 对话框

IMPLEMENT_DYNAMIC(AddAdmin, CDialogEx)

AddAdmin::AddAdmin(CWnd* pParent /*=NULL*/)
	: CDialogEx(AddAdmin::IDD, pParent)
	, m_ui_admin_user(_T(""))
	, m_ui_password(_T(""))
{

}

AddAdmin::~AddAdmin()
{
}

void AddAdmin::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_ui_admin_user);
	DDX_Text(pDX, IDC_EDIT2, m_ui_password);
}


BEGIN_MESSAGE_MAP(AddAdmin, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &AddAdmin::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &AddAdmin::OnBnClickedButton2)
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// AddAdmin 消息处理程序


void AddAdmin::OnBnClickedButton1()              //添加账号
{
	// TODO:  在此添加控件通知处理程序代码
	CMainFrame* mainfram = (CMainFrame*)AfxGetMainWnd();
	CManagerSystemDoc* pDoc = (CManagerSystemDoc*)mainfram->GetActiveDocument();
	Cadmin_login* pSet=pDoc->GetAdminSet();
	CAdmin admin;
	admin.SetAdminSet(pSet);
	UpdateData(TRUE);
	int result=admin.AddCount(m_ui_admin_user, m_ui_password);
	if (result==0)
	{
		AfxMessageBox("添加成功！");
	}
	OnOK();
}


void AddAdmin::OnBnClickedButton2()
{
	// TODO:  在此添加控件通知处理程序代码
	//去掉按钮
	OnCancel();
}


void AddAdmin::OnClose()
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值

	CDialogEx::OnClose();
}
