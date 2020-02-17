// CclassAdd.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ManagerSystem.h"
#include "CclassAdd.h"
#include "afxdialogex.h"
#include "MainFrm.h"
#include "ManagerSystemDoc.h"
#include "coursetable.h"

// CclassAdd �Ի���

IMPLEMENT_DYNAMIC(CclassAdd, CDialogEx)

CclassAdd::CclassAdd(CWnd* pParent /*=NULL*/)
	: CDialogEx(CclassAdd::IDD, pParent)
	, m_classnum(0)
	, m_tnum(0)
	, m_classname_G(_T(""))
	, m_opendepart(_T(""))
	, m_credit(0)
{

}

CclassAdd::~CclassAdd()
{
}

void CclassAdd::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_classnum);
	DDX_Text(pDX, IDC_EDIT2, m_tnum);
	DDX_Text(pDX, IDC_EDIT15, m_classname_G);
	DDX_Text(pDX, IDC_EDIT16, m_opendepart);
	DDX_Text(pDX, IDC_EDIT17, m_credit);
}


BEGIN_MESSAGE_MAP(CclassAdd, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON4, &CclassAdd::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CclassAdd::OnBnClickedButton5)
END_MESSAGE_MAP()


// CclassAdd ��Ϣ�������


void CclassAdd::OnBnClickedButton4()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CMainFrame* frame = (CMainFrame*)AfxGetMainWnd();
	CManagerSystemDoc* pDoc = (CManagerSystemDoc*)frame->GetActiveDocument();
	Ccoursetable*pSet = (Ccoursetable*)pDoc->GetCourseSet();
	UpdateData(TRUE);
	if (AfxMessageBox(TEXT("\nȷ�Ͽ���γ̣�: "), MB_YESNO) == IDYES)
	{
		if (pSet->IsOpen()==FALSE)
		{
			pSet->Open();
		}
		pSet->AddNew();
		pSet->m_Class_number = m_classnum;
		pSet->m_T_number = m_tnum;
		pSet->m_Class_name = m_classname_G;
		pSet->m_SetDepartment = m_opendepart;
		pSet->m_Credit = m_credit;
		pSet->m_Class_count = 0;
		pSet->Update();
		AfxMessageBox("����ɹ���");
		pSet->Close();
	}
	OnOK();
}


void CclassAdd::OnBnClickedButton5()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	OnCancel();
}
