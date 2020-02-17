// sbasicinformation.h : Csbasicinformation ���ʵ��



// Csbasicinformation ʵ��

// ���������� 2019��6��21��, 21:02

#include "stdafx.h"
#include "sbasicinformation.h"
IMPLEMENT_DYNAMIC(Csbasicinformation, CRecordset)

Csbasicinformation::Csbasicinformation(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_S_number = 0;
	m_S_name = L"";
	m_S_sex = L"";
	m_S_birthday;
	m_S_nation = L"";
	m_S_idnumber = L"";
	m_S_polst = L"";
	m_S_entertime;
	m_S_origin = L"";
	m_nFields = 9;
	m_nDefaultType = snapshot;
}
//#error ��ȫ���⣺�����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString Csbasicinformation::GetDefaultConnect()
{
	return _T("Driver=MySQL ODBC 8.0 Unicode Driver;SERVER=127.0.0.1;UID=root;PWD=password;DATABASE=mysql_learn;PORT=3306");
}

CString Csbasicinformation::GetDefaultSQL()
{
	return _T("[sbasicinformation]");
}

void Csbasicinformation::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Long(pFX, _T("[S_number]"), m_S_number);
	RFX_Text(pFX, _T("[S_name]"), m_S_name);
	RFX_Text(pFX, _T("[S_sex]"), m_S_sex);
	RFX_Date(pFX, _T("[S_birthday]"), m_S_birthday);
	RFX_Text(pFX, _T("[S_nation]"), m_S_nation);
	RFX_Text(pFX, _T("[S_idnumber]"), m_S_idnumber);
	RFX_Text(pFX, _T("[S_polst]"), m_S_polst);
	RFX_Date(pFX, _T("[S_entertime]"), m_S_entertime);
	RFX_Text(pFX, _T("[S_origin]"), m_S_origin);

}
/////////////////////////////////////////////////////////////////////////////
// Csbasicinformation ���

#ifdef _DEBUG
void Csbasicinformation::AssertValid() const
{
	CRecordset::AssertValid();
}

void Csbasicinformation::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


