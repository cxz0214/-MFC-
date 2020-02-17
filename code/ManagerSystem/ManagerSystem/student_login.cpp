// student_login.h : Cstudent_login 类的实现



// Cstudent_login 实现

// 代码生成在 2019年6月21日, 21:12

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
//#error 安全问题：连接字符串可能包含密码。
// 此连接字符串中可能包含明文密码和/或其他重要
// 信息。请在查看完此连接字符串并找到所有与安全
// 有关的问题后移除 #error。可能需要将此密码存
// 储为其他格式或使用其他的用户身份验证。
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
// RFX_Text() 和 RFX_Int() 这类宏依赖的是
// 成员变量的类型，而不是数据库字段的类型。
// ODBC 尝试自动将列值转换为所请求的类型
	RFX_Long(pFX, _T("[S_number]"), m_S_number);
	RFX_Text(pFX, _T("[S_password]"), m_S_password);

}
/////////////////////////////////////////////////////////////////////////////
// Cstudent_login 诊断

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


