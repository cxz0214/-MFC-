// teacher_login.h : Cteacher_login 类的实现



// Cteacher_login 实现

// 代码生成在 2019年6月21日, 21:24

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
//#error 安全问题：连接字符串可能包含密码。
// 此连接字符串中可能包含明文密码和/或其他重要
// 信息。请在查看完此连接字符串并找到所有与安全
// 有关的问题后移除 #error。可能需要将此密码存
// 储为其他格式或使用其他的用户身份验证。
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
// RFX_Text() 和 RFX_Int() 这类宏依赖的是
// 成员变量的类型，而不是数据库字段的类型。
// ODBC 尝试自动将列值转换为所请求的类型
	RFX_Long(pFX, _T("[T_number]"), m_T_number);
	RFX_Text(pFX, _T("[T_password]"), m_T_password);

}
/////////////////////////////////////////////////////////////////////////////
// Cteacher_login 诊断

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


