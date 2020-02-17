// coursetable.h : Ccoursetable 的声明

#pragma once

// 代码生成在 2019年6月25日, 17:08

class Ccoursetable : public CRecordset
{
public:
	Ccoursetable(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(Ccoursetable)

// 字段/参数数据

// 以下字符串类型(如果存在)反映数据库字段(ANSI 数据类型的 CStringA 和 Unicode
// 数据类型的 CStringW)的实际数据类型。
//  这是为防止 ODBC 驱动程序执行可能
// 不必要的转换。如果希望，可以将这些成员更改为
// CString 类型，ODBC 驱动程序将执行所有必要的转换。
// (注意: 必须使用 3.5 版或更高版本的 ODBC 驱动程序
// 以同时支持 Unicode 和这些转换)。

	long	m_Class_number;
	long	m_T_number;
	CStringW	m_Class_name;
	long	m_Class_count;
	CStringW	m_SetDepartment;
	float	m_Credit;

// 重写
	// 向导生成的虚函数重写
	public:
	virtual CString GetDefaultConnect();	// 默认连接字符串

	virtual CString GetDefaultSQL(); 	// 记录集的默认 SQL
	virtual void DoFieldExchange(CFieldExchange* pFX);	// RFX 支持

// 实现
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

};


