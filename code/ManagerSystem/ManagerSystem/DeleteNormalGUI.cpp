// DeleteNormalGUI.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ManagerSystem.h"
#include "DeleteNormalGUI.h"
#include "afxdialogex.h"
#include "NormalUser.h"
#include "MainFrm.h"
#include "ManagerSystemDoc.h"
#include "ManagerSystemView.h"


// CDeleteNormalGUI �Ի���

IMPLEMENT_DYNAMIC(CDeleteNormalGUI, CDialogEx)

CDeleteNormalGUI::CDeleteNormalGUI(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDeleteNormalGUI::IDD, pParent)
	, m_username(0)
{

}

CDeleteNormalGUI::~CDeleteNormalGUI()
{
}

void CDeleteNormalGUI::ReQueryGUI(int type)
{
	CMainFrame* frame = (CMainFrame*)AfxGetMainWnd();
	CManagerSystemDoc* pDoc = (CManagerSystemDoc*)frame->GetActiveDocument();
	CManagerSystemView* pView = (CManagerSystemView*)frame->GetActiveView();
	Cstudent_login* pstuset = pDoc->GetStudentSet();
	Cteacher_login* pteachset = pDoc->GetTeacherSet();
	CString sql;
	if (type == 1)
	{
		sql.Format(TEXT("T_number='%d'"), m_username);
		if (pteachset->IsOpen() == FALSE)
		{
			pteachset->Open();
		}
		pteachset->m_strFilter = sql;
		pteachset->Requery();
		if (pteachset->GetRecordCount() == 0)
		{
			AfxMessageBox("�޴��û���");
		}
		else
		{
			CString str;
			str.Format(TEXT("%d"), pteachset->m_T_number);
			m_listctrl.InsertItem(0, str);
			m_listctrl.SetItemText(0, 1, (CString)pteachset->m_T_password);
		}
	}
	//ѧ����ѯ
	if (type == 2)
	{
		sql.Format(TEXT("S_number='%d'"), m_username);
		if (pstuset->IsOpen() == FALSE)
		{
			pstuset->Open();
		}
		pstuset->m_strFilter = sql;
		pstuset->Requery();
		if (pstuset->GetRecordCount() == 0)
		{
			AfxMessageBox("�޴��û���");
		}
		else
		{
			CString str;
			str.Format(TEXT("%d"), pstuset->m_S_number);
			m_listctrl.InsertItem(0, str);
			m_listctrl.SetItemText(0, 1, (CString)pstuset->m_S_password);
		}
	}
	pstuset->m_strFilter = "";
	pstuset->Requery();
	pstuset->Close();

	pteachset->m_strFilter = "";
	pteachset->Requery();
	pteachset->Close();
}

void CDeleteNormalGUI::DeleteNormal(int type)
{
	CMainFrame* frame = (CMainFrame*)AfxGetMainWnd();
	CManagerSystemDoc* pDoc = (CManagerSystemDoc*)frame->GetActiveDocument();
	CManagerSystemView*pView = (CManagerSystemView*)frame->GetActiveView();
	Cstudent_login* pstuset = (Cstudent_login*)pDoc->GetStudentSet();
	Cteacher_login* pteachset = (Cteacher_login*)pDoc->GetTeacherSet();
	UpdateData(TRUE);
	CNormalUser user;
	CString str = m_listctrl.GetItemText(0, 0);
	if (type == 1)
	{
		if (AfxMessageBox(TEXT("ȷ��ɾ����\n�û�����") + str +
			TEXT("\n���룺") + m_listctrl.GetItemText(0, 1),
			MB_YESNO) == IDYES)
		{
			user.DeleteNormalUser(pteachset, m_username);
			AfxMessageBox("ɾ���ɹ���");
			m_listctrl.SetItemText(0, 0, "");
			m_listctrl.SetItemText(0, 1, "");
			return;
		}
	}
	if (type == 2)
	{
		if (AfxMessageBox(TEXT("ȷ��ɾ����\n�û�����") + str +
			TEXT("\n���룺") + m_listctrl.GetItemText(0, 1),
			MB_YESNO) == IDYES)
		{
			user.DeleteNormalUser(pstuset, m_username);
			AfxMessageBox("ɾ���ɹ���");
			m_listctrl.SetItemText(0, 0, "");
			m_listctrl.SetItemText(0, 1, "");
			return;
		}
	}


}

void CDeleteNormalGUI::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_username);
	DDX_Control(pDX, IDC_LIST1, m_listctrl);
}


BEGIN_MESSAGE_MAP(CDeleteNormalGUI, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CDeleteNormalGUI::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &CDeleteNormalGUI::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CDeleteNormalGUI::OnBnClickedButton4)
END_MESSAGE_MAP()


// CDeleteNormalGUI ��Ϣ�������


void CDeleteNormalGUI::OnBnClickedButton1()        //��ͨ�û���ѯ
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_listctrl.DeleteAllItems();
	m_username = 0;
	CMainFrame* frame = (CMainFrame*)AfxGetMainWnd();
	CManagerSystemDoc* pDoc = (CManagerSystemDoc*)frame->GetActiveDocument();
	CManagerSystemView* pView = (CManagerSystemView*)frame->GetActiveView();
	UpdateData(TRUE);
	int index = pView->m_MainFormChange.GetCurSel();
	ReQueryGUI(index);
}


BOOL CDeleteNormalGUI::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_listctrl.SetExtendedStyle(m_listctrl.GetExtendedStyle()
		| LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
	int weigth = 159;
	m_listctrl.InsertColumn(0, "�û���", LVCFMT_CENTER, weigth);
	m_listctrl .InsertColumn(1, "����", LVCFMT_CENTER, weigth);
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}


void CDeleteNormalGUI::OnBnClickedButton3()   //��ͨ�û�ɾ��
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CMainFrame* frame = (CMainFrame*)AfxGetMainWnd();
	CManagerSystemDoc* pDoc = (CManagerSystemDoc*)frame->GetActiveDocument();
	CManagerSystemView*pView = (CManagerSystemView*)frame->GetActiveView();
	Cstudent_login* pstuset = (Cstudent_login*)pDoc->GetStudentSet();
	Cteacher_login* pteachset = (Cteacher_login*)pDoc->GetTeacherSet();
	int index = pView->m_MainFormChange.GetCurSel();
	UpdateData(TRUE);
	DeleteNormal(index);
}


void CDeleteNormalGUI::OnBnClickedButton4()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	OnCancel();
}
