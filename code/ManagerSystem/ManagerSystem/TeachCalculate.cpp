// TeachCalculate.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ManagerSystem.h"
#include "TeachCalculate.h"
#include "afxdialogex.h"
#include "ManagerSystemDoc.h"
#include "MainFrm.h"

// CTeachCalculate �Ի���

IMPLEMENT_DYNAMIC(CTeachCalculate, CDialogEx)

CTeachCalculate::CTeachCalculate(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTeachCalculate::IDD, pParent)
{

}

CTeachCalculate::~CTeachCalculate()
{
}

void CTeachCalculate::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CTeachCalculate, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CTeachCalculate ��Ϣ�������


void CTeachCalculate::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO:  �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()
	CMainFrame* frame = (CMainFrame*)AfxGetMainWnd();
	CManagerSystemDoc* pDoc = (CManagerSystemDoc*)frame->GetActiveDocument();
	LOGFONT log;
	CFont font;
	log.lfHeight = 0;
	log.lfEscapement = 0;
	log.lfItalic = 0;
	log.lfUnderline = 0;
	log.lfStrikeOut = 0;

	wsprintf(log.lfFaceName, TEXT("%s"), TEXT("����"));

	font.CreateFontIndirect(&log);
	//����
	CPen pen(PS_SOLID, 1, RGB(0, 0, 0));
	dc.SelectObject(&pen);

	//�߼�����
	SetViewportOrgEx(dc, 35, 480, NULL);
	dc.SetMapMode(MM_LOMETRIC);//0.1����

	//������
	dc.MoveTo(0, 0);
	dc.LineTo(0, 650);//��1000
	dc.LineTo(-10, 630);
	dc.MoveTo(0, 650);
	dc.LineTo(10, 630);
	//������ѭ��
	CString str;
	//int i;
	for (int i = 0; i < 13; i++)
	{
		dc.MoveTo(0, i * 50);
		dc.LineTo(10, i * 50);
		CString str1;
		str1.Format(TEXT("%d"), i * 1);
		dc.TextOut(-40, i * 50 + 20, str1);
	}
	//������
	dc.MoveTo(0, 0);
	dc.LineTo(650, 0);
	dc.LineTo(630, 10);
	dc.MoveTo(650, 0);
	dc.LineTo(630, -10);
	for (int i = 1; i < 11; i++)
	{
		dc.MoveTo(i * 60, 0);
		dc.LineTo(i * 60, 10);
		CString str2;
		str2.Format(TEXT("%d"), i * 10);
		dc.TextOut(i * 60 - 20, -20, str2);
	}
	//////////////////////////////////////////////////////////////////////////
	CPen pen2(PS_SOLID, 1, RGB(0, 0, 0));
	dc.SelectObject(&pen2);
	for (int i = 0; i < 10;i++)
	{
		CRect r1(i * 60, pDoc->grade[i] * 50, (i + 1) * 60, 0);
		CBrush br1(RGB((20+i*50)%255, (23+i*50)%255, (23+i*25)%255));
		dc.FillRect(r1, &br1);
	}
	//////////////////////////////////////////////////////////////////////////
	dc.TextOut(700,550, TEXT("ȫ��ѧ��ƽ���ֵ�ͳ�ƣ�"));
	CRect r2(700,500,1000,450);
	CBrush br2(RGB(255, 255, 255));
	dc.FillRect(r2, &br2);
	CRect r3(700, 500, 700+300*(pDoc->average/100), 450);
	CBrush br3(RGB(255, 2, 25));
	dc.FillRect(r3, &br3);
	//////////////////////////////////////////////////////////////////////////
	dc.TextOut(700, 150, TEXT("ȫ��ѧ�������ʵ�ͳ�ƣ�"));
	CRect r5(700, 100, 1000, 50);
	CBrush br5(RGB(255, 255, 255));
	dc.FillRect(r5, &br5);
	CRect r4(700, 100, 700 + 300 *(1-pDoc->unpass), 50);
	CBrush br4(RGB(25, 101, 25));
	dc.FillRect(r4, &br4);
	//////////////////////////////////////////////////////////////////////////
	dc.TextOut(700, 283, TEXT("ȫ��ѧ���е���߷֣�"));
	CRect r6(700, 233, 1000, 183);
	CBrush br6(RGB(255, 255, 255));
	dc.FillRect(r6, &br6);
	CRect r7(700, 233, 700 + 300 * ((float)pDoc->max_grade/100), 183);
	CBrush br7(RGB(25, 211, 25));
	dc.FillRect(r7, &br7);
	//////////////////////////////////////////////////////////////////////////
	dc.TextOut(700, 400, TEXT("ȫ��ѧ���е���ͷ֣�"));
	CRect r8(700, 350, 1000, 300);
	CBrush br8(RGB(255, 255, 255));
	dc.FillRect(r8, &br8);
	CRect r9(700, 350, 700 + 300 * ((float)pDoc->min_grade / 100), 300);
	CBrush br9(RGB(25, 21, 180));
	dc.FillRect(r9, &br9);
	//////////////////////////////////////////////////////////////////////////
	CString str1;
	str1.Format(TEXT("%.2f"), pDoc->average);
	dc.TextOut(820, 495, str1+TEXT("��"));
	CString str2;
	str2.Format(TEXT("%.2f"), (1-pDoc->unpass)*100);
	dc.TextOut(820, 95, str2+TEXT("%"));
	str2.Format(TEXT("%d"), pDoc->min_grade);
	dc.TextOut(820, 345, str2 + TEXT("��"));
	str2.Format(TEXT("%d"), pDoc->max_grade);
	dc.TextOut(820, 228, str2 + TEXT("��"));
	dc.TextOut(200, 700, TEXT("��ѡ�γ�ȫ��ѧ�������ηֲ�"));
}
