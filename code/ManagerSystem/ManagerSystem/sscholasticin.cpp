// sscholasticin.h : Csscholasticin 类的实现



// Csscholasticin 实现

// 代码生成在 2019年6月23日, 21:02

#include "stdafx.h"
#include "sscholasticin.h"
IMPLEMENT_DYNAMIC(Csscholasticin, CRecordset)

Csscholasticin::Csscholasticin(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_S_number = 0;
	m_S_class = 0;
	m_S_serial = 0;
	m_S_department = L"";
	m_S_major = L"";
	m_S_gpa = 0.0;
	m_nFields = 6;
	m_nDefaultType = snapshot;
}
//#error 安全问题：连接字符串可能包含密码。
// 此连接字符串中可能包含明文密码和/或其他重要
// 信息。请在查看完此连接字符串并找到所有与安全
// 有关的问题后移除 #error。可能需要将此密码存
// 储为其他格式或使用其他的用户身份验证。
CString Csscholasticin::GetDefaultConnect()
{
	return _T("Driver=MySQL ODBC 8.0 Unicode Driver;SERVER=127.0.0.1;UID=root;PWD=password;DATABASE=mysql_learn;PORT=3306");
}

CString Csscholasticin::GetDefaultSQL()
{
	return _T("[sscholasticin]");
}

void Csscholasticin::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() 和 RFX_Int() 这类宏依赖的是
// 成员变量的类型，而不是数据库字段的类型。
// ODBC 尝试自动将列值转换为所请求的类型
	RFX_Long(pFX, _T("[S_number]"), m_S_number);
	RFX_Long(pFX, _T("[S_class]"), m_S_class);
	RFX_Int(pFX, _T("[S_serial]"), m_S_serial);
	RFX_Text(pFX, _T("[S_department]"), m_S_department);
	RFX_Text(pFX, _T("[S_major]"), m_S_major);
	RFX_Single(pFX, _T("[S_gpa]"), m_S_gpa);

}
/////////////////////////////////////////////////////////////////////////////
// Csscholasticin 诊断

#ifdef _DEBUG
void Csscholasticin::AssertValid() const
{
	CRecordset::AssertValid();
}

void Csscholasticin::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


