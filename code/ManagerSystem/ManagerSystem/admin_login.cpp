// admin_login.h : Cadmin_login ���ʵ��



// Cadmin_login ʵ��

// ���������� 2019��6��21��, 17:36

#include "stdafx.h"
#include "admin_login.h"
IMPLEMENT_DYNAMIC(Cadmin_login, CRecordset)

Cadmin_login::Cadmin_login(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_Admin_login = L"";
	m_Admin_password = L"";
	m_nFields = 2;
	m_nDefaultType = snapshot;
}
//#error ��ȫ���⣺�����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString Cadmin_login::GetDefaultConnect()
{
	return _T("Driver=MySQL ODBC 8.0 Unicode Driver;SERVER=127.0.0.1;UID=root;PWD=password;DATABASE=mysql_learn;PORT=3306");
}

CString Cadmin_login::GetDefaultSQL()
{
	return _T("[admin_login]");
}

void Cadmin_login::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Text(pFX, _T("[Admin_login]"), m_Admin_login);
	RFX_Text(pFX, _T("[Admin_password]"), m_Admin_password);

}
/////////////////////////////////////////////////////////////////////////////
// Cadmin_login ���

#ifdef _DEBUG
void Cadmin_login::AssertValid() const
{
	CRecordset::AssertValid();
}

void Cadmin_login::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


