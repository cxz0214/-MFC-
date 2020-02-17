
// ManagerSystemDoc.h : CManagerSystemDoc ��Ľӿ�
//


#pragma once
#include "admin_login.h"
#include "student_login.h"
#include "teacher_login.h"
#include "sbasicinformation.h"
#include "sscholasticin.h"
#include "teacherinfo.h"
#include "coursetable.h"
#include "s_classinfo.h"
class CManagerSystemDoc : public CDocument
{
protected: // �������л�����
	CManagerSystemDoc();
	DECLARE_DYNCREATE(CManagerSystemDoc)

// ����
public:
	//////////////////////////////////////////////////////////////////////////
	//��¼��ǰ�û�
	int student_user;   //��ǰ��¼��ѧ���û�
	int teacher_user;   //��ǰ��¼�Ľ�ʦ�û�
	//////////////////////////////////////////////////////////////////////////
	//��ȡ�����
	int study_num;
	int column;
	int teacher_num;
	int login_num;
	int student_change_class;
	int student_exit_class;
	int teacher_manager_list2;
	int teacher_manager_list;
	//////////////////////////////////////////////////////////////////////////
	//ѧ��������Ϣ�޸�
	int number_s;
	CString name_s;
	CString sex_s;
	int bir_year_s;
	int bir_month_s;
	int bir_day_s;
	CString nation_s;
	CString ID_s;
	CString plostic_s;
	int enter_year_s;
	int enter_month_s;
	int enter_day_s;
	CString place_s;
	//////////////////////////////////////////////////////////////////////////
	//ѧ��ѧ����Ϣ�޸�
	int stu_number;
	CString stu_name;
	int stu_class;
	short stu_seril;
	CString stu_department;
	CString stu_major;
	float stu_gpa;
	//////////////////////////////////////////////////////////////////////////
	//��ʦ��Ϣ�޸�
	int T_number;
	CString T_name;
	CString T_sex;
	CString T_department;
	//////////////////////////////////////////////////////////////////////////
	//¼��ɼ�
	int D_Snumber;
	CString D_name;
	CString D_Sdepartment;
	CString D_Sclass;
	int D_Sgrade;
	////////////////////////////////////////////////////////////////////////////
	CString comboxstr;
	int comboxint;
	CListCtrl* plistCtrl=NULL;
	//////////////////////////////////////////////////////////////////////////
	int grade[10];
	float average=0;
	int sum_grade=0;
	int sum_student=0;
	float unpass = 0;
	int max_grade = 0;
	int min_grade = 0;
// ����
public:
	void initvector();
	void DeleteStudentBasic(int snumber);
	Cadmin_login* GetAdminSet()
	{
		return &pAdminSet;
	}
	Cstudent_login* GetStudentSet()
	{
		return &pStudentSet;
	}
	Cteacher_login* GetTeacherSet()
	{
		return &pTeacherSet;
	}
	Csbasicinformation* GetStudentBasic()
	{
		return &pStudentBasic;
	}
	Csscholasticin* GetSscholSet()
	{
		return &psscholSet;
	}
	Cteacherinfo* GetTeacherInforSet()
	{
		return &pteacherSet;
	}
	Ccoursetable*GetCourseSet()
	{
		return &pcoursetableSet;
	}
	Cs_classinfo*getClassChangedSet()
	{
		return &pChangedSet;
	}
private:
	Cadmin_login pAdminSet;//����Ա��¼��¼��
	Cstudent_login pStudentSet;//ѧ����¼��¼��
	Cteacher_login pTeacherSet;//��ʦ��¼��¼��
	Csbasicinformation pStudentBasic;//ѧ��������Ϣ��¼��
	Csscholasticin psscholSet; //ѧ��ѧ����Ϣ��¼��
	Cteacherinfo pteacherSet;  //��ʦ������Ϣ��¼��
	Ccoursetable pcoursetableSet;//��ѡ�γ̱�
	Cs_classinfo pChangedSet; //��ѡ�α�



// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~CManagerSystemDoc();

	
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
