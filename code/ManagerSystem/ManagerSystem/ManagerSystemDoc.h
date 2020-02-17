
// ManagerSystemDoc.h : CManagerSystemDoc 类的接口
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
protected: // 仅从序列化创建
	CManagerSystemDoc();
	DECLARE_DYNCREATE(CManagerSystemDoc)

// 特性
public:
	//////////////////////////////////////////////////////////////////////////
	//记录当前用户
	int student_user;   //当前登录的学生用户
	int teacher_user;   //当前登录的教师用户
	//////////////////////////////////////////////////////////////////////////
	//获取点击行
	int study_num;
	int column;
	int teacher_num;
	int login_num;
	int student_change_class;
	int student_exit_class;
	int teacher_manager_list2;
	int teacher_manager_list;
	//////////////////////////////////////////////////////////////////////////
	//学生基本信息修改
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
	//学生学籍信息修改
	int stu_number;
	CString stu_name;
	int stu_class;
	short stu_seril;
	CString stu_department;
	CString stu_major;
	float stu_gpa;
	//////////////////////////////////////////////////////////////////////////
	//教师信息修改
	int T_number;
	CString T_name;
	CString T_sex;
	CString T_department;
	//////////////////////////////////////////////////////////////////////////
	//录入成绩
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
// 操作
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
	Cadmin_login pAdminSet;//管理员登录记录集
	Cstudent_login pStudentSet;//学生登录记录集
	Cteacher_login pTeacherSet;//教师登录记录集
	Csbasicinformation pStudentBasic;//学生基本信息记录集
	Csscholasticin psscholSet; //学生学籍信息记录集
	Cteacherinfo pteacherSet;  //教师基本信息记录集
	Ccoursetable pcoursetableSet;//供选课程表
	Cs_classinfo pChangedSet; //已选课表



// 重写
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 实现
public:
	virtual ~CManagerSystemDoc();

	
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 用于为搜索处理程序设置搜索内容的 Helper 函数
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
