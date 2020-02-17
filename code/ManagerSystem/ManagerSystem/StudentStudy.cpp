// StudentStudy.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ManagerSystem.h"
#include "StudentStudy.h"
#include "afxdialogex.h"
#include "MainFrm.h"
#include "ManagerSystemDoc.h"
#include "StudentBasic.h"
#include "StudyModify.h"
// CStudentStudy �Ի���

IMPLEMENT_DYNAMIC(CStudentStudy, CDialogEx)

CStudentStudy::CStudentStudy(CWnd* pParent /*=NULL*/)
	: CDialogEx(CStudentStudy::IDD, pParent)
{

}

CStudentStudy::~CStudentStudy()
{
}

void CStudentStudy::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST2, m_studyGUI);
}


BEGIN_MESSAGE_MAP(CStudentStudy, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CStudentStudy::OnBnClickedButton1)
	ON_NOTIFY(NM_CLICK, IDC_LIST2, &CStudentStudy::OnNMClickList2)
	ON_BN_CLICKED(IDC_BUTTON6, &CStudentStudy::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CStudentStudy::OnBnClickedButton7)
END_MESSAGE_MAP()


// CStudentStudy ��Ϣ�������


BOOL CStudentStudy::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_studyGUI.DeleteColumn(NULL);
	m_studyGUI.DeleteAllItems();
	CString head[] = { TEXT("ѧ��"), TEXT("����"), TEXT("�༶"), TEXT("�༶���"), TEXT("����Ժϵ"), TEXT("רҵ"),
		TEXT("ƽ��ѧ�ּ���") };
	m_studyGUI.SetExtendedStyle(m_studyGUI.GetExtendedStyle()
		| LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
	m_studyGUI.InsertColumn(0, head[0], LVCFMT_CENTER, 100);
	m_studyGUI.InsertColumn(1, head[1], LVCFMT_CENTER, 100);
	m_studyGUI.InsertColumn(2, head[2], LVCFMT_CENTER, 80);
	m_studyGUI.InsertColumn(3, head[3], LVCFMT_CENTER, 100);
	m_studyGUI.InsertColumn(4, head[4], LVCFMT_CENTER, 100);
	m_studyGUI.InsertColumn(5, head[5], LVCFMT_CENTER, 140);
	m_studyGUI.InsertColumn(6, head[6], LVCFMT_CENTER, 120);
	CMainFrame* frame = (CMainFrame*)AfxGetMainWnd();
	CManagerSystemDoc* pDoc = (CManagerSystemDoc*)frame->GetActiveDocument();
	Csbasicinformation* pset = (Csbasicinformation*)pDoc->GetStudentBasic();
	Csscholasticin* pSet = (Csscholasticin*)pDoc->GetSscholSet();
	if (pSet->IsOpen() == FALSE)
	{
		pSet->Open();
	}
	if (pset->IsOpen()==FALSE)
	{
		pset->Open();
	}
	pSet->Requery();
	for (int i = 0; i < pSet->GetRecordCount(); i++)
	{
		CString sql;
		sql.Format(TEXT("S_number='%d'"), pSet->m_S_number);
		pset->m_strFilter = sql;
		pset->Requery();
		sql.Empty();
		CString str;
		str.Format(TEXT("%d"), pSet->m_S_number);
		int j = 1;
		m_studyGUI.InsertItem(i, str);
		m_studyGUI.SetItemText(i, j++, (CString)pset->m_S_name);
		str.Format(TEXT("%d"), pSet->m_S_class);
		m_studyGUI.SetItemText(i, j++, str);
		str.Format(TEXT("%d"), pSet->m_S_serial);
		m_studyGUI.SetItemText(i, j++, str);
		m_studyGUI.SetItemText(i, j++, (CString)pSet->m_S_department);
		m_studyGUI.SetItemText(i, j++, (CString)pSet->m_S_major);
		str.Format(TEXT("%.2f"), pSet->m_S_gpa);
		m_studyGUI.SetItemText(i, j++, str);
		pSet->MoveNext();
	}
	pset->m_strFilter = "";
	pSet->Close();
	pset->Close();
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}


void CStudentStudy::OnBnClickedButton1()      //ѧ����Ϣ���
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CMainFrame*frame = (CMainFrame*)AfxGetMainWnd();
	CManagerSystemDoc* pDoc = (CManagerSystemDoc*)frame->GetActiveDocument();
	CListCtrl* pListCtrl = (CListCtrl*)GetDlgItem(IDC_LIST2);
	int i = pDoc->study_num;
	if (i<0)
	{
		AfxMessageBox("δѡ���κ�ѧ������ѡ�������");
	}
	else
	{
		CString str;
		str = pListCtrl->GetItemText(i, 0);
		pDoc->stu_number = _ttoi(str);
		str = pListCtrl->GetItemText(i, 1);
		pDoc->stu_name = str;
		str = pListCtrl->GetItemText(i, 2);
		pDoc->stu_class = _ttoi(str);
		str = pListCtrl->GetItemText(i, 3);
		pDoc->stu_seril = _ttoi(str);
		str = pListCtrl->GetItemText(i, 4);
		pDoc->stu_department = str;
		str = pListCtrl->GetItemText(i, 5);
		pDoc->stu_major = str;
		str = pListCtrl->GetItemText(i, 6);
		pDoc->stu_gpa = _ttof(str);
		CStudyModify Dlg;
		Dlg.DoModal();
	}
	
}


void CStudentStudy::OnNMClickList2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	NM_LISTVIEW* plist = (NM_LISTVIEW*)pNMHDR;
	CMainFrame*frame = (CMainFrame*)AfxGetMainWnd();
	CManagerSystemDoc* pDoc = (CManagerSystemDoc*)frame->GetActiveDocument();
	pDoc->study_num = plist->iItem;
	*pResult = 0;
}


void CStudentStudy::OnBnClickedButton6()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	OnCancel();
}


void CStudentStudy::OnBnClickedButton7()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_studyGUI.DeleteAllItems();
	CMainFrame* frame = (CMainFrame*)AfxGetMainWnd();
	CManagerSystemDoc* pDoc = (CManagerSystemDoc*)frame->GetActiveDocument();
	Csbasicinformation* pset = (Csbasicinformation*)pDoc->GetStudentBasic();
	Csscholasticin* pSet = (Csscholasticin*)pDoc->GetSscholSet();
	if (pSet->IsOpen() == FALSE)
	{
		pSet->Open();
	}
	if (pset->IsOpen() == FALSE)
	{
		pset->Open();
	}
	pSet->Requery();
	for (int i = 0; i < pSet->GetRecordCount(); i++)
	{
		CString sql;
		sql.Format(TEXT("S_number='%d'"), pSet->m_S_number);
		pset->m_strFilter = sql;
		pset->Requery();
		sql.Empty();
		CString str;
		str.Format(TEXT("%d"), pSet->m_S_number);
		int j = 1;
		m_studyGUI.InsertItem(i, str);
		m_studyGUI.SetItemText(i, j++, (CString)pset->m_S_name);
		str.Format(TEXT("%d"), pSet->m_S_class);
		m_studyGUI.SetItemText(i, j++, str);
		str.Format(TEXT("%d"), pSet->m_S_serial);
		m_studyGUI.SetItemText(i, j++, str);
		m_studyGUI.SetItemText(i, j++, (CString)pSet->m_S_department);
		m_studyGUI.SetItemText(i, j++, (CString)pSet->m_S_major);
		str.Format(TEXT("%.2f"), pSet->m_S_gpa);
		m_studyGUI.SetItemText(i, j++, str);
		pSet->MoveNext();
	}
	pset->m_strFilter = "";
	pSet->Close();
	pset->Close();
	
}
