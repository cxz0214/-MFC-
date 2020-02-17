// SBasic.cpp : 实现文件
//

#include "stdafx.h"
#include "ManagerSystem.h"
#include "SBasic.h"
#include "afxdialogex.h"
#include "MainFrm.h"
#include "ManagerSystemDoc.h"
#include "sbasicinformation.h"
#include "BasicStuAdd.h"
#include "EidtStudent.h"
#include <string>
#include<sstream>
#include<vector>
#include "StudentBasic.h"
using namespace std;
// CSBasic 对话框

IMPLEMENT_DYNAMIC(CSBasic, CDialogEx)

CSBasic::CSBasic(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSBasic::IDD, pParent)
	, m_sname(_T(""))
	, m_snumber(0)
{

}

CSBasic::~CSBasic()
{
}

void CSBasic::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_SBGUI_list);
	DDX_Control(pDX, IDC_COMBO1, m_combox);
	DDX_Text(pDX, IDC_EDIT1, m_sname);
	DDX_Text(pDX, IDC_EDIT2, m_snumber);
}


BEGIN_MESSAGE_MAP(CSBasic, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CSBasic::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON9, &CSBasic::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON3, &CSBasic::OnBnClickedButton3)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, &CSBasic::OnNMClickList1)
	ON_BN_CLICKED(IDC_BUTTON5, &CSBasic::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CSBasic::OnBnClickedButton6)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CSBasic::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_BUTTON4, &CSBasic::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON17, &CSBasic::OnBnClickedButton17)
	ON_BN_CLICKED(IDC_BUTTON8, &CSBasic::OnBnClickedButton8)
END_MESSAGE_MAP()


// CSBasic 消息处理程序


BOOL CSBasic::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_SBGUI_list.DeleteColumn(NULL);
	m_SBGUI_list.DeleteAllItems();
	CString head[] = { TEXT("学号"), TEXT("姓名"), TEXT("性别"), TEXT("出生年月"), TEXT("民族"), TEXT("身份证号码"),
		TEXT("政治面貌"), TEXT("入学时间"), TEXT("生源地") };
	m_SBGUI_list.SetExtendedStyle(m_SBGUI_list.GetExtendedStyle()
		| LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
	m_SBGUI_list.InsertColumn(0, head[0], LVCFMT_CENTER, 100);
	m_SBGUI_list.InsertColumn(1, head[1], LVCFMT_CENTER, 100);
	m_SBGUI_list.InsertColumn(2, head[2], LVCFMT_CENTER, 100);
	m_SBGUI_list.InsertColumn(3, head[3], LVCFMT_CENTER, 100);
	m_SBGUI_list.InsertColumn(4, head[4], LVCFMT_CENTER, 100);
	m_SBGUI_list.InsertColumn(5, head[5], LVCFMT_CENTER, 150);
	m_SBGUI_list.InsertColumn(6, head[6], LVCFMT_CENTER, 100);
	m_SBGUI_list.InsertColumn(7, head[7], LVCFMT_CENTER, 100);
	m_SBGUI_list.InsertColumn(8, head[8], LVCFMT_CENTER, 100);
	m_combox.SetCurSel(0);
	GetDlgItem(IDC_EDIT2)->EnableWindow(FALSE);
	CMainFrame* frame = (CMainFrame*)AfxGetMainWnd();
	CManagerSystemDoc* pDoc = (CManagerSystemDoc*)frame->GetActiveDocument();
	Csbasicinformation* pSet = (Csbasicinformation*)pDoc->GetStudentBasic();
	if (pSet->IsOpen() == FALSE)
	{
		pSet->Open();
	}
	pSet->Requery();
	for (int i = 0; i < pSet->GetRecordCount(); i++)
	{
		CString str;
		str.Format(TEXT("%d"), pSet->m_S_number);
		int j = 1;
		m_SBGUI_list.InsertItem(i, str);
		m_SBGUI_list.SetItemText(i, j++, (CString)pSet->m_S_name);
		m_SBGUI_list.SetItemText(i, j++, (CString)pSet->m_S_sex);

		CTime time = pSet->m_S_birthday;
		str = time.Format(TEXT("%Y-%m-%d"));
		m_SBGUI_list.SetItemText(i, j++, str);
		m_SBGUI_list.SetItemText(i, j++, (CString)pSet->m_S_nation);
		m_SBGUI_list.SetItemText(i, j++, (CString)pSet->m_S_idnumber);
		m_SBGUI_list.SetItemText(i, j++, (CString)pSet->m_S_polst);

		time = pSet->m_S_entertime;
		str = time.Format(TEXT("%Y-%m-%d"));
		m_SBGUI_list.SetItemText(i, j++, str);
		m_SBGUI_list.SetItemText(i, j++, (CString)pSet->m_S_origin);
		pSet->MoveNext();
	}
	pSet->m_strFilter = "";
	pSet->Requery();
	pSet->Close();
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}


void CSBasic::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码
	CBasicStuAdd basic;
	basic.DoModal();
}


void CSBasic::OnBnClickedButton9()
{
	// TODO:  在此添加控件通知处理程序代码
	OnCancel();
}


void CSBasic::OnBnClickedButton3()           //学生信息修改
{
	// TODO:  在此添加控件通知处理程序代码
	CMainFrame* frame = (CMainFrame*)AfxGetMainWnd();
	CManagerSystemDoc* pDoc = (CManagerSystemDoc*)frame->GetActiveDocument();
	CListCtrl* pListCtrl = (CListCtrl*)GetDlgItem(IDC_LIST1);
	int i = pDoc->column;
	CString str;
	str = pListCtrl->GetItemText(i, 0);
	pDoc->number_s = _ttoi(str);
	str = pListCtrl->GetItemText(i, 1);
	pDoc->name_s = str;
	str = pListCtrl->GetItemText(i, 2);
	pDoc->sex_s = str;
	str = pListCtrl->GetItemText(i, 3);
	pDoc->bir_year_s = _ttoi(str.Left(4));
	pDoc->bir_month_s = _ttoi(str.Mid(5, 2));
	pDoc->bir_day_s = _ttoi(str.Right(2));
	str = pListCtrl->GetItemText(i, 4);
	pDoc->nation_s = str;
	str = pListCtrl->GetItemText(i, 5);
	pDoc->ID_s = str;
	str = pListCtrl->GetItemText(i, 6);
	pDoc->plostic_s = str;
	str = pListCtrl->GetItemText(i, 7);
	pDoc->enter_year_s = _ttoi(str.Left(4));
	pDoc->enter_month_s= _ttoi(str.Mid(5, 2));
	pDoc->enter_day_s = _ttoi(str.Right(2));
	str = pListCtrl->GetItemText(i, 8);
	pDoc->place_s = str;
	CEidtStudent stu;
	stu.DoModal();

}


void CSBasic::OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO:  在此添加控件通知处理程序代码
	*pResult = 0;
	NM_LISTVIEW* plist = (NM_LISTVIEW*)pNMHDR;
	CMainFrame*frame = (CMainFrame*)AfxGetMainWnd();
	CManagerSystemDoc* pDoc = (CManagerSystemDoc*)frame->GetActiveDocument();
	pDoc->column = plist->iItem;
	
}
void CSBasic::OnBnClickedButton5()            //学生信息删除
{
	// TODO:  在此添加控件通知处理程序代码
	CMainFrame* frame = (CMainFrame*)AfxGetMainWnd();
	CManagerSystemDoc* pDoc = (CManagerSystemDoc*)frame->GetActiveDocument();
	CListCtrl* pListCtrl = (CListCtrl*)GetDlgItem(IDC_LIST1);
	Csbasicinformation* pSet = (Csbasicinformation*)pDoc->GetStudentBasic();
	int i = pDoc->column;
	CString str1,str2,str3,str4,str5,str6,str7,str8,str9;
	str1 = pListCtrl->GetItemText(i, 0);
	
	str2 = pListCtrl->GetItemText(i, 1);
	
	str3 = pListCtrl->GetItemText(i, 2);
	
	str4 = pListCtrl->GetItemText(i, 3);

	str5 = pListCtrl->GetItemText(i, 4);
	
	str6 = pListCtrl->GetItemText(i, 5);

	str7 = pListCtrl->GetItemText(i, 6);
	
	str8 = pListCtrl->GetItemText(i, 7);
	
	str9 = pListCtrl->GetItemText(i, 8);

	if (AfxMessageBox(TEXT("\n学号: ") + str1 + TEXT("\n用户名: ") + str2 + TEXT("\n性别: ") + str3 + TEXT("\n出生年月：") + str4
		+ TEXT("\n民族：") + str5 + TEXT("\n身份证号码：") + str6 + TEXT("\n政治面貌: ") + str7 + TEXT("\n入学时间: ") + str8
		+ TEXT("\n生源地：") + str9, MB_YESNO) == IDYES)
	{
		pDoc->DeleteStudentBasic(_ttoi(str1));
		AfxMessageBox("删除成功！");
		
	}

}


void CSBasic::OnBnClickedButton6()
{
	// TODO:  在此添加控件通知处理程序代码
	m_SBGUI_list.DeleteAllItems();
	CMainFrame* frame = (CMainFrame*)AfxGetMainWnd();
	CManagerSystemDoc* pDoc = (CManagerSystemDoc*)frame->GetActiveDocument();
	Csbasicinformation* pSet = (Csbasicinformation*)pDoc->GetStudentBasic();
	if (pSet->IsOpen() == FALSE)
	{
		pSet->Open();
	}
	pSet->Requery();
	for (int i = 0; i < pSet->GetRecordCount(); i++)
	{
		CString str;
		str.Format(TEXT("%d"), pSet->m_S_number); 
		int j = 1;
		m_SBGUI_list.InsertItem(i, str);
		m_SBGUI_list.SetItemText(i, j++, (CString)pSet->m_S_name);
		m_SBGUI_list.SetItemText(i, j++, (CString)pSet->m_S_sex);

		CTime time = pSet->m_S_birthday;
		str = time.Format(TEXT("%Y-%m-%d"));
		m_SBGUI_list.SetItemText(i, j++, str);
		m_SBGUI_list.SetItemText(i, j++, (CString)pSet->m_S_nation);
		m_SBGUI_list.SetItemText(i, j++, (CString)pSet->m_S_idnumber);
		m_SBGUI_list.SetItemText(i, j++, (CString)pSet->m_S_polst);

		time = pSet->m_S_entertime;
		str = time.Format(TEXT("%Y-%m-%d"));
		m_SBGUI_list.SetItemText(i, j++, str);
		m_SBGUI_list.SetItemText(i, j++, (CString)pSet->m_S_origin);
		pSet->MoveNext();
	}

}


void CSBasic::OnCbnSelchangeCombo1()
{
	// TODO:  在此添加控件通知处理程序代码
	int index = m_combox.GetCurSel();
	CString str;
	m_combox.GetLBText(index, str);
	if (str==TEXT("按姓名查询"))
	{
		m_snumber = 0;
		GetDlgItem(IDC_EDIT1)->EnableWindow(TRUE);
		GetDlgItem(IDC_EDIT2)->EnableWindow(FALSE);
	}
	if (str==TEXT("按学号查询"))
	{
		m_sname.Empty();
		GetDlgItem(IDC_EDIT1)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT2)->EnableWindow(TRUE);
	}
	UpdateData(FALSE);
}


void CSBasic::OnBnClickedButton4()      //查询
{
	// TODO:  在此添加控件通知处理程序代码
	m_sname.Empty();
	UpdateData(TRUE);
	CMainFrame* frame = (CMainFrame*)AfxGetMainWnd();
	CManagerSystemDoc* pDoc = (CManagerSystemDoc*)frame->GetActiveDocument();
	//////////////////////////////////////////////////////////////////////////
	Csbasicinformation* pSet = (Csbasicinformation*)pDoc->GetStudentBasic();

	m_SBGUI_list.DeleteAllItems();
	if (pSet->IsOpen() == FALSE)
	{
		pSet->Open();
	}
	int index = m_combox.GetCurSel();
	if (index == 0)   //按姓名查询
	{
		CString sql;
		sql.Format(TEXT("S_name LIKE'%%%s%%'"), m_sname);
		pSet->m_strFilter = sql;
		pSet->m_strSort = "S_number";
		pSet->Requery();
		int n = pSet->GetRecordCount();
		
		if (n==0)
		{
			AfxMessageBox("该用户不存在！请确定后重新输入！");
			sql.Empty();
			pSet->m_strFilter = sql;
			pSet->Requery();
			return;
		}
		int i = 0;
		while (pSet->IsEOF()==FALSE)
		{
			
			CString str;
			str.Format(TEXT("%d"), pSet->m_S_number);
			int j = 1;
			m_SBGUI_list.InsertItem(i, str);
			m_SBGUI_list.SetItemText(i, j++, (CString)pSet->m_S_name);
			m_SBGUI_list.SetItemText(i, j++, (CString)pSet->m_S_sex);
			CTime time = pSet->m_S_birthday;
			str = time.Format(TEXT("%Y-%m-%d"));
			m_SBGUI_list.SetItemText(i, j++, str);
			m_SBGUI_list.SetItemText(i, j++, (CString)pSet->m_S_nation);
			m_SBGUI_list.SetItemText(i, j++, (CString)pSet->m_S_idnumber);
			m_SBGUI_list.SetItemText(i, j++, (CString)pSet->m_S_polst);
			time = pSet->m_S_entertime;
			str = time.Format(TEXT("%Y-%m-%d"));
			m_SBGUI_list.SetItemText(i, j++, str);
			m_SBGUI_list.SetItemText(i, j++, (CString)pSet->m_S_origin);
			pSet->MoveNext();
			i++;

		}
		sql.Empty();
		pSet->m_strFilter = sql;
		pSet->Requery();
		pSet->Close();
		
	}
	if (index == 1)  //按学号查询
	{
		CString sql;
		sql.Format(TEXT("S_number='%d'"), m_snumber);
		pSet->m_strFilter = sql;
		pSet->Requery();
		int n = pSet->GetRecordCount();
		if (n == 0)
		{
			AfxMessageBox("该用户不存在！请确定后重新输入！");
			sql.Empty();
			pSet->m_strFilter = sql;
			pSet->Requery();
			return;
		}
		for (int i = 0; i < n; i++)
		{
			CString str;
			str.Format(TEXT("%d"), pSet->m_S_number);
			int j = 1;
			m_SBGUI_list.InsertItem(i, str);
			m_SBGUI_list.SetItemText(i, j++, (CString)pSet->m_S_name);
			m_SBGUI_list.SetItemText(i, j++, (CString)pSet->m_S_sex);

			CTime time = pSet->m_S_birthday;
			str = time.Format(TEXT("%Y-%m-%d"));
			m_SBGUI_list.SetItemText(i, j++, str);
			m_SBGUI_list.SetItemText(i, j++, (CString)pSet->m_S_nation);
			m_SBGUI_list.SetItemText(i, j++, (CString)pSet->m_S_idnumber);
			m_SBGUI_list.SetItemText(i, j++, (CString)pSet->m_S_polst);

			time = pSet->m_S_entertime;
			str = time.Format(TEXT("%Y-%m-%d"));
			m_SBGUI_list.SetItemText(i, j++, str);
			m_SBGUI_list.SetItemText(i, j++, (CString)pSet->m_S_origin);
			pSet->MoveNext();
		}
		sql.Empty();
		pSet->m_strFilter = sql;
		pSet->Requery();
		pSet->Close();
	}
}


void CSBasic::OnBnClickedButton17()// 导入数据
{
	// TODO:  在此添加控件通知处理程序代码
	CMainFrame* pMainFrame = (CMainFrame*)AfxGetMainWnd();
	CManagerSystemDoc* pDoc = (CManagerSystemDoc*)pMainFrame->GetActiveDocument();
	Csbasicinformation*pSet = (Csbasicinformation*)pDoc->GetStudentBasic();
	using namespace std;
	char szFilters[] = _T("txt文件(*.txt) | *.txt | xls文件(*.xls) | *.xls | 所有文件(*.*)|*.*||");
	CFileDialog dlg(FALSE, _T("txt"), _T("学生信息"), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, szFilters, this);

	dlg.m_ofn.lpstrTitle = TEXT("导入文件");

	if (dlg.DoModal() != IDOK)
	{
		return;
	}
	CString strFilePath;
	strFilePath = dlg.GetPathName();

	DWORD dwRe = GetFileAttributes(strFilePath);
	if (dwRe != (DWORD)-1)
	{
		m_SBGUI_list.DeleteAllItems();
		int nColumnCount = m_SBGUI_list.GetHeaderCtrl()->GetItemCount();
		for (int i = 0; i < nColumnCount; i++)
		{
			m_SBGUI_list.DeleteColumn(0);
		}
	}
	else
	{
		AfxMessageBox("文件不存在");
		return;
	}
	//读取文件数据
	FILE *fp;
	fopen_s(&fp, strFilePath, "r");
	char str[1024];
	if (fp == NULL)
	{
		printf("open file error\n");
		return;
	}
	int iRow = 0;
	int nlength = 0;
	while (fgets(str, sizeof(str), fp))
	{
		char _index[256];
		//sprintf_s(_index, "%d", iRow);
		m_SBGUI_list.InsertItem(iRow, _index);

		std::string s = str;
		std::string buf;
		std::stringstream ss(s);
		std::vector<std::string> tokens;

		int i = 0;
		while (ss >> buf)
		{
			if (buf.size() > 0)
			{
				tokens.push_back(buf);
				if (iRow == 0)
				{
					m_SBGUI_list.InsertColumn(i, TEXT(tokens.at(i).c_str()), LVCFMT_CENTER, 105);
				}
				else
				{
					m_SBGUI_list.SetItemText(iRow, i, tokens.at(i).c_str());
				}
				i++;
			}
		}
		iRow++;
	}
	m_SBGUI_list.DeleteItem(0);
	fclose(fp);
	for (int m = 0; m < m_SBGUI_list.GetItemCount(); m++)
	{
		int l = 0;
		CStudentBasic stu;
		stu.SetBasicSet(pSet);
		CString str1 = m_SBGUI_list.GetItemText(m, l + 3);
		CString str2 = m_SBGUI_list.GetItemText(m, l + 7);
		CTime birthday(_ttoi(str1.Left(4)), _ttoi(str1.Mid(5,2)),_ttoi(str1.Right(2)), 0, 0, 0);
		CTime enterTime(_ttoi(str2.Left(4)), _ttoi(str2.Mid(5, 2)), _ttoi(str2.Right(2)), 0, 0, 0);
		stu.SetStudentBasic(_ttoi(m_SBGUI_list.GetItemText(m, l)), m_SBGUI_list.GetItemText(m, l + 1), m_SBGUI_list.GetItemText(m, l + 2), birthday, m_SBGUI_list.GetItemText(m, l + 4), 
			m_SBGUI_list.GetItemText(m, l + 5), m_SBGUI_list.GetItemText(m, l + 6), enterTime, m_SBGUI_list.GetItemText(m, l + 8));
		stu.AddStudentBasic();
	}
	//pSet->MoveNext();
}


void CSBasic::OnBnClickedButton8()   //导出数据
{
	// TODO:  在此添加控件通知处理程序代码
	if (m_SBGUI_list.GetItemCount() <= 0)
	{
		AfxMessageBox(TEXT("列表中无记录可以保存！"));
		return;
	}
	//打开另存为对话框，需要包含#include<Afxdlgs.h>
	char szFilters[] = _T("txt文件(*.txt) | *.txt | xls文件(*.xls) | *.xls | 所有文件(*.*)|*.*||");
	CFileDialog dlg(FALSE, _T("txt"), _T("学生信息"), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, szFilters, this);
	if (dlg.DoModal() != IDOK)
		return;
	CString strFilePath;
	strFilePath = dlg.GetPathName();
	DWORD dwRe = GetFileAttributes(strFilePath);
	if (dwRe != (DWORD)-1)
	{
		DeleteFile(strFilePath);
	}
	FILE* fp;
	fopen_s(&fp, strFilePath, "w");
	char str[1024];
	if (fp == NULL)
	{
		printf("save file error\n");
		return;
	}
	int nHeadNum = m_SBGUI_list.GetHeaderCtrl()->GetItemCount();
	LVCOLUMN lvcol;
	char str_out[256];
	int nColNum;
	nColNum = 0;
	lvcol.mask = LVCF_TEXT;
	lvcol.pszText = str_out;
	lvcol.cchTextMax = 256;
	while (m_SBGUI_list.GetColumn(nColNum, &lvcol))
	{
		nColNum++;
		fprintf_s(fp, "%s\t", lvcol.pszText);
	}
	fprintf_s(fp, "\n", lvcol.pszText);


	int nRow = m_SBGUI_list.GetItemCount();
	for (int i = 0; i < nRow; i++)
	{
		for (int j = 0; j < nColNum; j++)
		{
			CString str_data = this->m_SBGUI_list.GetItemText(i, j);
			fprintf_s(fp, "%s\t", str_data);
		}
		fprintf_s(fp, "\n");
	}
	fclose(fp);
	AfxMessageBox(TEXT("保存成功！"));
}
