// EidtStudent.cpp : 实现文件
//

#include "stdafx.h"
#include "ManagerSystem.h"
#include "EidtStudent.h"
#include "afxdialogex.h"
#include "MainFrm.h"
#include "ManagerSystemDoc.h"
#include "SBasic.h"
#include "sbasicinformation.h"
#include <afxdb.h>
// CEidtStudent 对话框

IMPLEMENT_DYNAMIC(CEidtStudent, CDialogEx)

CEidtStudent::CEidtStudent(CWnd* pParent /*=NULL*/)
	: CDialogEx(CEidtStudent::IDD, pParent)
	, m_eidt_number(0)
	, m_edit_name(_T(""))
	, m_edit_sex(_T(""))
	, m_year(0)
	, m_month(0)
	, m_day(0)
	, m_nation(_T(""))
	, m_id(_T(""))
	, m_plot(_T(""))
	, m_place(_T(""))
	, m_enter_year(0)
	, m_enter_month(0)
	, m_enter_day(0)
{

}

CEidtStudent::~CEidtStudent()
{
}

void CEidtStudent::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_eidt_number);
	DDX_Text(pDX, IDC_EDIT3, m_edit_name);
	DDX_Text(pDX, IDC_EDIT4, m_edit_sex);
	DDX_Text(pDX, IDC_EDIT5, m_year);
	DDX_Text(pDX, IDC_EDIT10, m_month);
	DDX_Text(pDX, IDC_EDIT11, m_day);
	DDX_Text(pDX, IDC_EDIT6, m_nation);
	DDX_Text(pDX, IDC_EDIT7, m_id);
	DDX_Text(pDX, IDC_EDIT8, m_plot);
	DDX_Text(pDX, IDC_EDIT9, m_place);
	DDX_Text(pDX, IDC_EDIT12, m_enter_year);
	DDX_Text(pDX, IDC_EDIT13, m_enter_month);
	DDX_Text(pDX, IDC_EDIT14, m_enter_day);
}


BEGIN_MESSAGE_MAP(CEidtStudent, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON12, &CEidtStudent::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON2, &CEidtStudent::OnBnClickedButton2)
END_MESSAGE_MAP()


// CEidtStudent 消息处理程序


void CEidtStudent::OnBnClickedButton12()       //确认修改
{
	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CMainFrame*frame = (CMainFrame*)AfxGetMainWnd();
	CManagerSystemDoc* pDoc = (CManagerSystemDoc*)frame->GetActiveDocument();
	CDatabase db;
	Csbasicinformation pSet(&db);
	if (pSet.IsOpen() == FALSE)
	{
		pSet.Open();
	}
	if (AfxMessageBox(TEXT("确认修改?"),MB_YESNO) == IDYES)
	{
		CString sql;
		CTime time1(m_year, m_month, m_day, 0, 0, 0);
		CTime time2(m_enter_year, m_enter_month, m_enter_day, 0, 0, 0);
		CString str1=time1.Format(TEXT("%Y-%m-%d"));
		CString str2 = time2.Format(TEXT("%Y-%m-%d"));
		sql.Format(TEXT("update sbasicinformation set S_number='%d',S_name='%s',S_sex='%s',S_birthday='%s',S_nation='%s',S_idnumber='%s',S_polst='%s',S_entertime='%s',S_origin='%s' where S_number='%d'"), 
			m_eidt_number,m_edit_name,m_edit_sex,str1,m_nation,m_id,m_plot,str2,m_place,pDoc->number_s);
		db.ExecuteSQL(sql);
		pSet.Close();
		AfxMessageBox("修改成功！");
		OnOK();
	}
	


}


BOOL CEidtStudent::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	CMainFrame*frame = (CMainFrame*)AfxGetMainWnd();
	CManagerSystemDoc* pDoc = (CManagerSystemDoc*)frame->GetActiveDocument();
	
	m_eidt_number = pDoc->number_s;
	m_edit_name = pDoc->name_s;
	m_edit_sex = pDoc->sex_s;
	m_year = pDoc->bir_year_s;
	m_month = pDoc->bir_month_s;
	m_day = pDoc->bir_day_s;
	m_plot = pDoc->plostic_s;
	m_id = pDoc->ID_s;
	m_nation = pDoc->nation_s;
	m_enter_year = pDoc->enter_year_s;
	m_enter_month = pDoc->enter_month_s;
	m_enter_day = pDoc->enter_day_s;
	m_place = pDoc->place_s;
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}


void CEidtStudent::OnBnClickedButton2()
{
	// TODO:  在此添加控件通知处理程序代码
	OnCancel();
}
