#include "stdafx.h"
#include "Admin.h"
#include "admin_login.h"

CAdmin::CAdmin()
{
}


CAdmin::~CAdmin()
{
}

CString CAdmin::GetAdminUser()                            //获取用户名
{
	return admin_user;
}

CString CAdmin::GetAdminPassword()						  //获取用户名密码
{
	return admin_password;
}

void CAdmin::SetAdminObj(CString user, CString password)	  //设置用户
{
	admin_user = user;
	admin_password = password;
}

Cadmin_login* CAdmin::GetAdminUSet()
{
	return pAdminSet;
}

void CAdmin::SetAdminSet(Cadmin_login* pset)                    //设置记录集指针
{
	pAdminSet = pset;
}

int CAdmin::AddCount(CString User, CString Password)
{
	if (pAdminSet->IsOpen() == FALSE)
	{
		pAdminSet->Open();
	}
	pAdminSet->AddNew();
	pAdminSet->m_Admin_login = User;
	pAdminSet->m_Admin_password = Password;
	pAdminSet->Update();
	pAdminSet->Close();
	return 0;
}
