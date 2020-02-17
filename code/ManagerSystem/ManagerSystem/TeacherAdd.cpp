// TeacherAdd.cpp : 实现文件
//

#include "stdafx.h"
#include "ManagerSystem.h"
#include "TeacherAdd.h"
#include "afxdialogex.h"
#include "TeacherADDGUI.h"
#include "MainFrm.h"
#include "ManagerSystemDoc.h"
#include"teacherinfo.h"
#include "TeacherModify.h"
// CTeacherAdd 对话框

IMPLEMENT_DYNAMIC(CTeacherAdd, CDialogEx)

CTeacherAdd::CTeacherAdd(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTeacherAdd::IDD, pParent)
{

}

CTeacherAdd::~CTeacherAdd()
{
}

void CTeacherAdd::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_GUITeacher);
}


BEGIN_MESSAGE_MAP(CTeacherAdd, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CTeacherAdd::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON5, &CTeacherAdd::OnBnClickedButton5)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, &CTeacherAdd::OnNMClickList1)
	ON_BN_CLICKED(IDC_BUTTON6, &CTeacherAdd::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CTeacherAdd::OnBnClickedButton7)
END_MESSAGE_MAP()


// CTeacherAdd 消息处理程序


BOOL CTeacherAdd::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	CMainFrame*frame = (CMainFrame*)AfxGetMainWnd();
	CManagerSystemDoc* pDoc = (CManagerSystemDoc*)frame->GetActiveDocument();
	Cteacherinfo * pSet = (Cteacherinfo*)pDoc->GetTeacherInforSet();
	CString head[] = { TEXT("教职工号"), TEXT("姓名"), TEXT("性别"), TEXT("所属院系") };
	m_GUITeacher.SetExtendedStyle(m_GUITeacher.GetExtendedStyle()
		| LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
	m_GUITeacher.InsertColumn(0, head[0], LVCFMT_CENTER, 150);
	m_GUITeacher.InsertColumn(1, head[1], LVCFMT_CENTER, 150);
	m_GUITeacher.InsertColumn(2, head[2], LVCFMT_CENTER, 150);
	m_GUITeacher.InsertColumn(3, head[3], LVCFMT_CENTER, 200);


	if (pSet->IsOpen() == FALSE)
	{
		pSet->Open();
	}
	pSet->Requery();
	for (int i = 0; i < pSet->GetRecordCount(); i++)
	{
		CString str;
		str.Format(TEXT("%d"), pSet->m_T_number);
		int j = 1;
		m_GUITeacher.InsertItem(i, str);
		m_GUITeacher.SetItemText(i, j++, (CString)pSet->m_T_name);
		m_GUITeacher.SetItemText(i, j++, (CString)pSet->m_T_sex);
		m_GUITeacher.SetItemText(i, j++, (CString)pSet->m_Department);
		pSet->MoveNext();
	}
	pSet->Close();
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}


void CTeacherAdd::OnBnClickedButton1()    //信息添加
{
	// TODO:  在此添加控件通知处理程序代码
	CTeacherADDGUI Dlg;
	Dlg.DoModal();

}


void CTeacherAdd::OnBnClickedButton5()       //教师信息修改
{
	// TODO:  在此添加控件通知处理程序代码
	CMainFrame*frame = (CMainFrame*)AfxGetMainWnd();
	CManagerSystemDoc* pDoc = (CManagerSystemDoc*)frame->GetActiveDocument();
	CListCtrl* pListCtrl = (CListCtrl*)GetDlgItem(IDC_LIST1);
	int i = pDoc->teacher_num;
	if (i<0)
	{
		AfxMessageBox("未选择任何信息，请选择后重新输入！");
	}
	else
	{
		CString str;
		str = pListCtrl->GetItemText(i, 0);
		pDoc->T_number = _ttoi(str);
		str = pListCtrl->GetItemText(i, 1);
		pDoc->T_name = str;
		str = pListCtrl->GetItemText(i, 2);
		pDoc->T_sex = str;
		str = pListCtrl->GetItemText(i, 3);
		pDoc->T_department = str;
		CTeacherModify Dlg;
		Dlg.DoModal();
	}
	
}


void CTeacherAdd::OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO:  在此添加控件通知处理程序代码
	NM_LISTVIEW* plist = (NM_LISTVIEW*)pNMHDR;
	CMainFrame*frame = (CMainFrame*)AfxGetMainWnd();
	CManagerSystemDoc* pDoc = (CManagerSystemDoc*)frame->GetActiveDocument();
	pDoc->teacher_num= plist->iItem;
	*pResult = 0;
}


void CTeacherAdd::OnBnClickedButton6()
{
	// TODO:  在此添加控件通知处理程序代码
	CMainFrame* frame = (CMainFrame*)AfxGetMainWnd();
	CManagerSystemDoc* pDoc = (CManagerSystemDoc*)frame->GetActiveDocument();
	Cteacherinfo* pSet = (Cteacherinfo*)pDoc->GetTeacherInforSet();
	CListCtrl* pListCtrl = (CListCtrl*)GetDlgItem(IDC_LIST1);
	UpdateData(TRUE);
	if (pSet->IsOpen() == FALSE)
	{
		pSet->Open();
	}
	CString sql;
	sql.Format(TEXT("T_number='%d'"), pDoc->T_number);
	pSet->m_strFilter = sql;
	CString str;
	str.Format(TEXT("%d"), _ttoi(pListCtrl->GetItemText(1,0)));
	if (AfxMessageBox(TEXT("\n教职工号: ") + str + TEXT("\n教师姓名: ") + pListCtrl->GetItemText(1, 1) + TEXT("\n性别: ") + pListCtrl->GetItemText(1, 2) +
		TEXT("\n所属院系：") + pListCtrl->GetItemText(1, 3), MB_YESNO) == IDYES)
	{
		pSet->Delete();
		sql.Empty();
		pSet->m_strFilter = sql;
		pSet->Close();
		AfxMessageBox("删除成功！");
		OnOK();
	}
	else
		OnCancel();

}


void CTeacherAdd::OnBnClickedButton7()
{
	// TODO:  在此添加控件通知处理程序代码
	OnOK();
}
