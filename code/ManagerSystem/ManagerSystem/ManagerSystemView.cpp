
// ManagerSystemView.cpp : CManagerSystemView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "ManagerSystem.h"
#endif
#include "LoginGUI.h"
#include "ManagerSystemDoc.h"
#include "ManagerSystemView.h"
#include "Admin.h"
#include "AddAdmin.h"
#include "DeleteAdmin.h"
#include "AddNormalUser.h"
#include "DeleteNormalGUI.h"
#include "BasicStuAdd.h"
#include "Requery.h"
#include "SBasic.h"
#include "StudentStudy.h"
#include "TeacherAdd.h"
#include "CchangeClass.h"
#include "TeacherManagerClass.h"
#include "NoramlUser.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CManagerSystemView

IMPLEMENT_DYNCREATE(CManagerSystemView, CFormView)

BEGIN_MESSAGE_MAP(CManagerSystemView, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CManagerSystemView::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CManagerSystemView::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON5, &CManagerSystemView::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON8, &CManagerSystemView::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON6, &CManagerSystemView::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CManagerSystemView::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON23, &CManagerSystemView::OnBnClickedButton23)
	ON_BN_CLICKED(IDC_BUTTON25, &CManagerSystemView::OnBnClickedButton25)
	ON_BN_CLICKED(IDC_BUTTON3, &CManagerSystemView::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CManagerSystemView::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON30, &CManagerSystemView::OnBnClickedButton30)
END_MESSAGE_MAP()

// CManagerSystemView ����/����

CManagerSystemView::CManagerSystemView()
	: CFormView(CManagerSystemView::IDD)
{
	// TODO:  �ڴ˴���ӹ������

}

CManagerSystemView::~CManagerSystemView()
{
}

void CManagerSystemView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_MainFormChange);
}

BOOL CManagerSystemView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CFormView::PreCreateWindow(cs);
}

void CManagerSystemView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	CManagerSystemDoc*pDoc = GetDocument();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();
	//������¼�Ի���
	CLoginGUI gui;
	gui.DoModal();
	m_MainFormChange.SetCurSel(0);

	if (pDoc->login_num==1)
	{
		GetDlgItem(IDC_BUTTON1)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON2)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON6)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON7)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON8)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON23)->EnableWindow(FALSE);
		GetDlgItem(IDC_COMBO1)->EnableWindow(FALSE);

	}
	else if (pDoc->login_num==2)
	{
		GetDlgItem(IDC_BUTTON1)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON2)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON6)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON7)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON8)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON25)->EnableWindow(FALSE);
		GetDlgItem(IDC_COMBO1)->EnableWindow(FALSE);
	}
	else
	{
		GetDlgItem(IDC_BUTTON23)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON25)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON3)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON4)->EnableWindow(FALSE);
	}
	
}


// CManagerSystemView ���

#ifdef _DEBUG
void CManagerSystemView::AssertValid() const
{
	CFormView::AssertValid();
}

void CManagerSystemView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CManagerSystemDoc* CManagerSystemView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CManagerSystemDoc)));
	return (CManagerSystemDoc*)m_pDocument;
}
#endif //_DEBUG


// CManagerSystemView ��Ϣ�������


void CManagerSystemView::OnBnClickedButton1() //����˺Ű�ť
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	int index = m_MainFormChange.GetCurSel();
	if (index==0)
	{
		AddAdmin add;
		add.DoModal();
	}
	else
	{
		CAddNormalUser user;
		user.DoModal();
	}

	
}


void CManagerSystemView::OnBnClickedButton2() //ɾ���˺Ű�ť
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	int index = m_MainFormChange.GetCurSel();
	if (index==0)
	{
		CDeleteAdmin deladmin;
		deladmin.DoModal();
	}
	else
	{
		CDeleteNormalGUI gui;
		gui.DoModal();
	}
	

}


void CManagerSystemView::OnBnClickedButton5()    //ѧ��������Ϣ���
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	CBasicStuAdd basic;
	basic.DoModal();

}


void CManagerSystemView::OnBnClickedButton8()    //��ʦ��Ϣ����ϵͳ
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CTeacherAdd teacher;
	teacher.DoModal();

}


void CManagerSystemView::OnBnClickedButton6()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CSBasic basic;
	basic.DoModal();
}


void CManagerSystemView::OnBnClickedButton7()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//ѧ����Ϣ����ϵͳ
	CStudentStudy study;
	study.DoModal();

}


void CManagerSystemView::OnBnClickedButton23()  
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//////////////////////////////////////////////////////////////////////////
	//ѧ��ѡ��
	CchangeClass Dlg;
	Dlg.DoModal();
}


void CManagerSystemView::OnBnClickedButton25()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//////////////////////////////////////////////////////////////////////////
	//��ʦ��Ϣ����
	CTeacherManagerClass Dlg;
	Dlg.DoModal();

}


void CManagerSystemView::OnBnClickedButton3()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CManagerSystemDoc* pDoc = (CManagerSystemDoc*)GetDocument();
	Cteacher_login* pSet = (Cteacher_login*)pDoc->GetTeacherSet();
	Cstudent_login* pset = (Cstudent_login*)pDoc->GetStudentSet();
	CString str;
	if (pDoc->teacher_user > 0)
	{
		str.Format(TEXT("%d"), pDoc->teacher_user);
	}
	else{
		str.Format(TEXT("%d"), pDoc->student_user);
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
		if (AfxMessageBox(TEXT("�û�����") + str + TEXT("\n���룺") + (CString)pSet->m_T_password, MB_YESNO) == IDYES)
		{
			return;
		}
	}
	else
	{
		CString sql;
		sql.Format(TEXT("S_number='%d'"), pDoc->student_user);
		pset->m_strFilter = sql;
		pset->Requery();
		if (AfxMessageBox(TEXT("�û�����") + str + TEXT("\n���룺") + (CString)pset->m_S_password, MB_YESNO) == IDYES)
		{
			return;
		}
	}
	pSet->m_strFilter = "";
	pset->m_strFilter = "";
	pSet->Requery();
	pset->Requery();
	pSet->Close();
	pset->Close();
}


void CManagerSystemView::OnBnClickedButton4()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CNoramlUser dlg;
	dlg.DoModal();
}


void CManagerSystemView::OnBnClickedButton30()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	exit(0);
}
