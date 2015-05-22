#include "CStudent.h"
#include <iostream>
using std::cout;
using std::endl;


CStudent::CStudent()
:m_sname("default")
{
	cout<<"Student Contructor called"<<endl;
}

CStudent::~CStudent()
{
	cout<<"Student Destructor called"<<endl;
}

string CStudent::getName()
{
	return m_sname;
}

void CStudent::setName(string name)
{
	this->m_sname = name;
}

int CStudent::getAge()
{
	return m_iage;
}

void CStudent::setAge(int age)
{
	this->m_iage = age;
}

void CStudent::toString()
{
	cout<<"My name is: "<<m_sname<<", and my age is "<<m_iage<<endl;
}
