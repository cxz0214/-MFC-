#pragma once
#include "Admin.h"
#include "admin_login.h"
class CAdmin
{
public:
	CAdmin();
	~CAdmin();
	CString GetAdminUser();//��ȡ�û���
	CString GetAdminPassword();//��ȡ����
	void SetAdminObj(CString user, CString password);
	Cadmin_login* GetAdminUSet();
	void SetAdminSet(Cadmin_login* pset);
	int AddCount(CString User,CString Password);
private:
	CString admin_user;            //����Ա�û���
	CString admin_password;		   //����Ա����
	Cadmin_login* pAdminSet;	  //����Ա���ݿ��¼��ָ��
};

