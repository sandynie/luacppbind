#ifndef _CSTUDENT_H
#define _CSTUDENT_H
#include <string>
using std::string;
class CStudent
{
public:
	CStudent();
	~CStudent();
	string getName();
	void setName(string name);
	int getAge();
	void setAge(int age);
	void toString();
protected:
private:
	string m_sname;
	int m_iage;
};
#endif
