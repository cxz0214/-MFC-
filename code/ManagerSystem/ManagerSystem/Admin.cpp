#include "stdafx.h"
#include "Admin.h"
#include "admin_login.h"

CAdmin::CAdmin()
{
}


CAdmin::~CAdmin()
{
}

CString CAdmin::GetAdminUser()                            //��ȡ�û���
{
	return admin_user;
}

CString CAdmin::GetAdminPassword()						  //��ȡ�û�������
{
	return admin_password;
}

void CAdmin::SetAdminObj(CString user, CString password)	  //�����û�
{
	admin_user = user;
	admin_password = password;
}

Cadmin_login* CAdmin::GetAdminUSet()
{
	return pAdminSet;
}

void CAdmin::SetAdminSet(Cadmin_login* pset)                    //���ü�¼��ָ��
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
