// sbasicinformation.h : Csbasicinformation ������

#pragma once

// ���������� 2019��6��21��, 21:02

class Csbasicinformation : public CRecordset
{
public:
	Csbasicinformation(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(Csbasicinformation)

// �ֶ�/��������

// �����ַ�������(�������)��ӳ���ݿ��ֶ�(ANSI �������͵� CStringA �� Unicode
// �������͵� CStringW)��ʵ���������͡�
//  ����Ϊ��ֹ ODBC ��������ִ�п���
// ����Ҫ��ת�������ϣ�������Խ���Щ��Ա����Ϊ
// CString ���ͣ�ODBC ��������ִ�����б�Ҫ��ת����
// (ע��: ����ʹ�� 3.5 �����߰汾�� ODBC ��������
// ��ͬʱ֧�� Unicode ����Щת��)��

	long	m_S_number;
	CStringW	m_S_name;
	CStringW	m_S_sex;
	CTime	m_S_birthday;
	CStringW	m_S_nation;
	CStringW	m_S_idnumber;
	CStringW	m_S_polst;
	CTime	m_S_entertime;
	CStringW	m_S_origin;

// ��д
	// �����ɵ��麯����д
	public:
	virtual CString GetDefaultConnect();	// Ĭ�������ַ���

	virtual CString GetDefaultSQL(); 	// ��¼����Ĭ�� SQL
	virtual void DoFieldExchange(CFieldExchange* pFX);	// RFX ֧��

// ʵ��
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

};


