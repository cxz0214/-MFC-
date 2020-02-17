// NoramlUser.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ManagerSystem.h"
#include "NoramlUser.h"
#include "afxdialogex.h"
#include "MainFrm.h"
#include "ManagerSystemDoc.h"
#include "teacher_login.h"
#include "student_login.h"

// CNoramlUser �Ի���

IMPLEMENT_DYNAMIC(CNoramlUser, CDialogEx)

CNoramlUser::CNoramlUser(CWnd* pParent /*=NULL*/)
	: CDialogEx(CNoramlUser::IDD, pParent)
	, m_GUIUser(0)
	, m_GUIPassword(_T(""))
{

}

CNoramlUser::~CNoramlUser()
{
}

void CNoramlUser::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_GUIUser);
	DDX_Text(pDX, IDC_EDIT2, m_GUIPassword);
}


BEGIN_MESSAGE_MAP(CNoramlUser, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CNoramlUser::OnBnClickedButton1)
END_MESSAGE_MAP()


// CNoramlUser ��Ϣ�������


BOOL CNoramlUser::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	CMainFrame* frame = (CMainFrame*)AfxGetMainWnd();
	CManagerSystemDoc* pDoc = (CManagerSystemDoc*)frame->GetActiveDocument();
	Cteacher_login* pSet = (Cteacher_login*)pDoc->GetTeacherSet();
	Cstudent_login* pset = (Cstudent_login*)pDoc->GetStudentSet();
	CString str;
	if (pDoc->teacher_user > 0)
	{
		m_GUIUser=pDoc->teacher_user;
	}
	else{
		m_GUIUser= pDoc->student_user;
	}
	if (pSet->IsOpen() == FALSE)
	{
		pSet->Open();
	}
	if (pset->IsOpen() == FALSE)
	{
		pset->Open();
	}
	if (pDoc->teacher_user > 0)   //��ʦ��¼
	{
		CString sql;
		sql.Format(TEXT("T_number='%d'"), pDoc->teacher_user);
		pSet->m_strFilter = sql;
		pSet->Requery();
		m_GUIPassword = pSet->m_T_password;
	}
	else
	{
		CString sql;
		sql.Format(TEXT("S_number='%d'"), pDoc->student_user);
		pset->m_strFilter = sql;
		pset->Requery();
		m_GUIPassword = pset->m_S_password;
	}
	UpdateData(FALSE);
	GetDlgItem(IDC_EDIT1)->EnableWindow(FALSE);
	pSet->m_strFilter = "";
	pset->m_strFilter = "";
	pSet->Requery();
	pset->Requery();
	pSet->Close();
	pset->Close();

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}


void CNoramlUser::OnBnClickedButton1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CMainFrame* frame = (CMainFrame*)AfxGetMainWnd();
	CManagerSystemDoc* pDoc = (CManagerSystemDoc*)frame->GetActiveDocument();
	Cteacher_login* pSet = (Cteacher_login*)pDoc->GetTeacherSet();
	Cstudent_login* pset = (Cstudent_login*)pDoc->GetStudentSet();
	UpdateData(TRUE);
	CString str;
	if (pSet->IsOpen() == FALSE)
	{
		pSet->Open();
	}
	if (pset->IsOpen() == FALSE)
	{
		pset->Open();
	}
	if (pDoc->teacher_user > 0)   //��ʦ��¼
	{
		CString sql;
		sql.Format(TEXT("T_number='%d'"), pDoc->teacher_user);
		pSet->m_strFilter = sql;
		pSet->Requery();
		pSet->Edit();
		pSet->m_T_password = m_GUIPassword;
		pSet->Update();
		AfxMessageBox("�޸ĳɹ���");
	}
	else
	{
		CString sql;
		sql.Format(TEXT("S_number='%d'"), pDoc->student_user);
		pset->m_strFilter = sql;
		pset->Requery();
		pset->Edit();
		pset->m_S_password = m_GUIPassword;
		pset->Update();	
		AfxMessageBox("�޸ĳɹ���");
		
	}
	UpdateData(FALSE);
	GetDlgItem(IDC_EDIT1)->EnableWindow(FALSE);
	pSet->m_strFilter = "";
	pset->m_strFilter = "";
	pSet->Requery();
	pset->Requery();
	pSet->Close();
	pset->Close();
	OnOK();
}
