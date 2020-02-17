// TeacherModify.cpp : 实现文件
//

#include "stdafx.h"
#include "ManagerSystem.h"
#include "TeacherModify.h"
#include "afxdialogex.h"
#include "MainFrm.h"
#include "ManagerSystemDoc.h"


// CTeacherModify 对话框

IMPLEMENT_DYNAMIC(CTeacherModify, CDialogEx)

CTeacherModify::CTeacherModify(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTeacherModify::IDD, pParent)
	, m_MOD_number(0)
	, m_EDIT_name(_T(""))
	, m_MOD_sex(_T(""))
	, m_MOD_department(_T(""))
{

}

CTeacherModify::~CTeacherModify()
{
}

void CTeacherModify::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_MOD_number);
	DDX_Text(pDX, IDC_EDIT2, m_EDIT_name);
	DDX_Text(pDX, IDC_EDIT15, m_MOD_sex);
	DDX_Text(pDX, IDC_EDIT16, m_MOD_department);
}


BEGIN_MESSAGE_MAP(CTeacherModify, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON3, &CTeacherModify::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CTeacherModify::OnBnClickedButton4)
END_MESSAGE_MAP()


// CTeacherModify 消息处理程序


BOOL CTeacherModify::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	CMainFrame* frame = (CMainFrame*)AfxGetMainWnd();
	CManagerSystemDoc* pDoc = (CManagerSystemDoc*)frame->GetActiveDocument();
	m_MOD_number = pDoc->T_number;
	m_EDIT_name = pDoc->T_name;
	m_MOD_sex = pDoc->T_sex;
	m_MOD_department = pDoc->T_department;
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}


void CTeacherModify::OnBnClickedButton3()
{
	// TODO:  在此添加控件通知处理程序代码
	CMainFrame* frame = (CMainFrame*)AfxGetMainWnd();
	CManagerSystemDoc* pDoc = (CManagerSystemDoc*)frame->GetActiveDocument();
	Cteacherinfo* pSet = (Cteacherinfo*)pDoc->GetTeacherInforSet();
	UpdateData(TRUE);
	if (pSet->IsOpen()==FALSE)
	{
		pSet->Open();
	}
	CString sql;
	sql.Format(TEXT("T_number='%d'"), pDoc->T_number);
	pSet->m_strFilter = sql;
	pSet->Edit();
	pSet->m_T_number = m_MOD_number;
	pSet->m_T_name = m_EDIT_name;
	pSet->m_T_sex = m_MOD_sex;
	pSet->m_Department = m_MOD_department;
	pSet->Update();
	sql.Empty();
	pSet->m_strFilter = sql;
	pSet->Close();
	AfxMessageBox("修改成功！");
	OnOK();

}


void CTeacherModify::OnBnClickedButton4()
{
	// TODO:  在此添加控件通知处理程序代码
	OnCancel();
}
