#include "stdafx.h"
#include "StudentBasic.h"


CStudentBasic::CStudentBasic()
{
}


CStudentBasic::~CStudentBasic()
{
}

void CStudentBasic::SetStudentBasic(int snumber, CString sname, CString ssex, CTime sbirthday, CString snation,
	CString sID, CString splot, CTime sentertime, CString sorigin)
{
	number = snumber;
	name=sname;
	sex=ssex;
	birthday=sbirthday;
	nation=snation;
	ID=sID;
	plostic=splot;
	entertime=sentertime;
	origin=sorigin;
}

void CStudentBasic::AddStudentBasic()
{
	if (pStudentBasicSet->IsOpen()==FALSE)
	{
		pStudentBasicSet->Open();
	}
	pStudentBasicSet->AddNew();
	pStudentBasicSet->m_S_name = name;
	pStudentBasicSet->m_S_number = number;
	pStudentBasicSet->m_S_sex = sex;
	pStudentBasicSet->m_S_birthday = birthday;
	pStudentBasicSet->m_S_nation = nation;
	pStudentBasicSet->m_S_idnumber = ID;
	pStudentBasicSet->m_S_polst = plostic;
	pStudentBasicSet->m_S_entertime = entertime;
	pStudentBasicSet->m_S_origin = origin;
	pStudentBasicSet->Update();
	pStudentBasicSet->Close();
}

void CStudentBasic::SetBasicSet(Csbasicinformation* pset)
{
	pStudentBasicSet = pset;
}
