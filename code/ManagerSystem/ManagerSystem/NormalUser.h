#pragma once
#include "teacher_login.h"
#include "student_login.h"
class CNormalUser
{
public:
	CNormalUser();
	~CNormalUser();
	int GetUserName();
	CString GetUserPassword();
	void SetUserObj( int user, CString pass);
	void AddNormalUser(Cstudent_login* pset);
	void AddNormalUser(Cteacher_login* pset);
	void DeleteNormalUser(Cstudent_login* pset, int user);
	void DeleteNormalUser(Cteacher_login* pset, int user);
private:
	int username;
	CString password;
	Cstudent_login* pStuSet;
	Cteacher_login* pTeachSet;
};

