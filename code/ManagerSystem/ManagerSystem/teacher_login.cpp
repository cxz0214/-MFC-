// teacher_login.h : Cteacher_login ���ʵ��



// Cteacher_login ʵ��

// ���������� 2019��6��21��, 21:24

#include "stdafx.h"
#include "teacher_login.h"
IMPLEMENT_DYNAMIC(Cteacher_login, CRecordset)

Cteacher_login::Cteacher_login(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_T_number = 0;
	m_T_password = L"";
	m_nFields = 2;
	m_nDefaultType = snapshot;
}
//#error ��ȫ���⣺�����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString Cteacher_login::GetDefaultConnect()
{
	return _T("Driver=MySQL ODBC 8.0 Unicode Driver;SERVER=127.0.0.1;UID=root;PWD=password;DATABASE=mysql_learn;PORT=3306");
}

CString Cteacher_login::GetDefaultSQL()
{
	return _T("[teacher_login]");
}

void Cteacher_login::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Long(pFX, _T("[T_number]"), m_T_number);
	RFX_Text(pFX, _T("[T_password]"), m_T_password);

}
/////////////////////////////////////////////////////////////////////////////
// Cteacher_login ���

#ifdef _DEBUG
void Cteacher_login::AssertValid() const
{
	CRecordset::AssertValid();
}

void Cteacher_login::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


