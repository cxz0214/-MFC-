// sscholasticin.h : Csscholasticin ���ʵ��



// Csscholasticin ʵ��

// ���������� 2019��6��23��, 21:02

#include "stdafx.h"
#include "sscholasticin.h"
IMPLEMENT_DYNAMIC(Csscholasticin, CRecordset)

Csscholasticin::Csscholasticin(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_S_number = 0;
	m_S_class = 0;
	m_S_serial = 0;
	m_S_department = L"";
	m_S_major = L"";
	m_S_gpa = 0.0;
	m_nFields = 6;
	m_nDefaultType = snapshot;
}
//#error ��ȫ���⣺�����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString Csscholasticin::GetDefaultConnect()
{
	return _T("Driver=MySQL ODBC 8.0 Unicode Driver;SERVER=127.0.0.1;UID=root;PWD=password;DATABASE=mysql_learn;PORT=3306");
}

CString Csscholasticin::GetDefaultSQL()
{
	return _T("[sscholasticin]");
}

void Csscholasticin::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Long(pFX, _T("[S_number]"), m_S_number);
	RFX_Long(pFX, _T("[S_class]"), m_S_class);
	RFX_Int(pFX, _T("[S_serial]"), m_S_serial);
	RFX_Text(pFX, _T("[S_department]"), m_S_department);
	RFX_Text(pFX, _T("[S_major]"), m_S_major);
	RFX_Single(pFX, _T("[S_gpa]"), m_S_gpa);

}
/////////////////////////////////////////////////////////////////////////////
// Csscholasticin ���

#ifdef _DEBUG
void Csscholasticin::AssertValid() const
{
	CRecordset::AssertValid();
}

void Csscholasticin::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


