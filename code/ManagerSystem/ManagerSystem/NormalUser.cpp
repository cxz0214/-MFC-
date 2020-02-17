#include "stdafx.h"
#include "NormalUser.h"


CNormalUser::CNormalUser()
{
}


CNormalUser::~CNormalUser()
{
}

int CNormalUser::GetUserName()
{
	return username;
}
CString CNormalUser::GetUserPassword()
{
	return password;
}

void CNormalUser::SetUserObj( int user, CString pass)
{
	username = user;
	password = pass;
}

void CNormalUser::AddNormalUser(Cstudent_login* pset)
{
	if (pset->IsOpen()==FALSE)
	{
		pset->Open();
	}
	pset->AddNew();
	pset->m_S_number = username;
	pset->m_S_password = password;
	pset->Update();
	pset->Close();
}

void CNormalUser::AddNormalUser(Cteacher_login* pset)
{
	if (pset->IsOpen() == FALSE)
	{
		pset->Open();
	}
	pset->AddNew();
	pset->m_T_number = username;
	pset->m_T_password = password;
	pset->Update();
	pset->Close();
}

void CNormalUser::DeleteNormalUser(Cstudent_login* pset, int user)
{
	if (pset->IsOpen()==FALSE)
	{
		pset->Open();
	}
	CString sql;
	sql.Format(TEXT("S_number='%d'"), user);
	pset->m_strFilter = sql;
	pset->Requery();
	pset->Delete();
	pset->Close();
}

void CNormalUser::DeleteNormalUser(Cteacher_login* pset, int user)
{
	if (pset->IsOpen() == FALSE)
	{
		pset->Open();
	}
	CString sql;
	sql.Format(TEXT("T_number='%d'"), user);
	pset->m_strFilter = sql;
	pset->Requery();
	pset->Delete();
	pset->Close();
}
