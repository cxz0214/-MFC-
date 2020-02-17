// AddNormalUser.cpp : 实现文件
//

#include "stdafx.h"
#include "ManagerSystem.h"
#include "AddNormalUser.h"
#include "afxdialogex.h"
#include "MainFrm.h"
#include "ManagerSystemDoc.h"
#include "NormalUser.h"
#include "ManagerSystemView.h"


// CAddNormalUser 对话框

IMPLEMENT_DYNAMIC(CAddNormalUser, CDialogEx)

CAddNormalUser::CAddNormalUser(CWnd* pParent /*=NULL*/)
	: CDialogEx(CAddNormalUser::IDD, pParent)
	, m_normal_user(0)
	, m_normal_password(_T(""))
{

}

CAddNormalUser::~CAddNormalUser()
{
}

void CAddNormalUser::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_normal_user);
	DDX_Text(pDX, IDC_EDIT2, m_normal_password);
}


BEGIN_MESSAGE_MAP(CAddNormalUser, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CAddNormalUser::OnBnClickedButton1)
END_MESSAGE_MAP()


// CAddNormalUser 消息处理程序


void CAddNormalUser::OnBnClickedButton1()   //添加
{
	// TODO:  在此添加控件通知处理程序代码
	CMainFrame* frame = (CMainFrame*)AfxGetMainWnd();
	CManagerSystemDoc* pDoc = (CManagerSystemDoc*)frame->GetActiveDocument();
	CManagerSystemView* pView = (CManagerSystemView*)frame->GetActiveView();
	Cstudent_login* pStuset=pDoc->GetStudentSet();
	Cteacher_login* pTeachset = pDoc->GetTeacherSet();
	UpdateData(TRUE);
	CNormalUser normaluser;
	normaluser.SetUserObj(m_normal_user, m_normal_password);
	int index = pView->m_MainFormChange.GetCurSel();
	if (index==1)
	{
		normaluser.AddNormalUser(pTeachset);
		AfxMessageBox("添加成功！");
	}
	if (index==2)
	{
		normaluser.AddNormalUser(pStuset);
		AfxMessageBox("添加成功！");
	}
	

}
