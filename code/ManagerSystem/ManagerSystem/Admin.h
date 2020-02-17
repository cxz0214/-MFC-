#pragma once
#include "Admin.h"
#include "admin_login.h"
class CAdmin
{
public:
	CAdmin();
	~CAdmin();
	CString GetAdminUser();//获取用户名
	CString GetAdminPassword();//获取密码
	void SetAdminObj(CString user, CString password);
	Cadmin_login* GetAdminUSet();
	void SetAdminSet(Cadmin_login* pset);
	int AddCount(CString User,CString Password);
private:
	CString admin_user;            //管理员用户名
	CString admin_password;		   //管理员密码
	Cadmin_login* pAdminSet;	  //管理员数据库记录集指针
};

