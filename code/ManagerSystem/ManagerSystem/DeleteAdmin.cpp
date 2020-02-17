// DeleteAdmin.cpp : 实现文件
//

#include "stdafx.h"
#include "ManagerSystem.h"
#include "DeleteAdmin.h"
#include "afxdialogex.h"
#include "MainFrm.h"
#include "ManagerSystemDoc.h"


// CDeleteAdmin 对话框

IMPLEMENT_DYNAMIC(CDeleteAdmin, CDialogEx)

CDeleteAdmin::CDeleteAdmin(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDeleteAdmin::IDD, pParent)
	, m_re_user(_T(""))
{

}

CDeleteAdmin::~CDeleteAdmin()
{
}

void CDeleteAdmin::DeleteCount(Cadmin_login* set, CString username)
{
	CString sql;
	sql.Format(TEXT("Admin_login='%s'"), username);
	if (set->IsOpen()==FALSE)
	{
		set->Open();
	}

	set->m_strFilter = sql;
	set->Requery();
	set->Delete();
	
}

void CDeleteAdmin::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_re_user);
	DDX_Control(pDX, IDC_LIST1, m_reult_list);
}


BEGIN_MESSAGE_MAP(CDeleteAdmin, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CDeleteAdmin::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &CDeleteAdmin::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CDeleteAdmin::OnBnClickedButton4)
END_MESSAGE_MAP()


// CDeleteAdmin 消息处理程序


void CDeleteAdmin::OnBnClickedButton1()//查询
{
	// TODO:  在此添加控件通知处理程序代码
	m_re_user.Empty();
	m_reult_list.DeleteAllItems();
	CString sql;
	sql.Empty();
	CMainFrame* frame = (CMainFrame*)AfxGetMainWnd();
	CManagerSystemDoc* pDoc = (CManagerSystemDoc*)frame->GetActiveDocument();
	Cadmin_login* pSet=pDoc->GetAdminSet();
	if (pSet->IsOpen()==FALSE)
	{
		pSet->Open();
	}
	UpdateData(TRUE);

	sql.Format(TEXT("Admin_login='%s'"), m_re_user);
	pSet->m_strFilter = sql;
	pSet->Requery();
	if (pSet->GetRecordCount()==0)
	{
		AfxMessageBox("用户不存在");
	}
	else
	{
		m_reult_list.InsertItem(0, (CString)pSet->m_Admin_login);
		m_reult_list.SetItemText(0, 1, (CString)pSet->m_Admin_password);
	}
	
}


BOOL CDeleteAdmin::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_reult_list.SetExtendedStyle(m_reult_list.GetExtendedStyle()
		| LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
	int weigth = 162;
	m_reult_list.InsertColumn(0, "用户名",LVCFMT_CENTER,weigth);
	m_reult_list.InsertColumn(1, "密码", LVCFMT_CENTER, weigth);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}


void CDeleteAdmin::OnBnClickedButton3()       //删除账号
{
	// TODO:  在此添加控件通知处理程序代码
	CMainFrame* frame = (CMainFrame*)AfxGetMainWnd();
	CManagerSystemDoc* pDoc = (CManagerSystemDoc*)frame->GetActiveDocument();
	Cadmin_login* pSet = pDoc->GetAdminSet();
	UpdateData(TRUE);
	CString str=m_reult_list.GetItemText(0,0);
	if (AfxMessageBox(TEXT("确认删除：\n用户名：") + str +
		TEXT("\n密码：") + m_reult_list.GetItemText(0, 1),
		MB_YESNO) == IDYES)
	{
		DeleteCount(pSet, m_re_user);
		AfxMessageBox("删除成功！");
		m_reult_list.SetItemText(0, 0, "");
		m_reult_list.SetItemText(0, 1, "");
	}
}


void CDeleteAdmin::OnBnClickedButton4()         //取消按钮
{
	// TODO:  在此添加控件通知处理程序代码
	OnCancel();
}
