// DeleteAdmin.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ManagerSystem.h"
#include "DeleteAdmin.h"
#include "afxdialogex.h"
#include "MainFrm.h"
#include "ManagerSystemDoc.h"


// CDeleteAdmin �Ի���

IMPLEMENT_DYNAMIC(CDeleteAdmin, CDialogEx)

CDeleteAdmin::CDeleteAdmin(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDeleteAdmin::IDD, pParent)
	, m_re_user(_T(""))
{

}

CDeleteAdmin::~CDeleteAdmin()
{
}

void CDeleteAdmin::DeleteCount(Cadmin_login* set, CString username)
{
	CString sql;
	sql.Format(TEXT("Admin_login='%s'"), username);
	if (set->IsOpen()==FALSE)
	{
		set->Open();
	}

	set->m_strFilter = sql;
	set->Requery();
	set->Delete();
	
}

void CDeleteAdmin::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_re_user);
	DDX_Control(pDX, IDC_LIST1, m_reult_list);
}


BEGIN_MESSAGE_MAP(CDeleteAdmin, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CDeleteAdmin::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &CDeleteAdmin::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CDeleteAdmin::OnBnClickedButton4)
END_MESSAGE_MAP()


// CDeleteAdmin ��Ϣ�������


void CDeleteAdmin::OnBnClickedButton1()//��ѯ
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_re_user.Empty();
	m_reult_list.DeleteAllItems();
	CString sql;
	sql.Empty();
	CMainFrame* frame = (CMainFrame*)AfxGetMainWnd();
	CManagerSystemDoc* pDoc = (CManagerSystemDoc*)frame->GetActiveDocument();
	Cadmin_login* pSet=pDoc->GetAdminSet();
	if (pSet->IsOpen()==FALSE)
	{
		pSet->Open();
	}
	UpdateData(TRUE);

	sql.Format(TEXT("Admin_login='%s'"), m_re_user);
	pSet->m_strFilter = sql;
	pSet->Requery();
	if (pSet->GetRecordCount()==0)
	{
		AfxMessageBox("�û�������");
	}
	else
	{
		m_reult_list.InsertItem(0, (CString)pSet->m_Admin_login);
		m_reult_list.SetItemText(0, 1, (CString)pSet->m_Admin_password);
	}
	
}


BOOL CDeleteAdmin::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_reult_list.SetExtendedStyle(m_reult_list.GetExtendedStyle()
		| LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
	int weigth = 162;
	m_reult_list.InsertColumn(0, "�û���",LVCFMT_CENTER,weigth);
	m_reult_list.InsertColumn(1, "����", LVCFMT_CENTER, weigth);

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}


void CDeleteAdmin::OnBnClickedButton3()       //ɾ���˺�
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CMainFrame* frame = (CMainFrame*)AfxGetMainWnd();
	CManagerSystemDoc* pDoc = (CManagerSystemDoc*)frame->GetActiveDocument();
	Cadmin_login* pSet = pDoc->GetAdminSet();
	UpdateData(TRUE);
	CString str=m_reult_list.GetItemText(0,0);
	if (AfxMessageBox(TEXT("ȷ��ɾ����\n�û�����") + str +
		TEXT("\n���룺") + m_reult_list.GetItemText(0, 1),
		MB_YESNO) == IDYES)
	{
		DeleteCount(pSet, m_re_user);
		AfxMessageBox("ɾ���ɹ���");
		m_reult_list.SetItemText(0, 0, "");
		m_reult_list.SetItemText(0, 1, "");
	}
}


void CDeleteAdmin::OnBnClickedButton4()         //ȡ����ť
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	OnCancel();
}
