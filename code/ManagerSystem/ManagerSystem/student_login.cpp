// student_login.h : Cstudent_login ���ʵ��



// Cstudent_login ʵ��

// ���������� 2019��6��21��, 21:12

#include "stdafx.h"
#include "student_login.h"
IMPLEMENT_DYNAMIC(Cstudent_login, CRecordset)

Cstudent_login::Cstudent_login(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_S_number = 0;
	m_S_password = L"";
	m_nFields = 2;
	m_nDefaultType = snapshot;
}
//#error ��ȫ���⣺�����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString Cstudent_login::GetDefaultConnect()
{
	return _T("Driver=MySQL ODBC 8.0 Unicode Driver;SERVER=127.0.0.1;UID=root;PWD=password;DATABASE=mysql_learn;PORT=3306");
}

CString Cstudent_login::GetDefaultSQL()
{
	return _T("[student_login]");
}

void Cstudent_login::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Long(pFX, _T("[S_number]"), m_S_number);
	RFX_Text(pFX, _T("[S_password]"), m_S_password);

}
/////////////////////////////////////////////////////////////////////////////
// Cstudent_login ���

#ifdef _DEBUG
void Cstudent_login::AssertValid() const
{
	CRecordset::AssertValid();
}

void Cstudent_login::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


