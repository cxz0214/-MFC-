// CchangeClass.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ManagerSystem.h"
#include "CchangeClass.h"
#include "afxdialogex.h"
#include "MainFrm.h"
#include "ManagerSystemDoc.h"
#include "s_classinfo.h"
#include "StudentChangeADD.h"
// CchangeClass �Ի���

IMPLEMENT_DYNAMIC(CchangeClass, CDialogEx)

CchangeClass::CchangeClass(CWnd* pParent /*=NULL*/)
	: CDialogEx(CchangeClass::IDD, pParent)
{

}

CchangeClass::~CchangeClass()
{
}

void CchangeClass::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_waitchange);
	DDX_Control(pDX, IDC_LIST3, m_changed);
}


BEGIN_MESSAGE_MAP(CchangeClass, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CchangeClass::OnBnClickedButton1)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, &CchangeClass::OnNMClickList1)
	ON_BN_CLICKED(IDC_BUTTON4, &CchangeClass::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CchangeClass::OnBnClickedButton5)
	ON_NOTIFY(NM_CLICK, IDC_LIST3, &CchangeClass::OnNMClickList3)
	ON_BN_CLICKED(IDC_BUTTON6, &CchangeClass::OnBnClickedButton6)
END_MESSAGE_MAP()


// CchangeClass ��Ϣ�������


BOOL CchangeClass::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	CMainFrame*frame = (CMainFrame*)AfxGetMainWnd();
	CManagerSystemDoc* pDoc = (CManagerSystemDoc*)frame->GetActiveDocument();
	Ccoursetable * pSet = (Ccoursetable*)pDoc->GetCourseSet();
	Cteacherinfo*pset = (Cteacherinfo*)pDoc->GetTeacherInforSet();
	Cs_classinfo* Pset = (Cs_classinfo*)pDoc->getClassChangedSet();
	CString head[] = { TEXT("�γ̱��"), TEXT("��ʦ����"), TEXT("��ʦ����"), TEXT("�γ�����") ,TEXT("��ѡ������"),TEXT("ѧ��"),TEXT("����Ժϵ")};
	//////////////////////////////////////////////////////////////////////////
	//��ѡ��
	m_waitchange.SetExtendedStyle(m_waitchange.GetExtendedStyle()
		| LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
	m_waitchange.InsertColumn(0, head[0], LVCFMT_CENTER, 100);
	m_waitchange.InsertColumn(1, head[1], LVCFMT_CENTER, 100);
	m_waitchange.InsertColumn(2, head[2], LVCFMT_CENTER, 100);
	m_waitchange.InsertColumn(3, head[3], LVCFMT_CENTER, 150);
	m_waitchange.InsertColumn(4, head[4], LVCFMT_CENTER, 100);
	m_waitchange.InsertColumn(5, head[5], LVCFMT_CENTER, 100);
	m_waitchange.InsertColumn(6, head[6], LVCFMT_CENTER, 170);
	if (pSet->IsOpen()==FALSE)
	{
		pSet->Open();
	}
	if (pset->IsOpen()==FALSE)
	{
		pset->Open();
	}
	pSet->Requery();
	int i = 0;
	while (pSet->IsEOF()==FALSE)
	{
		int j = 1;
		CString str;
		str.Format(TEXT("%d"), pSet->m_Class_number);
		m_waitchange.InsertItem(i, str);
		str.Format(TEXT("%d"), pSet->m_T_number);
		m_waitchange.SetItemText(i, j++, str);
		CString sql;
		sql.Format(TEXT("T_number='%d'"), pSet->m_T_number);
		pset->m_strFilter = sql;
		pset->Requery();
		m_waitchange.SetItemText(i, j++, (CString)pset->m_T_name);
		m_waitchange.SetItemText(i, j++, (CString)pSet->m_Class_name);
		str.Format(TEXT("%d"), pSet->m_Class_count);
		m_waitchange.SetItemText(i,j++, str);
		str.Format(TEXT("%.2f"), pSet->m_Credit);
		m_waitchange.SetItemText(i, j++, str);
		m_waitchange.SetItemText(i, j++, (CString)pSet->m_SetDepartment);
		pSet->MoveNext();
		i++;
		sql.Empty();
		pset->m_strFilter = sql;
		pset->Requery();
	}
	pset->Close();
	pSet->m_strFilter = "";
	pSet->Requery();
	pSet->Close();
	i = 0;
	//////////////////////////////////////////////////////////////////////////
	//��ѡ��
	m_changed.SetExtendedStyle(m_changed.GetExtendedStyle()
		| LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
	m_changed.InsertColumn(0, head[0], LVCFMT_CENTER, 100);
	m_changed.InsertColumn(1, head[1], LVCFMT_CENTER, 100);
	m_changed.InsertColumn(2, head[2], LVCFMT_CENTER, 100);
	m_changed.InsertColumn(3, head[3], LVCFMT_CENTER, 150);
	m_changed.InsertColumn(4, TEXT("����"), LVCFMT_CENTER, 100);
	m_changed.InsertColumn(5, head[5], LVCFMT_CENTER, 100);
	m_changed.InsertColumn(6, head[6], LVCFMT_CENTER, 170);
	if (Pset->IsOpen()==FALSE)
	{
		Pset->Open();
	}
	if (pSet->IsOpen()==FALSE)
	{
		pSet->Open();
	}
	if (pset->IsOpen()==FALSE)
	{
		pset->Open();
	}
	CString sql_re;
	sql_re.Format(TEXT("S_number='%d'"), pDoc->student_user);
	Pset->m_strFilter = sql_re;
	Pset->Requery();
	while (Pset->IsEOF()==FALSE)
	{
		int j = 1;
		CString str;
		str.Format(TEXT("%d"), Pset->m_Class_number);
		m_changed.InsertItem(i, str);
		str.Format(TEXT("%d"), Pset->m_T_number);
		m_changed.SetItemText(i, j++, str);
		//////////////////////////////////////////////////////////////////////////
		CString sql;
		sql.Format(TEXT("T_number='%d'"), Pset->m_T_number);
		pset->m_strFilter = sql;
		pset->Requery();
		//////////////////////////////////////////////////////////////////////////
		m_changed.SetItemText(i, j++, (CString)pset->m_T_name);
		//////////////////////////////////////////////////////////////////////////
		CString sql_course;
		sql_course.Format(TEXT("Class_number='%d' and T_number='%d'"), Pset->m_Class_number, Pset->m_T_number);
		pSet->m_strFilter = sql_course;
		pSet->Requery();
		m_changed.SetItemText(i, j++, (CString)pSet->m_Class_name);
		str.Format(TEXT("%d"), Pset->m_S_grade);
		m_changed.SetItemText(i, j++, str);
		str.Format(TEXT("%.2f"), pSet->m_Credit);
		m_changed.SetItemText(i, j++, str);
		m_changed.SetItemText(i, j++, (CString)pSet->m_SetDepartment);
		Pset->MoveNext();
		i++;
		sql.Empty();
		pset->m_strFilter = sql;
		pset->Requery();
		sql_course.Empty();
		pSet->m_strFilter = sql_course;
		pSet->Requery();
	}
	Pset->Close();
	pSet->Close();
	pset->Close();
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}


void CchangeClass::OnBnClickedButton1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//////////////////////////////////////////////////////////////////////////
	//���ѡ��
	CMainFrame*frame = (CMainFrame*)AfxGetMainWnd();
	CManagerSystemDoc* pDoc = (CManagerSystemDoc*)frame->GetActiveDocument();
	Cs_classinfo* pSet = (Cs_classinfo*)pDoc->getClassChangedSet();
	CStudentChangeADD classinstance;
	CListCtrl* pListCtrl = (CListCtrl*)GetDlgItem(IDC_LIST1);
	int i = pDoc->student_change_class;
	classinstance.SetClassSet(pSet);
	classinstance.SetClassObj(_ttoi(pListCtrl->GetItemText(i, 0)), pDoc->student_user, _ttoi(pListCtrl->GetItemText(i, 1)));
	classinstance.AddToClasstable();
	AfxMessageBox("ѡ�γɹ���");
	OnBnClickedButton4();
	OnBnClickedButton6();
}


void CchangeClass::OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	NM_LISTVIEW *pView = (NM_LISTVIEW *)pNMHDR;
	CMainFrame*frame = (CMainFrame*)AfxGetMainWnd();
	CManagerSystemDoc* pDoc = (CManagerSystemDoc*)frame->GetActiveDocument();
	pDoc->student_change_class=pView->iItem;
	*pResult = 0;
}


void CchangeClass::OnBnClickedButton4()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//////////////////////////////////////////////////////////////////////////
	//ˢ��ѡ�α�
	m_waitchange.DeleteAllItems();
	CMainFrame*frame = (CMainFrame*)AfxGetMainWnd();
	CManagerSystemDoc* pDoc = (CManagerSystemDoc*)frame->GetActiveDocument();
	Ccoursetable * pSet = (Ccoursetable*)pDoc->GetCourseSet();
	Cteacherinfo*pset = (Cteacherinfo*)pDoc->GetTeacherInforSet();
	if (pSet->IsOpen() == FALSE)
	{
		pSet->Open();
	}
	if (pset->IsOpen() == FALSE)
	{
		pset->Open();
	}
	pSet->Requery();
	int i = 0;
	while (pSet->IsEOF() == FALSE)
	{
		int j = 1;
		CString str;
		str.Format(TEXT("%d"), pSet->m_Class_number);
		m_waitchange.InsertItem(i, str);
		str.Format(TEXT("%d"), pSet->m_T_number);
		m_waitchange.SetItemText(i, j++, str);
		CString sql;
		sql.Format(TEXT("T_number='%d'"), pSet->m_T_number);
		pset->m_strFilter = sql;
		pset->Requery();
		m_waitchange.SetItemText(i, j++, (CString)pset->m_T_name);
		m_waitchange.SetItemText(i, j++, (CString)pSet->m_Class_name);
		str.Format(TEXT("%d"), pSet->m_Class_count);
		m_waitchange.SetItemText(i, j++, str);
		str.Format(TEXT("%.2f"), pSet->m_Credit);
		m_waitchange.SetItemText(i, j++, str);
		m_waitchange.SetItemText(i, j++, (CString)pSet->m_SetDepartment);
		pSet->MoveNext();
		i++;
		sql.Empty();
		pset->m_strFilter = sql;
		pset->Requery();
	}
	pset->Close();
	pSet->Close();
}


void CchangeClass::OnBnClickedButton5()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//////////////////////////////////////////////////////////////////////////
	//�˿�
	CMainFrame*frame = (CMainFrame*)AfxGetMainWnd();
	CManagerSystemDoc* pDoc = (CManagerSystemDoc*)frame->GetActiveDocument();
	Cs_classinfo* pSet = (Cs_classinfo*)pDoc->getClassChangedSet();
	CListCtrl* pListCtrl = (CListCtrl*)GetDlgItem(IDC_LIST3);
	if (pSet->IsOpen()==FALSE)
	{
		pSet->Open();
	}
	int i = pDoc->student_exit_class;
	CString sql;
	sql.Format(TEXT("T_number='%d' and S_number='%d' and Class_number='%d'"), _ttoi(pListCtrl->GetItemText(i, 1)),
		pDoc->student_user, _ttoi(pListCtrl->GetItemText(i, 0)));
	pSet->m_strFilter = sql;
	pSet->Requery();
	if (AfxMessageBox(TEXT("ȷ���˿Σ�"), MB_YESNO) == IDYES)
	{
		pSet->Delete();
		pSet->m_strFilter = "";
		pSet->Requery();
		pSet->Close();
		AfxMessageBox("�˿γɹ���");
	}
	OnBnClickedButton4();
	OnBnClickedButton6();
}


void CchangeClass::OnNMClickList3(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	NM_LISTVIEW *pView = (NM_LISTVIEW *)pNMHDR;
	CMainFrame*frame = (CMainFrame*)AfxGetMainWnd();
	CManagerSystemDoc* pDoc = (CManagerSystemDoc*)frame->GetActiveDocument();
	pDoc->student_exit_class = pView->iItem;
	*pResult = 0;
}


void CchangeClass::OnBnClickedButton6()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//////////////////////////////////////////////////////////////////////////
	//ˢ�¿α�
	m_changed.DeleteAllItems();
	CMainFrame*frame = (CMainFrame*)AfxGetMainWnd();
	CManagerSystemDoc* pDoc = (CManagerSystemDoc*)frame->GetActiveDocument();
	Ccoursetable * pSet = (Ccoursetable*)pDoc->GetCourseSet();
	Cteacherinfo*pset = (Cteacherinfo*)pDoc->GetTeacherInforSet();
	Cs_classinfo* Pset = (Cs_classinfo*)pDoc->getClassChangedSet();
	int i = 0;
	if (Pset->IsOpen() == FALSE)
	{
		Pset->Open();
	}
	if (pSet->IsOpen() == FALSE)
	{
		pSet->Open();
	}
	if (pset->IsOpen() == FALSE)
	{
		pset->Open();
	}
	CString sql_re;
	sql_re.Format(TEXT("S_number='%d'"), pDoc->student_user);
	Pset->m_strFilter = sql_re;
	Pset->Requery();
	while (Pset->IsEOF() == FALSE)
	{
		int j = 1;
		CString str;
		str.Format(TEXT("%d"), Pset->m_Class_number);
		m_changed.InsertItem(i, str);
		str.Format(TEXT("%d"), Pset->m_T_number);
		m_changed.SetItemText(i, j++, str);
		//////////////////////////////////////////////////////////////////////////
		CString sql;
		sql.Format(TEXT("T_number='%d'"), Pset->m_T_number);
		pset->m_strFilter = sql;
		pset->Requery();
		//////////////////////////////////////////////////////////////////////////
		m_changed.SetItemText(i, j++, (CString)pset->m_T_name);
		//////////////////////////////////////////////////////////////////////////
		CString sql_course;
		sql_course.Format(TEXT("Class_number='%d' and T_number='%d'"), Pset->m_Class_number, Pset->m_T_number);
		pSet->m_strFilter = sql_course;
		pSet->Requery();
		m_changed.SetItemText(i, j++, (CString)pSet->m_Class_name);
		str.Format(TEXT("%d"), Pset->m_S_grade);
		m_changed.SetItemText(i, j++, str);
		str.Format(TEXT("%.2f"), pSet->m_Credit);
		m_changed.SetItemText(i, j++, str);
		m_changed.SetItemText(i, j++, (CString)pSet->m_SetDepartment);
		Pset->MoveNext();
		i++;
		sql.Empty();
		pset->m_strFilter = sql;
		pset->Requery();
		sql_course.Empty();
		pSet->m_strFilter = sql_course;
		pSet->Requery();
	}
	Pset->Close();
	pSet->Close();
	pset->Close();

}
