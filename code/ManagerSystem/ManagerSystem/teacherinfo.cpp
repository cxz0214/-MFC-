// teacherinfo.h : Cteacherinfo ���ʵ��



// Cteacherinfo ʵ��

// ���������� 2019��6��24��, 16:15

#include "stdafx.h"
#include "teacherinfo.h"
IMPLEMENT_DYNAMIC(Cteacherinfo, CRecordset)

Cteacherinfo::Cteacherinfo(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_T_name = L"";
	m_T_number = 0;
	m_T_sex = L"";
	m_Department = L"";
	m_nFields = 4;
	m_nDefaultType = snapshot;
}
//#error ��ȫ���⣺�����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString Cteacherinfo::GetDefaultConnect()
{
	return _T("Driver=MySQL ODBC 8.0 Unicode Driver;SERVER=127.0.0.1;UID=root;PWD=password;DATABASE=mysql_learn;PORT=3306");
}

CString Cteacherinfo::GetDefaultSQL()
{
	return _T("[teacherinfo]");
}

void Cteacherinfo::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Text(pFX, _T("[T_name]"), m_T_name);
	RFX_Long(pFX, _T("[T_number]"), m_T_number);
	RFX_Text(pFX, _T("[T_sex]"), m_T_sex);
	RFX_Text(pFX, _T("[Department]"), m_Department);

}
/////////////////////////////////////////////////////////////////////////////
// Cteacherinfo ���

#ifdef _DEBUG
void Cteacherinfo::AssertValid() const
{
	CRecordset::AssertValid();
}

void Cteacherinfo::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


