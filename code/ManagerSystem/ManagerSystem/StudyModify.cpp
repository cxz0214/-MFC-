// StudyModify.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ManagerSystem.h"
#include "StudyModify.h"
#include "afxdialogex.h"
#include "MainFrm.h"
#include "ManagerSystemDoc.h"

// CStudyModify �Ի���

IMPLEMENT_DYNAMIC(CStudyModify, CDialogEx)

CStudyModify::CStudyModify(CWnd* pParent /*=NULL*/)
	: CDialogEx(CStudyModify::IDD, pParent)
	, m_GUInumber(0)
	, m_GUIname(_T(""))
	, m_GUIclass(0)
	, m_GUIseril(0)
	, m_GUIdepartment(_T(""))
	, m_GUImajor(_T(""))
	, m_GUIgpa(0)
{

}

CStudyModify::~CStudyModify()
{
}

void CStudyModify::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_GUInumber);
	DDX_Text(pDX, IDC_EDIT2, m_GUIname);
	DDX_Text(pDX, IDC_EDIT15, m_GUIclass);
	DDX_Text(pDX, IDC_EDIT16, m_GUIseril);
	DDX_Text(pDX, IDC_EDIT17, m_GUIdepartment);
	DDX_Text(pDX, IDC_EDIT18, m_GUImajor);
	DDX_Text(pDX, IDC_EDIT19, m_GUIgpa);
}


BEGIN_MESSAGE_MAP(CStudyModify, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON5, &CStudyModify::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON7, &CStudyModify::OnBnClickedButton7)
END_MESSAGE_MAP()


// CStudyModify ��Ϣ�������


void CStudyModify::OnBnClickedButton5()   //ȷ���޸�
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	CMainFrame*frame = (CMainFrame*)AfxGetMainWnd();
	CManagerSystemDoc*pDoc = (CManagerSystemDoc*)frame->GetActiveDocument();
	Csscholasticin* pSet = (Csscholasticin*)pDoc->GetSscholSet();
	if (AfxMessageBox(TEXT("ȷ���޸�?"), MB_YESNO) == IDYES)
	{
		CString sql;
		sql.Format(TEXT("S_number='%d'"), m_GUInumber);
		pSet->m_strFilter = sql;
		if (pSet->IsOpen()==FALSE)
		{
			pSet->Open();
		}
		pSet->Requery();
		pSet->Edit();
		pSet->m_S_class = m_GUIclass;
		pSet->m_S_serial = m_GUIseril;
		pSet->m_S_department = m_GUIdepartment;
		pSet->m_S_major = m_GUImajor;
		pSet->m_S_gpa = m_GUIgpa;
		pSet->Update();
		sql.Empty();
		pSet->m_strFilter = sql;
		pSet->Close();
		AfxMessageBox("�޸ĳɹ���");
		
		OnOK();
	}

	
}


BOOL CStudyModify::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	CMainFrame*frame = (CMainFrame*)AfxGetMainWnd();
	CManagerSystemDoc* pDoc = (CManagerSystemDoc*)frame->GetActiveDocument();
	m_GUIname = pDoc->stu_name;
	m_GUInumber = pDoc->stu_number;
	m_GUIclass = pDoc->stu_class;
	m_GUIseril = pDoc->stu_seril;
	m_GUIdepartment = pDoc->stu_department;
	m_GUIgpa = pDoc->stu_gpa;
	m_GUImajor = pDoc->stu_major;
	UpdateData(FALSE);
	GetDlgItem(IDC_EDIT1)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT2)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT19)->EnableWindow(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}


void CStudyModify::OnBnClickedButton7()    //ȡ���޸�
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	OnCancel();
}
