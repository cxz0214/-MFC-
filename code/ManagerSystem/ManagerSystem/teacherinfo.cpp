// teacherinfo.h : Cteacherinfo 类的实现



// Cteacherinfo 实现

// 代码生成在 2019年6月24日, 16:15

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
//#error 安全问题：连接字符串可能包含密码。
// 此连接字符串中可能包含明文密码和/或其他重要
// 信息。请在查看完此连接字符串并找到所有与安全
// 有关的问题后移除 #error。可能需要将此密码存
// 储为其他格式或使用其他的用户身份验证。
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
// RFX_Text() 和 RFX_Int() 这类宏依赖的是
// 成员变量的类型，而不是数据库字段的类型。
// ODBC 尝试自动将列值转换为所请求的类型
	RFX_Text(pFX, _T("[T_name]"), m_T_name);
	RFX_Long(pFX, _T("[T_number]"), m_T_number);
	RFX_Text(pFX, _T("[T_sex]"), m_T_sex);
	RFX_Text(pFX, _T("[Department]"), m_Department);

}
/////////////////////////////////////////////////////////////////////////////
// Cteacherinfo 诊断

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


