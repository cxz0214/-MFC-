// sbasicinformation.h : Csbasicinformation 类的实现



// Csbasicinformation 实现

// 代码生成在 2019年6月21日, 21:02

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
//#error 安全问题：连接字符串可能包含密码。
// 此连接字符串中可能包含明文密码和/或其他重要
// 信息。请在查看完此连接字符串并找到所有与安全
// 有关的问题后移除 #error。可能需要将此密码存
// 储为其他格式或使用其他的用户身份验证。
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
// RFX_Text() 和 RFX_Int() 这类宏依赖的是
// 成员变量的类型，而不是数据库字段的类型。
// ODBC 尝试自动将列值转换为所请求的类型
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
// Csbasicinformation 诊断

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


