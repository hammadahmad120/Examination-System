#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
using namespace std;
class student
{
	char name[50];
	int id;
	double s1;
	double s2;
public:
	void setdata()
	{
		cout << "enter name : ";
		cin.ignore();
		cin.getline(name, 50);
		cout << "enter id : ";
		cin >> id;
		cout << "enter gpa for 1st semester  : ";
		cin >> s1;
		cout << "enter gpa for 2nd semester  : ";
		cin >> s2;
	}
	int getid()
	{
		return id;
	}
	double gets1()
	{
		return s1;
	}
	double gets2()
	{
		return s2;
	}
	void setgpa1(double gp)
	{
			s1 =  gp;
	}
	void setgpa2(double gp)
	{
			s2 = gp;
	}
	void specific(int n)
	{
		cout << "\nname : " << name;
		cout << "\nid : " << id;
		if (n==1)
		cout << "\ngpa 1stsemester : " << s1;
		if (n==2)
		cout << "\n2nd semester : " << s2;
	}
	void show()
	{
		cout << "\nname : " << name;
		cout << "\nid : " << id;
		cout << "\ngpa 1stsemester : " << s1;
		cout << "\n2nd semester : " << s2;
	}
};
#endif