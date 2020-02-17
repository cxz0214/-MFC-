// s_classinfo.h : Cs_classinfo 类的实现



// Cs_classinfo 实现

// 代码生成在 2019年6月25日, 18:38

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
//#error 安全问题：连接字符串可能包含密码。
// 此连接字符串中可能包含明文密码和/或其他重要
// 信息。请在查看完此连接字符串并找到所有与安全
// 有关的问题后移除 #error。可能需要将此密码存
// 储为其他格式或使用其他的用户身份验证。
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
// RFX_Text() 和 RFX_Int() 这类宏依赖的是
// 成员变量的类型，而不是数据库字段的类型。
// ODBC 尝试自动将列值转换为所请求的类型
	RFX_Long(pFX, _T("[S_number]"), m_S_number);
	RFX_Long(pFX, _T("[S_grade]"), m_S_grade);
	RFX_Long(pFX, _T("[T_number]"), m_T_number);
	RFX_Long(pFX, _T("[Class_number]"), m_Class_number);

}
/////////////////////////////////////////////////////////////////////////////
// Cs_classinfo 诊断

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


