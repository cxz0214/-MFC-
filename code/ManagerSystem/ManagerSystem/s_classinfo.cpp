// s_classinfo.h : Cs_classinfo ���ʵ��



// Cs_classinfo ʵ��

// ���������� 2019��6��25��, 18:38

#include "stdafx.h"
#include "s_classinfo.h"
IMPLEMENT_DYNAMIC(Cs_classinfo, CRecordset)

Cs_classinfo::Cs_classinfo(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_S_number = 0;
	m_S_grade = 0;
	m_T_number = 0;
	m_Class_number = 0;
	m_nFields = 4;
	m_nDefaultType = snapshot;
}
//#error ��ȫ���⣺�����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString Cs_classinfo::GetDefaultConnect()
{
	return _T("Driver=MySQL ODBC 8.0 Unicode Driver;SERVER=127.0.0.1;UID=root;PWD=password;DATABASE=mysql_learn;PORT=3306");
}

CString Cs_classinfo::GetDefaultSQL()
{
	return _T("[s_classinfo]");
}

void Cs_classinfo::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Long(pFX, _T("[S_number]"), m_S_number);
	RFX_Long(pFX, _T("[S_grade]"), m_S_grade);
	RFX_Long(pFX, _T("[T_number]"), m_T_number);
	RFX_Long(pFX, _T("[Class_number]"), m_Class_number);

}
/////////////////////////////////////////////////////////////////////////////
// Cs_classinfo ���

#ifdef _DEBUG
void Cs_classinfo::AssertValid() const
{
	CRecordset::AssertValid();
}

void Cs_classinfo::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


