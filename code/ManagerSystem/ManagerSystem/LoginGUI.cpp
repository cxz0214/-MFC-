// LoginGUI.cpp : 实现文件
//

#include "stdafx.h"
#include "ManagerSystem.h"
#include "LoginGUI.h"
#include "afxdialogex.h"
#include"MainFrm.h"
#include "ManagerSystemDoc.h"
#include "admin_login.h"

// CLoginGUI 对话框

IMPLEMENT_DYNAMIC(CLoginGUI, CDialogEx)

CLoginGUI::CLoginGUI(CWnd* pParent /*=NULL*/)
	: CDialogEx(CLoginGUI::IDD, pParent)
	, m_uiAdmin(_T(""))
	, m_uiAdminPassword(_T(""))
{

}

CLoginGUI::~CLoginGUI()
{
}

void CLoginGUI::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_change);
	DDX_Text(pDX, IDC_EDIT1, m_uiAdmin);
	DDX_Text(pDX, IDC_EDIT2, m_uiAdminPassword);
}


BEGIN_MESSAGE_MAP(CLoginGUI, CDialogEx)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CLoginGUI::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_BUTTON1, &CLoginGUI::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CLoginGUI::OnBnClickedButton2)
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// CLoginGUI 消息处理程序


BOOL CLoginGUI::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_change.SetCurSel(0);
	m_uiAdmin = TEXT("CXZ");
	m_uiAdminPassword = TEXT("0214");
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}


void CLoginGUI::OnCbnSelchangeCombo1()
{
	// TODO:  在此添加控件通知处理程序代码
	CMainFrame* frame = (CMainFrame*)AfxGetMainWnd();
	CManagerSystemDoc* pDoc = (CManagerSystemDoc*)frame->GetActiveDocument();
	pDoc->login_num = m_change.GetCurSel();
	
}


void CLoginGUI::OnBnClickedButton1()//登录
{
	// TODO:  在此添加控件通知处理程序代码
	//获取框架指针
	CMainFrame * mainfram = (CMainFrame*)AfxGetMainWnd();
	//获取文档类对象指针
	CManagerSystemDoc* pDoc = (CManagerSystemDoc*)mainfram->GetActiveDocument();
	//获取用户数据库记录集指针
	Cadmin_login* pAdminset = pDoc->GetAdminSet();
	Cstudent_login*pStuSet =pDoc->GetStudentSet();
	Cteacher_login*pTeachSet = pDoc->GetTeacherSet();
	if (pAdminset->IsOpen()==FALSE)
	{
		//如果数据库未打开，则打开数据库
		pAdminset->Open();
	}
	if (pStuSet->IsOpen()==FALSE)
	{
		pStuSet->Open();
	}
	if (pTeachSet->IsOpen()==FALSE)
	{
		pTeachSet->Open();
	}

	UpdateData(TRUE);
	if (m_uiAdmin.IsEmpty()||m_uiAdminPassword.IsEmpty())
	{
		AfxMessageBox("用户名或密码不能为空！请重新输入！");
	}
	else
	{
		BOOL state = FALSE;
		int index = m_change.GetCurSel();
		if (index == 0)
		{
			CString sql;
			sql.Format(TEXT("Admin_login='%s' and Admin_password='%s'"), m_uiAdmin, m_uiAdminPassword);
			pAdminset->m_strFilter = sql;
			pAdminset->Requery();
			if (pAdminset->GetRecordCount() == 0)
			{
				AfxMessageBox("用户名或密码错误！");
			}
			else
			{
				AfxMessageBox("登录成功！");
				state = TRUE;
			}

			pAdminset->Close();
		}
		else if (index == 2)
		{
			CString sql;
			sql.Format(TEXT("S_number='%s' and S_password='%s'"), m_uiAdmin, m_uiAdminPassword);
			pStuSet->m_strFilter = sql;
			pStuSet->Requery();
			if (pStuSet->GetRecordCount() == 0)
			{
				AfxMessageBox("用户名或密码错误！");
			}
			else
			{
				AfxMessageBox("登录成功！");
				pDoc->student_user = _ttoi(m_uiAdmin);
				state = TRUE;
			}

			pStuSet->Close();
		}
		else
		{
			CString sql;
			sql.Format(TEXT("T_number='%s' and T_password='%s'"), m_uiAdmin, m_uiAdminPassword);
			pTeachSet->m_strFilter = sql;
			pTeachSet->Requery();
			if (pTeachSet->GetRecordCount() == 0)
			{
				AfxMessageBox("用户名或密码错误！");
			}
			else
			{
				pDoc->teacher_user = _ttoi(m_uiAdmin);
				AfxMessageBox("登录成功！");
				state = TRUE;
			}

			pTeachSet->Close();
		}
		if (state == TRUE)
		{
			OnOK();
		}
	}
}


void CLoginGUI::OnBnClickedButton2()//取消按钮
{
	// TODO:  在此添加控件通知处理程序代码
	OnClose();
}

void CLoginGUI::OnClose()
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	exit(1);
	CDialogEx::OnClose();
}
