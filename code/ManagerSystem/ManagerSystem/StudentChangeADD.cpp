#include "stdafx.h"
#include "StudentChangeADD.h"


CStudentChangeADD::CStudentChangeADD()
{
}


CStudentChangeADD::~CStudentChangeADD()
{
}

void CStudentChangeADD::SetClassObj(int c_number, int s_number, int t_number, int c_grade /*= 0*/)
{
	C_number = c_number;
	S_number = s_number;
	T_number = t_number;
	C_grade = c_grade;
}

void CStudentChangeADD::SetClassSet(Cs_classinfo* p)
{
	pClassInforSet = p;
}

void CStudentChangeADD::AddToClasstable()
{
	if (pClassInforSet->IsOpen()==FALSE)
	{
		pClassInforSet->Open();
	}
	pClassInforSet->AddNew();
	pClassInforSet->m_Class_number = C_number;
	pClassInforSet->m_S_number = S_number;
	pClassInforSet->m_T_number = T_number;
	pClassInforSet->m_S_grade = C_grade;
	pClassInforSet->Update();
	pClassInforSet->Close();
}
