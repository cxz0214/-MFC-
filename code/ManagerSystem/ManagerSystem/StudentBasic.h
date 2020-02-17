#pragma once
#include "sbasicinformation.h"
class CStudentBasic
{
public:
	CStudentBasic();
	~CStudentBasic();
	void SetStudentBasic(int snumber, CString sname,CString ssex,CTime sbirthday,CString snation,CString sID,
		CString splot,CTime sentertime,CString sorigin);
	void AddStudentBasic();
	void SetBasicSet(Csbasicinformation* pset);
private:
	int number;
	CString name;
	CString sex;
	CTime birthday;
	CString nation;
	CString ID;
	CString plostic;
	CTime entertime;
	CString origin;
	Csbasicinformation* pStudentBasicSet;
};

