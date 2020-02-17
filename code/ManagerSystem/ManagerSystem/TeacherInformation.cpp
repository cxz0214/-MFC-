#include "stdafx.h"
#include "TeacherInformation.h"


TeacherInformation::TeacherInformation()
{
}


TeacherInformation::~TeacherInformation()
{
}

void TeacherInformation::SetTeacherObJ(int number, CString name, CString sex, CString depart)
{
	teacher_num = number;
	teacher_name = name;
	teacher_sex = sex;
	teacher_department = depart;
}

void TeacherInformation::SetTeacherSet(Cteacherinfo* p)
{
	pTeacherSet = p;
}

void TeacherInformation::AddTeacherObj()
{
	if (pTeacherSet->IsOpen()==FALSE)
	{
		pTeacherSet->Open();
	}
	pTeacherSet->AddNew();
	pTeacherSet->m_T_number = teacher_num;
	pTeacherSet->m_T_name = teacher_name;
	pTeacherSet->m_T_sex = teacher_sex;
	pTeacherSet->m_Department = teacher_department;
	pTeacherSet->Update();
	pTeacherSet->Close();
}
