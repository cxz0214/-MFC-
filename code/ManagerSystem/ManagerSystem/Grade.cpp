// Grade.cpp : 实现文件
//

#include "stdafx.h"
#include "ManagerSystem.h"
#include "Grade.h"
#include "afxdialogex.h"
#include "MainFrm.h"
#include "ManagerSystemDoc.h"
#include "coursetable.h"
#include "s_classinfo.h"
#include "sscholasticin.h"
#include "sbasicinformation.h"
#include "TeacherManagerClass.h"

// CGrade 对话框

IMPLEMENT_DYNAMIC(CGrade, CDialogEx)

CGrade::CGrade(CWnd* pParent /*=NULL*/)
	: CDialogEx(CGrade::IDD, pParent)
	, m_number(0)
	, m_name(_T(""))
	, m_department(_T(""))
	, m_classname(_T(""))
	, m_grade(0)
{

}

CGrade::~CGrade()
{
}

void CGrade::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_number);
	DDX_Text(pDX, IDC_EDIT18, m_name);
	DDX_Text(pDX, IDC_EDIT20, m_department);
	DDX_Text(pDX, IDC_EDIT21, m_classname);
	DDX_Text(pDX, IDC_EDIT22, m_grade);
}


BEGIN_MESSAGE_MAP(CGrade, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CGrade::OnBnClickedButton1)
END_MESSAGE_MAP()


// CGrade 消息处理程序


BOOL CGrade::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	CMainFrame* frame = (CMainFrame*)AfxGetMainWnd();
	CManagerSystemDoc* pDoc = (CManagerSystemDoc*)frame->GetActiveDocument();
	Ccoursetable* pSet = (Ccoursetable*)pDoc->GetCourseSet();
	Cs_classinfo* pset = (Cs_classinfo*)pDoc->getClassChangedSet();
	Csscholasticin*Stu = (Csscholasticin*)pDoc->GetSscholSet();
	Csbasicinformation* stu = (Csbasicinformation*)pDoc->GetStudentBasic();
	m_number = pDoc->D_Snumber;
	m_name = pDoc->D_name;
	m_department = pDoc->D_Sdepartment;
	m_classname = pDoc->D_Sclass;
	m_grade = pDoc->D_Sgrade;
	GetDlgItem(IDC_EDIT1)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT18)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT20)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT21)->EnableWindow(FALSE);
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}


void CGrade::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码
	//////////////////////////////////////////////////////////////////////////
	//确认录入
	CMainFrame* frame = (CMainFrame*)AfxGetMainWnd();
	CManagerSystemDoc* pDoc = (CManagerSystemDoc*)frame->GetActiveDocument();
	Ccoursetable* pSet = (Ccoursetable*)pDoc->GetCourseSet();
	CDatabase db;
	Cs_classinfo pset(&db);
	Csscholasticin*Stu = (Csscholasticin*)pDoc->GetSscholSet();
	Csbasicinformation* stu = (Csbasicinformation*)pDoc->GetStudentBasic();
	CListCtrl* pListCtrl = (CListCtrl*)GetDlgItem(IDC_LIST2);
	if (pSet->IsOpen()==FALSE)
	{
		pSet->Open();
	}
	if (pset.IsOpen()==FALSE)
	{
		pset.Open();
	}
	if (Stu->IsOpen()==FALSE)
	{
		Stu->Open();
	}
	if (stu->IsOpen()==FALSE)
	{
		stu->Open();
	}
	UpdateData(TRUE);
	CString sql;
	sql.Format(TEXT("Class_name='%s'"), m_classname);
	pSet->m_strFilter = sql;
	pSet->Requery();
	sql.Format(TEXT("Class_number='%d' and T_number='%d' and S_number='%d'"), pSet->m_Class_number, pDoc->teacher_user, m_number);
	pset.m_strFilter = sql;
	pset.Requery();
	pset.Edit();
	pset.m_S_grade = m_grade;
	sql.Format(TEXT("call calculategpa('%d')"), m_number);
	pset.Update();
	db.ExecuteSQL(sql);
	AfxMessageBox("录入成功");
	pSet->m_strFilter = "";
	pset.m_strFilter = "";
	pSet->Requery();
	pset.Requery();
	pSet->Close();
	pset.Close();
	updatelist();
	OnOK();

}

void CGrade::updatelist()
{
	CMainFrame* frame = (CMainFrame*)AfxGetMainWnd();
	CManagerSystemDoc* pDoc = (CManagerSystemDoc*)frame->GetActiveDocument();
	Ccoursetable* pSet = (Ccoursetable*)pDoc->GetCourseSet();
	Cs_classinfo* pset = (Cs_classinfo*)pDoc->getClassChangedSet();
	Csscholasticin* Stu = (Csscholasticin*)pDoc->GetSscholSet();
	Csbasicinformation* stu = (Csbasicinformation*)pDoc->GetStudentBasic();
	CListCtrl* pListCtrl = pDoc->plistCtrl;
	int m = pDoc->comboxint;
	CString str=pDoc->comboxstr;
	if (pSet->IsOpen() == FALSE)
	{
		pSet->Open();
	}
	if (Stu->IsOpen() == FALSE)
	{
		Stu->Open();
	}
	if (stu->IsOpen() == FALSE)
	{
		stu->Open();
	}
	if (pset->IsOpen() == FALSE)
	{
		pset->Open();
	}
	CString sql;
	sql.Format(TEXT("T_number='%d' and Class_name='%s'"), pDoc->teacher_user, str);
	pSet->m_strFilter = sql;
	pSet->Requery();
	CString sqls;
	sqls.Format(TEXT("Class_number='%d'and T_number='%d'"), pSet->m_Class_number, pDoc->teacher_user);
	pset->m_strFilter = sqls;
	pset->Requery();
	pListCtrl->DeleteAllItems();
	int i = 0;
	while (pset->IsEOF() == FALSE)
	{
		CString sql3;
		sql3.Format(TEXT("S_number='%d'"), pset->m_S_number);
		Stu->m_strFilter = sql3;
		stu->m_strFilter = sql3;
		Stu->Requery();
		stu->Requery();
		CString strm;
		strm.Format(TEXT("%d"), pset->m_S_number);
		pListCtrl->InsertItem(i, strm);
		pListCtrl->SetItemText(i, 1, (CString)stu->m_S_name);
		strm.Format(TEXT("%d"), Stu->m_S_class);
		pListCtrl->SetItemText(i, 2, strm);
		pListCtrl->SetItemText(i, 3, (CString)Stu->m_S_department);
		str.Format(TEXT("%d"), pset->m_S_grade);
		pListCtrl->SetItemText(i, 4, str);
		sql3.Empty();
		Stu->m_strFilter = sql3;
		stu->m_strFilter = sql3;
		Stu->Requery();
		stu->Requery();
		pset->MoveNext();
		i++;
	}
	pSet->m_strFilter = "";
	pset->m_strFilter = "";
	Stu->m_strFilter = "";
	stu->m_strFilter = "";
	pSet->Requery();
	pset->Requery();
	Stu->Requery();
	stu->Requery();
	pSet->Close();
	pset->Close();
	Stu->Close();
	stu->Close();

}
