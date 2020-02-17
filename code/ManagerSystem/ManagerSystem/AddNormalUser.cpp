// AddNormalUser.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ManagerSystem.h"
#include "AddNormalUser.h"
#include "afxdialogex.h"
#include "MainFrm.h"
#include "ManagerSystemDoc.h"
#include "NormalUser.h"
#include "ManagerSystemView.h"


// CAddNormalUser �Ի���

IMPLEMENT_DYNAMIC(CAddNormalUser, CDialogEx)

CAddNormalUser::CAddNormalUser(CWnd* pParent /*=NULL*/)
	: CDialogEx(CAddNormalUser::IDD, pParent)
	, m_normal_user(0)
	, m_normal_password(_T(""))
{

}

CAddNormalUser::~CAddNormalUser()
{
}

void CAddNormalUser::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_normal_user);
	DDX_Text(pDX, IDC_EDIT2, m_normal_password);
}


BEGIN_MESSAGE_MAP(CAddNormalUser, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CAddNormalUser::OnBnClickedButton1)
END_MESSAGE_MAP()


// CAddNormalUser ��Ϣ�������


void CAddNormalUser::OnBnClickedButton1()   //���
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CMainFrame* frame = (CMainFrame*)AfxGetMainWnd();
	CManagerSystemDoc* pDoc = (CManagerSystemDoc*)frame->GetActiveDocument();
	CManagerSystemView* pView = (CManagerSystemView*)frame->GetActiveView();
	Cstudent_login* pStuset=pDoc->GetStudentSet();
	Cteacher_login* pTeachset = pDoc->GetTeacherSet();
	UpdateData(TRUE);
	CNormalUser normaluser;
	normaluser.SetUserObj(m_normal_user, m_normal_password);
	int index = pView->m_MainFormChange.GetCurSel();
	if (index==1)
	{
		normaluser.AddNormalUser(pTeachset);
		AfxMessageBox("��ӳɹ���");
	}
	if (index==2)
	{
		normaluser.AddNormalUser(pStuset);
		AfxMessageBox("��ӳɹ���");
	}
	

}
