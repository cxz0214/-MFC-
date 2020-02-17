// TeacherManagerClass.cpp : 实现文件
//

#include "stdafx.h"
#include "ManagerSystem.h"
#include "TeacherManagerClass.h"
#include "afxdialogex.h"
#include "CclassAdd.h"
#include "MainFrm.h"
#include "ManagerSystemDoc.h"
#include "coursetable.h"
#include "s_classinfo.h"
#include "sscholasticin.h"
#include "sbasicinformation.h"
#include "Grade.h"
#include "TeachCalculate.h"
// CTeacherManagerClass 对话框

IMPLEMENT_DYNAMIC(CTeacherManagerClass, CDialogEx)

CTeacherManagerClass::CTeacherManagerClass(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTeacherManagerClass::IDD, pParent)
{

}

CTeacherManagerClass::~CTeacherManagerClass()
{
}

void CTeacherManagerClass::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST2, m_list);
	DDX_Control(pDX, IDC_LIST4, m_list_2);
	DDX_Control(pDX, IDC_COMBO1, m_comboBox);
}


BEGIN_MESSAGE_MAP(CTeacherManagerClass, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CTeacherManagerClass::OnBnClickedButton1)
	ON_NOTIFY(NM_CLICK, IDC_LIST4, &CTeacherManagerClass::OnNMClickList4)
	ON_BN_CLICKED(IDC_BUTTON2, &CTeacherManagerClass::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CTeacherManagerClass::OnBnClickedButton3)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CTeacherManagerClass::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_BUTTON6, &CTeacherManagerClass::OnBnClickedButton6)
	ON_NOTIFY(NM_CLICK, IDC_LIST2, &CTeacherManagerClass::OnNMClickList2)
	ON_BN_CLICKED(IDC_BUTTON4, &CTeacherManagerClass::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CTeacherManagerClass::OnBnClickedButton5)
END_MESSAGE_MAP()


// CTeacherManagerClass 消息处理程序


BOOL CTeacherManagerClass::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	CMainFrame* frame = (CMainFrame*)AfxGetMainWnd();
	CManagerSystemDoc* pDoc = (CManagerSystemDoc*)frame->GetActiveDocument();
	Ccoursetable* pSet = (Ccoursetable*)pDoc->GetCourseSet();
	Cs_classinfo* pset = (Cs_classinfo*)pDoc->getClassChangedSet();
	Csscholasticin*Stu = (Csscholasticin*)pDoc->GetSscholSet();
	Csbasicinformation* stu = (Csbasicinformation*)pDoc->GetStudentBasic();
	// TODO:  在此添加额外的初始化
	pDoc->plistCtrl = &m_list;
	////////////////////////////////////////////////////////////////////////// 列表控件初始化
	CString head[] = { TEXT("学号"), TEXT("姓名"), TEXT("班级"), TEXT("所属院系"), TEXT("分数") };
	m_list.SetExtendedStyle(m_list.GetExtendedStyle()
		| LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
	m_list.InsertColumn(0, head[0], LVCFMT_CENTER, 100);
	m_list.InsertColumn(1, head[1], LVCFMT_CENTER, 100);
	m_list.InsertColumn(2, head[2], LVCFMT_CENTER, 100);
	m_list.InsertColumn(3, head[3], LVCFMT_CENTER, 130);
	m_list.InsertColumn(4, head[4], LVCFMT_CENTER, 100);
	//////////////////////////////////////////////////////////////////////////
	if (pset->IsOpen()==FALSE)
	{
		pset->Open();
	}
	if (Stu->IsOpen()==FALSE)
	{
		Stu->Open();
	}
	if (stu->IsOpen()==FALSE)
	{
		stu->Open();
	}
	CString sql1;
	sql1.Format(TEXT("T_number='%d'"), pDoc->teacher_user);
	pset->m_strFilter = sql1;
	pset->Requery();
	int i = 0;
	while (pset->IsEOF()==FALSE)
	{
		CString sql3;
		sql3.Format(TEXT("S_number='%d'"), pset->m_S_number);
		Stu->m_strFilter = sql3;
		stu->m_strFilter = sql3;
		Stu->Requery();
		stu->Requery();
		CString str;
		str.Format(TEXT("%d"), pset->m_S_number);
		m_list.InsertItem(i, str);
		m_list.SetItemText(i, 1, (CString)stu->m_S_name);
		str.Format(TEXT("%d"), Stu->m_S_class);
		m_list.SetItemText(i, 2, str);
		m_list.SetItemText(i, 3, (CString)Stu->m_S_department);
		str.Format(TEXT("%d"), pset->m_S_grade);
		m_list.SetItemText(i, 4, str);
		sql3.Empty();
		Stu->m_strFilter = sql3;
		stu->m_strFilter = sql3;
		Stu->Requery();
		stu->Requery();
		pset->MoveNext();
		i++;
	}
	Stu->m_strFilter ="";
	stu->m_strFilter = "";
	Stu->Requery();
	stu->Requery();
	Stu->Close();
	stu->Close();
	////////////////////////////////////////////////////////////////////////// 列表控件初始化
	m_list_2.SetExtendedStyle(m_list_2.GetExtendedStyle()
		| LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
	m_list_2.InsertColumn(0, TEXT("课程名"), LVCFMT_CENTER, 100);
	m_list_2.InsertColumn(1, TEXT("选课人数"), LVCFMT_CENTER, 100);
	if (pSet->IsOpen()==FALSE)
	{
		pSet->Open();
	}
	//////////////////////////////////////////////////////////////////////////  列表初始化
	CString sql2;
	sql2.Format(TEXT("T_number='%d'"), pDoc->teacher_user);
	pSet->m_strFilter = sql2;
	pSet->Requery();
	i=0;
	while (pSet->IsEOF()==FALSE)
	{
		m_list_2.InsertItem(i, (CString)pSet->m_Class_name);
		CString str;
		str.Format(TEXT("%d"), pSet->m_Class_count);
		m_list_2.SetItemText(i, 1, str);
		i++;
		pSet->MoveNext();
	}
	pSet->m_strFilter = "";
	pSet->Requery();
	pSet->Close();
	//////////////////////////////////////////////////////////////////////////
	//初始化下拉框
	if (pSet->IsOpen()==FALSE)
	{
		pSet->Open();
	}
	CString sql;
	sql.Format(TEXT("T_number='%d'"), pDoc->teacher_user);
	pSet->m_strFilter = sql;
	pSet->Requery();
	while (pSet->IsEOF()==FALSE)
	{
		m_comboBox.AddString((CString)pSet->m_Class_name);
		pSet->MoveNext();
	}
	sql.Empty();
	pSet->m_strFilter = sql;
	pSet->Requery();
	pSet->Close();
	//m_comboBox.SetCurSel(0);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}


void CTeacherManagerClass::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码
	///////////////////////////////////////////////////////////////////////////
	//开设课程
	CclassAdd dlg;
	dlg.DoModal();
}


void CTeacherManagerClass::OnNMClickList4(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO:  在此添加控件通知处理程序代码
	CMainFrame* frame = (CMainFrame*)AfxGetMainWnd();
	CManagerSystemDoc* pDoc = (CManagerSystemDoc*)frame->GetActiveDocument();
	NM_LISTVIEW* pView = (NM_LISTVIEW*)pNMHDR;
	pDoc->teacher_manager_list2=pView->iItem;
	*pResult = 0;
}


void CTeacherManagerClass::OnBnClickedButton2()    
{
	// TODO:  在此添加控件通知处理程序代码
	//////////////////////////////////////////////////////////////////////////
	//删除课程
	CMainFrame* frame = (CMainFrame*)AfxGetMainWnd();
	CManagerSystemDoc* pDoc = (CManagerSystemDoc*)frame->GetActiveDocument();
	CDatabase db;
	Ccoursetable  pSet(&db);
	if (AfxMessageBox(TEXT("\n确认删除课程？ "), MB_YESNO) == IDYES)
	{
		if (pSet.Open()==FALSE)
		{
			pSet.Open();
		}
		CString sql;
		sql.Format(TEXT("T_number='%d' and Class_name='%s'"), pDoc->teacher_user, m_list_2.GetItemText(pDoc->teacher_manager_list2, 0));
		pSet.m_strFilter = sql;
		pSet.Requery();
		sql.Format(TEXT("call deleteclass('%d')"), pSet.m_Class_number);
		db.ExecuteSQL(sql);
		pSet.m_strFilter = "";
		pSet.Requery();
		pSet.Close();
		AfxMessageBox("删除成功！");
	}

}


void CTeacherManagerClass::OnBnClickedButton3()
{
	// TODO:  在此添加控件通知处理程序代码
	//////////////////////////////////////////////////////////////////////////
	//录入成绩
	CMainFrame* frame = (CMainFrame*)AfxGetMainWnd();
	CManagerSystemDoc* pDoc = (CManagerSystemDoc*)frame->GetActiveDocument();
	Ccoursetable* pSet = (Ccoursetable*)pDoc->GetCourseSet();
	Cs_classinfo* pset = (Cs_classinfo*)pDoc->getClassChangedSet();
	Csscholasticin* Stu = (Csscholasticin*)pDoc->GetSscholSet();
	Csbasicinformation* stu = (Csbasicinformation*)pDoc->GetStudentBasic();
	CListCtrl* pListCtrl = (CListCtrl*)GetDlgItem(IDC_LIST2);
	CComboBox* pCombox = (CComboBox*)GetDlgItem(IDC_COMBO1);
	int index = pCombox->GetCurSel();
	CString str,sql_name;
	pCombox->GetLBText(index, str);
	if (pSet->IsOpen()==FALSE)
	{
		pSet->Open();
	}
	sql_name.Format(TEXT("Class_name='%s'"), str);
	pSet->m_strFilter = sql_name;
	pSet->Requery();
	if (Stu->IsOpen()==FALSE)
	{
		Stu->Open();
	}
	if (stu->IsOpen()==FALSE)
	{
		stu->Open();
	}
	if (pset->IsOpen()==FALSE)
	{
		pset->Open();
	}
	CString sql;
	sql.Format(TEXT("S_number='%d'"),_ttoi(pListCtrl->GetItemText(pDoc->teacher_manager_list, 0)));
	Stu->m_strFilter = sql;
	stu->m_strFilter = sql;
	Stu->Requery();
	stu->Requery();
	if (Stu->GetRecordCount()!=0&&stu->GetRecordCount()!=0)
	{
		pDoc->D_Snumber = Stu->m_S_number;
		pDoc->D_name = (CString)stu->m_S_name;
		pDoc->D_Sdepartment = (CString)Stu->m_S_department;
		sql.Format(TEXT("S_number='%d' and T_number='%d' and Class_number='%d'"), _ttoi(pListCtrl->GetItemText(pDoc->teacher_manager_list, 0)),
			pDoc->teacher_user, pSet->m_Class_number);
		pset->m_strFilter = sql;
		pset->Requery();
		pDoc->D_Sclass = str;
		pDoc->D_Sgrade = pset->m_S_grade;
		sql.Empty();
		pSet->m_strFilter = sql;
		pset->m_strFilter = sql;
		Stu->m_strFilter = sql;
		stu->m_strFilter = sql;
		pSet->Requery();
		pset->Requery();
		Stu->Requery();
		stu->Requery();
		pSet->Close();
		pset->Close();
		Stu->Close();
		stu->Close();
		CGrade dlg;
		dlg.DoModal();
	}
	else
	{
		AfxMessageBox("信息无效");
		return;
	}
	
}


void CTeacherManagerClass::OnCbnSelchangeCombo1()
{
	// TODO:  在此添加控件通知处理程序代码
	//////////////////////////////////////////////////////////////////////////
	//
	CMainFrame* frame = (CMainFrame*)AfxGetMainWnd();
	CManagerSystemDoc* pDoc = (CManagerSystemDoc*)frame->GetActiveDocument();
	Ccoursetable* pSet = (Ccoursetable*)pDoc->GetCourseSet();
	Cs_classinfo* pset = (Cs_classinfo*)pDoc->getClassChangedSet();
	Csscholasticin* Stu = (Csscholasticin*)pDoc->GetSscholSet();
	Csbasicinformation* stu = (Csbasicinformation*)pDoc->GetStudentBasic();
	int m = m_comboBox.GetCurSel();
	CString str;
	m_comboBox.GetLBText(m, str);
	pDoc->comboxstr = str;
	pDoc->comboxint = m;
	if (pSet->IsOpen()==FALSE)
	{
		pSet->Open();
	}
	if (Stu->IsOpen()==FALSE)
	{
		Stu->Open();
	}
	if (stu->IsOpen()==FALSE)
	{
		stu->Open();
	}
	if (pset->IsOpen()==FALSE)
	{
		pset->Open();
	}
	CString sql;
	sql.Format(TEXT("T_number='%d' and Class_name='%s'"), pDoc->teacher_user, str);
	pSet->m_strFilter = sql;
	pSet->Requery();
	CString sqls;
	sqls.Format(TEXT("Class_number='%d'and T_number='%d'"),pSet->m_Class_number,pDoc->teacher_user);
	pset->m_strFilter = sqls;
	pset->Requery();
	m_list.DeleteAllItems();
	int i = 0;
	while (pset->IsEOF()==FALSE)
	{
		CString sql3;
		sql3.Format(TEXT("S_number='%d'"), pset->m_S_number);
		Stu->m_strFilter = sql3;
		stu->m_strFilter = sql3;
		Stu->Requery();
		stu->Requery();
		CString strm;
		strm.Format(TEXT("%d"), pset->m_S_number);
		m_list.InsertItem(i, strm);
		m_list.SetItemText(i, 1, (CString)stu->m_S_name);
		strm.Format(TEXT("%d"), Stu->m_S_class);
		m_list.SetItemText(i, 2, strm);
		m_list.SetItemText(i, 3, (CString)Stu->m_S_department);
		str.Format(TEXT("%d"), pset->m_S_grade);
		m_list.SetItemText(i, 4, str);
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
	Stu-> Requery();
	stu-> Requery();
	pSet->Close();
	pset->Close();
	Stu-> Close();
	stu-> Close();

}


void CTeacherManagerClass::OnBnClickedButton6()
{
	// TODO:  在此添加控件通知处理程序代码
	//////////////////////////////////////////////////////////////////////////
	//刷新课程
	m_list_2.DeleteAllItems();
	CMainFrame* frame = (CMainFrame*)AfxGetMainWnd();
	CManagerSystemDoc* pDoc = (CManagerSystemDoc*)frame->GetActiveDocument();
	Ccoursetable* pSet = (Ccoursetable*)pDoc->GetCourseSet();
	Cs_classinfo* pset = (Cs_classinfo*)pDoc->getClassChangedSet();
	Csscholasticin*Stu = (Csscholasticin*)pDoc->GetSscholSet();
	Csbasicinformation* stu = (Csbasicinformation*)pDoc->GetStudentBasic();
	if (pSet->IsOpen() == FALSE)
	{
		pSet->Open();
	}
	//////////////////////////////////////////////////////////////////////////  列表初始化
	CString sql2;
	sql2.Format(TEXT("T_number='%d'"), pDoc->teacher_user);
	pSet->m_strFilter = sql2;
	pSet->Requery();
	int i = 0;
	while (pSet->IsEOF() == FALSE)
	{
		m_list_2.InsertItem(i, (CString)pSet->m_Class_name);
		CString str;
		str.Format(TEXT("%d"), pSet->m_Class_count);
		m_list_2.SetItemText(i, 1, str);
		i++;
		pSet->MoveNext();
	}
	pSet->m_strFilter = "";
	pSet->Requery();
	pSet->Close();
	//////////////////////////////////////////////////////////////////////////
	//初始化下拉框
	if (pSet->IsOpen() == FALSE)
	{
		pSet->Open();
	}
	CString sql;
	sql.Format(TEXT("T_number='%d'"), pDoc->teacher_user);
	pSet->m_strFilter = sql;
	pSet->Requery();
	int j = 0;
	m_comboBox.DeleteString(j);
	while (pSet->IsEOF() == FALSE)
	{
		m_comboBox.DeleteString(j);
		m_comboBox.AddString((CString)pSet->m_Class_name);
		pSet->MoveNext();
		j++;
	}
	sql.Empty();
	pSet->m_strFilter = sql;
	pSet->Requery();
	pSet->Close();
	m_comboBox.SetCurSel(0);

}


void CTeacherManagerClass::OnNMClickList2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO:  在此添加控件通知处理程序代码
	CMainFrame* frame = (CMainFrame*)AfxGetMainWnd();
	CManagerSystemDoc* pDoc = (CManagerSystemDoc*)frame->GetActiveDocument();
	NM_LISTVIEW* pView = (NM_LISTVIEW*)pNMHDR;
	pDoc->teacher_manager_list = pView->iItem;
	*pResult = 0;
}


void CTeacherManagerClass::OnBnClickedButton4()
{
	// TODO:  在此添加控件通知处理程序代码
	if (m_list.GetItemCount() <= 0)
	{
		AfxMessageBox(TEXT("列表中无记录可以保存！"));
		return;
	}
	//打开另存为对话框，需要包含#include<Afxdlgs.h>
	char szFilters[] = _T("txt文件(*.txt) | *.txt | xls文件(*.xls) | *.xls | 所有文件(*.*)|*.*||");
	CFileDialog dlg(FALSE, _T("txt"), _T("选课名单"), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, szFilters, this);
	if (dlg.DoModal() != IDOK)
		return;
	CString strFilePath;
	strFilePath = dlg.GetPathName();
	DWORD dwRe = GetFileAttributes(strFilePath);
	if (dwRe != (DWORD)-1)
	{
		DeleteFile(strFilePath);
	}
	FILE* fp;
	fopen_s(&fp, strFilePath, "w");
	char str[1024];
	if (fp == NULL)
	{
		printf("save file error\n");
		return;
	}
	int nHeadNum = m_list.GetHeaderCtrl()->GetItemCount();
	LVCOLUMN lvcol;
	char str_out[256];
	int nColNum;
	nColNum = 0;
	lvcol.mask = LVCF_TEXT;
	lvcol.pszText = str_out;
	lvcol.cchTextMax = 256;
	while (m_list.GetColumn(nColNum, &lvcol))
	{
		nColNum++;
		fprintf_s(fp, "%s\t", lvcol.pszText);
	}
	fprintf_s(fp, "\n", lvcol.pszText);


	int nRow = m_list.GetItemCount();
	for (int i = 0; i < nRow; i++)
	{
		for (int j = 0; j < nColNum; j++)
		{
			CString str_data = this->m_list.GetItemText(i, j);
			fprintf_s(fp, "%s\t", str_data);
		}
		fprintf_s(fp, "\n");
	}
	fclose(fp);
	AfxMessageBox(TEXT("保存成功！"));

}


void CTeacherManagerClass::OnBnClickedButton5()
{
	// TODO:  在此添加控件通知处理程序代码
	//////////////////////////////////////////////////////////////////////////
	//教学评估
	CMainFrame* frame = (CMainFrame*)AfxGetMainWnd();
	CManagerSystemDoc* pDoc = (CManagerSystemDoc*)frame->GetActiveDocument();
	Ccoursetable* pSet = (Ccoursetable*)pDoc->GetCourseSet();
	Cs_classinfo* pset = (Cs_classinfo*)pDoc->getClassChangedSet();
	Csscholasticin*Stu = (Csscholasticin*)pDoc->GetSscholSet();
	Csbasicinformation* stu = (Csbasicinformation*)pDoc->GetStudentBasic();
	CString str = pDoc->comboxstr;
	if (pSet->IsOpen()==FALSE)
	{
		pSet->Open();
	}
	CString sql;
	sql.Format(TEXT("Class_name='%s'"), str);
	pSet->m_strFilter = sql;
	pSet->Requery();
	if (pset->IsOpen()==FALSE)
	{
		pset->Open();
	}
	sql.Format(TEXT("Class_number='%d'"), pSet->m_Class_number);
	pset->m_strFilter = sql;
	pset->Requery();
	pDoc->initvector();
	pDoc->average = 0;
	pDoc->sum_student = 0;
	pDoc->sum_grade = 0;
	pDoc->max_grade = 0;
	pDoc->min_grade = 100;
	while (pset->IsEOF()==FALSE)
	{
		if (pset->m_S_grade>pDoc->max_grade)
		{
			pDoc->max_grade = pset->m_S_grade;
		}
		if (pset->m_S_grade<pDoc->min_grade)
		{
			pDoc->min_grade = pset->m_S_grade;
		}
		//////////////////////////////////////////////////////////////////////////0-10
		if (pset->m_S_grade>=0&&pset->m_S_grade<=10)
		{
			pDoc->grade[0]++;
		}
		//////////////////////////////////////////////////////////////////////////10-20
		if (pset->m_S_grade >10 && pset->m_S_grade <= 20)
		{
			pDoc->grade[1]++;
		}
		//////////////////////////////////////////////////////////////////////////20-30
		if (pset->m_S_grade >20 && pset->m_S_grade <= 30)
		{
			pDoc->grade[2]++;
		}
		//////////////////////////////////////////////////////////////////////////30-40
		if (pset->m_S_grade >30 && pset->m_S_grade <= 40)
		{
			pDoc->grade[3]++;
		}
		//////////////////////////////////////////////////////////////////////////40-50
		if (pset->m_S_grade >40 && pset->m_S_grade <= 50)
		{
			pDoc->grade[4]++;
		}
		//////////////////////////////////////////////////////////////////////////50-60
		if (pset->m_S_grade >50 && pset->m_S_grade <= 60)
		{
			pDoc->grade[5]++;
		}
		//////////////////////////////////////////////////////////////////////////60-70
		if (pset->m_S_grade >60 && pset->m_S_grade <= 70)
		{
			pDoc->grade[6]++;
		}
		//////////////////////////////////////////////////////////////////////////70-80
		if (pset->m_S_grade >70 && pset->m_S_grade <= 80)
		{
			pDoc->grade[7]++;
		}
		//////////////////////////////////////////////////////////////////////////80-90
		if (pset->m_S_grade >80 && pset->m_S_grade <= 90)
		{
			pDoc->grade[8]++;
		}
		//////////////////////////////////////////////////////////////////////////90-100
		if (pset->m_S_grade >90 && pset->m_S_grade <= 100)
		{
			pDoc->grade[9]++;
		}
		pset->MoveNext();
	}
	pset->Requery();
	while (pset->IsEOF()==FALSE)
	{
		pDoc->sum_grade += pset->m_S_grade;
		pset->MoveNext();
	}
	for (int i = 0; i < 10;i++)
	{
		pDoc->sum_student += pDoc->grade[i];
	}
	int sum=0;
	for (int i = 0; i < 6;i++)
	{
		sum += pDoc->grade[i];
	}
	pDoc->average =(float)pDoc->sum_grade / pDoc->sum_student;
	pDoc->unpass = (float)sum / pDoc->sum_student;
	pset->m_strFilter = "";
	pset->Requery();
	pset->Close();
// 	CDatabase db;
// 	Cs_classinfo  pset1(&db);
// 	if (pset1.IsOpen()==FALSE)
// 	{
// 		pset1.Open();
// 	}
// 	CString sql1;
// 	sql1.Format("select max(S_grade) from s_classinfo where Class_number='900001' and T_number='101001'");
// 	db.ExecuteSQL(sql1);
// 	db.
// 	CString strw;
// 	strw.Format(TEXT("%d"), pset1.m_S_grade);
// 	AfxMessageBox(strw);
	CTeachCalculate dlg;
	dlg.DoModal();
}
