// TeacherADDGUI.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ManagerSystem.h"
#include "TeacherADDGUI.h"
#include "afxdialogex.h"
#include "MainFrm.h"
#include "ManagerSystemDoc.h"
#include "teacherinfo.h"
#include "TeacherInformation.h"

// CTeacherADDGUI �Ի���

IMPLEMENT_DYNAMIC(CTeacherADDGUI, CDialogEx)

CTeacherADDGUI::CTeacherADDGUI(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTeacherADDGUI::IDD, pParent)
	, m_GUInumber(0)
	, m_GUIname(_T(""))
	, m_GUIsex(_T(""))
	, m_GUIdepart(_T(""))
{

}

CTeacherADDGUI::~CTeacherADDGUI()
{
}

void CTeacherADDGUI::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_GUInumber);
	DDX_Text(pDX, IDC_EDIT2, m_GUIname);
	DDX_Text(pDX, IDC_EDIT15, m_GUIsex);
	DDX_Text(pDX, IDC_EDIT16, m_GUIdepart);
}


BEGIN_MESSAGE_MAP(CTeacherADDGUI, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON3, &CTeacherADDGUI::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CTeacherADDGUI::OnBnClickedButton4)
END_MESSAGE_MAP()


// CTeacherADDGUI ��Ϣ�������


void CTeacherADDGUI::OnBnClickedButton3()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	CMainFrame* frame = (CMainFrame*)AfxGetMainWnd();
	CManagerSystemDoc*pDoc = (CManagerSystemDoc*)frame->GetActiveDocument();
	Cteacherinfo* pSet = (Cteacherinfo*)pDoc->GetTeacherInforSet();
	TeacherInformation teacher;
	teacher.SetTeacherSet(pSet);
	teacher.SetTeacherObJ(m_GUInumber, m_GUIname, m_GUIsex, m_GUIdepart);
	teacher.AddTeacherObj();
	AfxMessageBox("��ӳɹ���");
	OnOK();

}


void CTeacherADDGUI::OnBnClickedButton4()     //ȡ�����
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	OnCancel();
}
