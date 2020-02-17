// TeacherAdd.cpp : ʵ���ļ�
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
// CTeacherAdd �Ի���

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


// CTeacherAdd ��Ϣ�������


BOOL CTeacherAdd::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	CMainFrame*frame = (CMainFrame*)AfxGetMainWnd();
	CManagerSystemDoc* pDoc = (CManagerSystemDoc*)frame->GetActiveDocument();
	Cteacherinfo * pSet = (Cteacherinfo*)pDoc->GetTeacherInforSet();
	CString head[] = { TEXT("��ְ����"), TEXT("����"), TEXT("�Ա�"), TEXT("����Ժϵ") };
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
	// �쳣:  OCX ����ҳӦ���� FALSE
}


void CTeacherAdd::OnBnClickedButton1()    //��Ϣ���
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CTeacherADDGUI Dlg;
	Dlg.DoModal();

}


void CTeacherAdd::OnBnClickedButton5()       //��ʦ��Ϣ�޸�
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CMainFrame*frame = (CMainFrame*)AfxGetMainWnd();
	CManagerSystemDoc* pDoc = (CManagerSystemDoc*)frame->GetActiveDocument();
	CListCtrl* pListCtrl = (CListCtrl*)GetDlgItem(IDC_LIST1);
	int i = pDoc->teacher_num;
	if (i<0)
	{
		AfxMessageBox("δѡ���κ���Ϣ����ѡ����������룡");
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
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	NM_LISTVIEW* plist = (NM_LISTVIEW*)pNMHDR;
	CMainFrame*frame = (CMainFrame*)AfxGetMainWnd();
	CManagerSystemDoc* pDoc = (CManagerSystemDoc*)frame->GetActiveDocument();
	pDoc->teacher_num= plist->iItem;
	*pResult = 0;
}


void CTeacherAdd::OnBnClickedButton6()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
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
	if (AfxMessageBox(TEXT("\n��ְ����: ") + str + TEXT("\n��ʦ����: ") + pListCtrl->GetItemText(1, 1) + TEXT("\n�Ա�: ") + pListCtrl->GetItemText(1, 2) +
		TEXT("\n����Ժϵ��") + pListCtrl->GetItemText(1, 3), MB_YESNO) == IDYES)
	{
		pSet->Delete();
		sql.Empty();
		pSet->m_strFilter = sql;
		pSet->Close();
		AfxMessageBox("ɾ���ɹ���");
		OnOK();
	}
	else
		OnCancel();

}


void CTeacherAdd::OnBnClickedButton7()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	OnOK();
}
