// Requery.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ManagerSystem.h"
#include "Requery.h"
#include "afxdialogex.h"
#include "MainFrm.h"
#include "ManagerSystemDoc.h"

// CRequery �Ի���

IMPLEMENT_DYNAMIC(CRequery, CDialogEx)

CRequery::CRequery(CWnd* pParent /*=NULL*/)
	: CDialogEx(CRequery::IDD, pParent)
{

}

CRequery::~CRequery()
{
}

void CRequery::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_re_list);
}


BEGIN_MESSAGE_MAP(CRequery, CDialogEx)
END_MESSAGE_MAP()


// CRequery ��Ϣ�������


BOOL CRequery::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
// 	CString head[] = { TEXT("ѧ��"), TEXT("����"), TEXT("�Ա�"), TEXT("��������"), TEXT("����"), TEXT("���֤����"),
// 		TEXT("������ò"), TEXT("��ѧʱ��"), TEXT("��Դ��") };
// 	m_re_list.SetExtendedStyle(m_re_list.GetExtendedStyle()
// 		| LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
// 	m_re_list.InsertColumn(0, head[0], LVCFMT_CENTER, 100);
// 	m_re_list.InsertColumn(1, head[1], LVCFMT_CENTER, 100);
// 	m_re_list.InsertColumn(2, head[2], LVCFMT_CENTER, 100);
// 	m_re_list.InsertColumn(3, head[3], LVCFMT_CENTER, 100);
// 	m_re_list.InsertColumn(4, head[4], LVCFMT_CENTER, 100);
// 	m_re_list.InsertColumn(5, head[5], LVCFMT_CENTER, 130);
// 	m_re_list.InsertColumn(6, head[6], LVCFMT_CENTER, 100);
// 	m_re_list.InsertColumn(7, head[7], LVCFMT_CENTER, 100);
// 	m_re_list.InsertColumn(8, head[8], LVCFMT_CENTER, 100);
// 
// 	CMainFrame* frame = (CMainFrame*)AfxGetMainWnd();
// 	CManagerSystemDoc* pDoc = (CManagerSystemDoc*)frame->GetActiveDocument();
// 	Csbasicinformation* pSet = (Csbasicinformation*)pDoc->GetStudentBasic();
// 	if (pSet->IsOpen()==FALSE)
// 	{
// 		pSet->Open();
// 	}
// 	pSet->Requery();
// 	for (int i = 0; i <pSet->GetRecordCount() ; i++)
// 	{
// 		CString str;
// 		str.Format(TEXT("%d"), pSet->m_S_number);
// 		int j = 1;
// 		m_re_list.InsertItem(i, str);
// 		m_re_list.SetItemText(i, j++, (CString)pSet->m_S_name);
// 		m_re_list.SetItemText(i, j++, (CString)pSet->m_S_sex);
// 
// 		CTime time=pSet->m_S_birthday;
// 		str=time.Format(TEXT("%Y-%m-%d"));
// 		m_re_list.SetItemText(i, j++, str);
// 		m_re_list.SetItemText(i, j++, (CString)pSet->m_S_nation);
// 		m_re_list.SetItemText(i, j++, (CString)pSet->m_S_idnumber);
// 		m_re_list.SetItemText(i, j++, (CString)pSet->m_S_polst);
// 
// 	    time = pSet->m_S_entertime;
// 		str = time.Format(TEXT("%Y-%m-%d"));
// 		m_re_list.SetItemText(i, j++, str);
// 		m_re_list.SetItemText(i, j++, (CString)pSet->m_S_origin);
// 		pSet->MoveNext();
// 	}
// 


	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}
