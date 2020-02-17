// LoginGUI.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ManagerSystem.h"
#include "LoginGUI.h"
#include "afxdialogex.h"
#include"MainFrm.h"
#include "ManagerSystemDoc.h"
#include "admin_login.h"

// CLoginGUI �Ի���

IMPLEMENT_DYNAMIC(CLoginGUI, CDialogEx)

CLoginGUI::CLoginGUI(CWnd* pParent /*=NULL*/)
	: CDialogEx(CLoginGUI::IDD, pParent)
	, m_uiAdmin(_T(""))
	, m_uiAdminPassword(_T(""))
{

}

CLoginGUI::~CLoginGUI()
{
}

void CLoginGUI::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_change);
	DDX_Text(pDX, IDC_EDIT1, m_uiAdmin);
	DDX_Text(pDX, IDC_EDIT2, m_uiAdminPassword);
}


BEGIN_MESSAGE_MAP(CLoginGUI, CDialogEx)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CLoginGUI::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_BUTTON1, &CLoginGUI::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CLoginGUI::OnBnClickedButton2)
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// CLoginGUI ��Ϣ�������


BOOL CLoginGUI::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_change.SetCurSel(0);
	m_uiAdmin = TEXT("CXZ");
	m_uiAdminPassword = TEXT("0214");
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}


void CLoginGUI::OnCbnSelchangeCombo1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CMainFrame* frame = (CMainFrame*)AfxGetMainWnd();
	CManagerSystemDoc* pDoc = (CManagerSystemDoc*)frame->GetActiveDocument();
	pDoc->login_num = m_change.GetCurSel();
	
}


void CLoginGUI::OnBnClickedButton1()//��¼
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//��ȡ���ָ��
	CMainFrame * mainfram = (CMainFrame*)AfxGetMainWnd();
	//��ȡ�ĵ������ָ��
	CManagerSystemDoc* pDoc = (CManagerSystemDoc*)mainfram->GetActiveDocument();
	//��ȡ�û����ݿ��¼��ָ��
	Cadmin_login* pAdminset = pDoc->GetAdminSet();
	Cstudent_login*pStuSet =pDoc->GetStudentSet();
	Cteacher_login*pTeachSet = pDoc->GetTeacherSet();
	if (pAdminset->IsOpen()==FALSE)
	{
		//������ݿ�δ�򿪣�������ݿ�
		pAdminset->Open();
	}
	if (pStuSet->IsOpen()==FALSE)
	{
		pStuSet->Open();
	}
	if (pTeachSet->IsOpen()==FALSE)
	{
		pTeachSet->Open();
	}

	UpdateData(TRUE);
	if (m_uiAdmin.IsEmpty()||m_uiAdminPassword.IsEmpty())
	{
		AfxMessageBox("�û��������벻��Ϊ�գ����������룡");
	}
	else
	{
		BOOL state = FALSE;
		int index = m_change.GetCurSel();
		if (index == 0)
		{
			CString sql;
			sql.Format(TEXT("Admin_login='%s' and Admin_password='%s'"), m_uiAdmin, m_uiAdminPassword);
			pAdminset->m_strFilter = sql;
			pAdminset->Requery();
			if (pAdminset->GetRecordCount() == 0)
			{
				AfxMessageBox("�û������������");
			}
			else
			{
				AfxMessageBox("��¼�ɹ���");
				state = TRUE;
			}

			pAdminset->Close();
		}
		else if (index == 2)
		{
			CString sql;
			sql.Format(TEXT("S_number='%s' and S_password='%s'"), m_uiAdmin, m_uiAdminPassword);
			pStuSet->m_strFilter = sql;
			pStuSet->Requery();
			if (pStuSet->GetRecordCount() == 0)
			{
				AfxMessageBox("�û������������");
			}
			else
			{
				AfxMessageBox("��¼�ɹ���");
				pDoc->student_user = _ttoi(m_uiAdmin);
				state = TRUE;
			}

			pStuSet->Close();
		}
		else
		{
			CString sql;
			sql.Format(TEXT("T_number='%s' and T_password='%s'"), m_uiAdmin, m_uiAdminPassword);
			pTeachSet->m_strFilter = sql;
			pTeachSet->Requery();
			if (pTeachSet->GetRecordCount() == 0)
			{
				AfxMessageBox("�û������������");
			}
			else
			{
				pDoc->teacher_user = _ttoi(m_uiAdmin);
				AfxMessageBox("��¼�ɹ���");
				state = TRUE;
			}

			pTeachSet->Close();
		}
		if (state == TRUE)
		{
			OnOK();
		}
	}
}


void CLoginGUI::OnBnClickedButton2()//ȡ����ť
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	OnClose();
}

void CLoginGUI::OnClose()
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	exit(1);
	CDialogEx::OnClose();
}
