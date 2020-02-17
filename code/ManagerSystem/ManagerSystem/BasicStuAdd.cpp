// BasicStuAdd.cpp : 实现文件
//

#include "stdafx.h"
#include "ManagerSystem.h"
#include "BasicStuAdd.h"
#include "afxdialogex.h"
#include "MainFrm.h"
#include "BasicStuAdd.h"
#include "sbasicinformation.h"
#include "ManagerSystemDoc.h"
#include "StudentBasic.h"
// CBasicStuAdd 对话框

IMPLEMENT_DYNAMIC(CBasicStuAdd, CDialogEx)

CBasicStuAdd::CBasicStuAdd(CWnd* pParent /*=NULL*/)
	: CDialogEx(CBasicStuAdd::IDD, pParent)
	, m_uisnumber(0)
	, m_uisname(_T(""))
	, m_uissex(_T(""))
	, m_uination(_T(""))
	, m_uisID(_T(""))
	, m_uiplot(_T(""))
	, m_uiplace(_T(""))
	, m_bir_year(0)
	, m_birth_month(0)
	, m_birth_day(0)
	, m_enter_year(0)
	, m_enter_month(0)
	, m_enter_day(0)
{
}

CBasicStuAdd::~CBasicStuAdd()
{
}

void CBasicStuAdd::AddStudentBasic()
{
	CMainFrame* frame = (CMainFrame*)AfxGetMainWnd();
	CManagerSystemDoc* pDoc = (CManagerSystemDoc*)frame->GetActiveDocument();
	Csbasicinformation* pSet = (Csbasicinformation*)pDoc->GetStudentBasic();
	CStudentBasic stu;
	stu.SetBasicSet(pSet);
	CTime birthday(m_bir_year, m_birth_month, m_birth_day,0,0,0);
	CTime enterTime(m_enter_year, m_enter_month, m_enter_day,0,0,0);
	stu.SetStudentBasic(m_uisnumber, m_uisname, m_uissex, birthday, m_uination, m_uisID, m_uiplot, enterTime, m_uiplace);
	stu.AddStudentBasic();
}

void CBasicStuAdd::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_uisnumber);
	DDX_Text(pDX, IDC_EDIT3, m_uisname);
	DDX_Text(pDX, IDC_EDIT4, m_uissex);
	DDX_Text(pDX, IDC_EDIT6, m_uination);
	DDX_Text(pDX, IDC_EDIT7, m_uisID);
	DDX_Text(pDX, IDC_EDIT8, m_uiplot);
	DDX_Text(pDX, IDC_EDIT9, m_uiplace);
	DDX_Text(pDX, IDC_EDIT5, m_bir_year);
	DDX_Text(pDX, IDC_EDIT10, m_birth_month);
	DDX_Text(pDX, IDC_EDIT11, m_birth_day);
	DDX_Text(pDX, IDC_EDIT12, m_enter_year);
	DDX_Text(pDX, IDC_EDIT13, m_enter_month);
	DDX_Text(pDX, IDC_EDIT14, m_enter_day);
}


BEGIN_MESSAGE_MAP(CBasicStuAdd, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON12, &CBasicStuAdd::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON2, &CBasicStuAdd::OnBnClickedButton2)
END_MESSAGE_MAP()


// CBasicStuAdd 消息处理程序


void CBasicStuAdd::OnBnClickedButton12()
{
	// TODO:  在此添加控件通知处理程序代码

	UpdateData(TRUE);

	AddStudentBasic();
	AfxMessageBox("添加成功！");
	OnOK();
}


void CBasicStuAdd::OnBnClickedButton2()
{
	// TODO:  在此添加控件通知处理程序代码
	OnCancel();
}
