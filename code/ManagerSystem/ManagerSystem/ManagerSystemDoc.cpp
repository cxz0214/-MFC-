
// ManagerSystemDoc.cpp : CManagerSystemDoc ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "ManagerSystem.h"
#endif
#include <afxdb.h>
#include "ManagerSystemDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CManagerSystemDoc

IMPLEMENT_DYNCREATE(CManagerSystemDoc, CDocument)

BEGIN_MESSAGE_MAP(CManagerSystemDoc, CDocument)
END_MESSAGE_MAP()


// CManagerSystemDoc ����/����

CManagerSystemDoc::CManagerSystemDoc()
{
	// TODO:  �ڴ����һ���Թ������

}

CManagerSystemDoc::~CManagerSystemDoc()
{
}

void CManagerSystemDoc::initvector()
{
	for (int i = 0; i < 10;i++)
	{
		grade[i] = 0;
	}
}

void CManagerSystemDoc::DeleteStudentBasic(int snumber)
{
	CDatabase db;
	Csbasicinformation rs(&db);
	if (rs.IsOpen() == FALSE)
	{
		rs.Open();
	}
	CString sql;
	sql.Format(TEXT("call deletestudent('%d')"), snumber);
	db.ExecuteSQL(sql);
	rs.Close();

}

BOOL CManagerSystemDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO:  �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CManagerSystemDoc ���л�

void CManagerSystemDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO:  �ڴ���Ӵ洢����
	}
	else
	{
		// TODO:  �ڴ���Ӽ��ش���
	}
}

#ifdef SHARED_HANDLERS

// ����ͼ��֧��
void CManagerSystemDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// �޸Ĵ˴����Ի����ĵ�����
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// ������������֧��
void CManagerSystemDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ���ĵ����������������ݡ�
	// ���ݲ���Ӧ�ɡ�;���ָ�

	// ����:     strSearchContent = _T("point;rectangle;circle;ole object;")��
	SetSearchContent(strSearchContent);
}

void CManagerSystemDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CManagerSystemDoc ���

#ifdef _DEBUG
void CManagerSystemDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CManagerSystemDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CManagerSystemDoc ����
