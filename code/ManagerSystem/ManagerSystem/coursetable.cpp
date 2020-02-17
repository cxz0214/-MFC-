// coursetable.h : Ccoursetable ���ʵ��



// Ccoursetable ʵ��

// ���������� 2019��6��25��, 17:08

#include "stdafx.h"
#include "coursetable.h"
IMPLEMENT_DYNAMIC(Ccoursetable, CRecordset)

Ccoursetable::Ccoursetable(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_Class_number = 0;
	m_T_number = 0;
	m_Class_name = L"";
	m_Class_count = 0;
	m_SetDepartment = L"";
	m_Credit = 0.0;
	m_nFields = 6;
	m_nDefaultType = snapshot;
}
//#error ��ȫ���⣺�����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString Ccoursetable::GetDefaultConnect()
{
	return _T("Driver=MySQL ODBC 8.0 Unicode Driver;SERVER=127.0.0.1;UID=root;PWD=password;DATABASE=mysql_learn;PORT=3306");
}

CString Ccoursetable::GetDefaultSQL()
{
	return _T("[coursetable]");
}

void Ccoursetable::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Long(pFX, _T("[Class_number]"), m_Class_number);
	RFX_Long(pFX, _T("[T_number]"), m_T_number);
	RFX_Text(pFX, _T("[Class_name]"), m_Class_name);
	RFX_Long(pFX, _T("[Class_count]"), m_Class_count);
	RFX_Text(pFX, _T("[SetDepartment]"), m_SetDepartment);
	RFX_Single(pFX, _T("[Credit]"), m_Credit);

}
/////////////////////////////////////////////////////////////////////////////
// Ccoursetable ���

#ifdef _DEBUG
void Ccoursetable::AssertValid() const
{
	CRecordset::AssertValid();
}

void Ccoursetable::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


