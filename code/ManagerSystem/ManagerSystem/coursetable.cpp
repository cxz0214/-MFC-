// coursetable.h : Ccoursetable 类的实现



// Ccoursetable 实现

// 代码生成在 2019年6月25日, 17:08

#include "stdafx.h"
#include "coursetable.h"
IMPLEMENT_DYNAMIC(Ccoursetable, CRecordset)

Ccoursetable::Ccoursetable(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_Class_number = 0;
	m_T_number = 0;
	m_Class_name = L"";
	m_Class_count = 0;
	m_SetDepartment = L"";
	m_Credit = 0.0;
	m_nFields = 6;
	m_nDefaultType = snapshot;
}
//#error 安全问题：连接字符串可能包含密码。
// 此连接字符串中可能包含明文密码和/或其他重要
// 信息。请在查看完此连接字符串并找到所有与安全
// 有关的问题后移除 #error。可能需要将此密码存
// 储为其他格式或使用其他的用户身份验证。
CString Ccoursetable::GetDefaultConnect()
{
	return _T("Driver=MySQL ODBC 8.0 Unicode Driver;SERVER=127.0.0.1;UID=root;PWD=password;DATABASE=mysql_learn;PORT=3306");
}

CString Ccoursetable::GetDefaultSQL()
{
	return _T("[coursetable]");
}

void Ccoursetable::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() 和 RFX_Int() 这类宏依赖的是
// 成员变量的类型，而不是数据库字段的类型。
// ODBC 尝试自动将列值转换为所请求的类型
	RFX_Long(pFX, _T("[Class_number]"), m_Class_number);
	RFX_Long(pFX, _T("[T_number]"), m_T_number);
	RFX_Text(pFX, _T("[Class_name]"), m_Class_name);
	RFX_Long(pFX, _T("[Class_count]"), m_Class_count);
	RFX_Text(pFX, _T("[SetDepartment]"), m_SetDepartment);
	RFX_Single(pFX, _T("[Credit]"), m_Credit);

}
/////////////////////////////////////////////////////////////////////////////
// Ccoursetable 诊断

#ifdef _DEBUG
void Ccoursetable::AssertValid() const
{
	CRecordset::AssertValid();
}

void Ccoursetable::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


