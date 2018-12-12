#include <iostream>
#include <fstream>
#include <cctype>
#include "student.h"
using namespace std;
void create_record();
void update_gpa(int x);
void showall();
void display_sp();
void main()
{
	system("color 9D");
	int x;
	cout << "\n\n\n\t\t WELCOME TO EXAMINATTION SYSTEM";
	cout << "\n\n\n\t\t OUR MOTTO IS TO SERVE YOU ";
	cin.get();
	do
	{
		system("cls");
		cout << "\n\n\n\tMAIN MENU";
		cout << "\n\n\t1. NEW RECORD ENTER";
		cout << "\n\n\t2. CHANGE GPA";
		cout << "\n\n\t3. SHOW ALL";
		cout << "\n\n\t4. DISPLAY SPECIFIC";
		cout << "\n\n\t5. FOR EXIT";
		cout << "\n\n\tSelect Your Option (1-4) ";
		cin >> x;
		system("cls");
		switch (x)
		{
		case 1:
			create_record();
			break;
		case 2:
			cout << "\n\n\tEnter The id : "; cin >> x;
			update_gpa(x);
			break;
		case 3:
			showall();
			break;
		case 4:
			display_sp();
			break;
		case 5:
			cout<<"\n\nthanks for using system \n";
			break;

				default:cout << "\a";
		}
		cin.ignore();
		cin.get();
	} while (x != 5);

}
void create_record()
{
	student s;
	
	fstream file;
	file.open("student.dat", ios::binary | ios::app|ios::out);
	s.setdata();
	file.write(reinterpret_cast<char *>(&s), sizeof(s));
	file.close();			
}

void update_gpa(int n)
{
	int t = 0, no = 0;
	double g;
	cout << "enter the semester whose gpa is to be updated : ";
	cin >> no;
	student s;
	fstream File;
	File.open("student.dat", ios::binary | ios::in | ios::out);
	while (!File.eof() && t == 0)
	{
		File.read(reinterpret_cast<char*>(&s), sizeof(s));

		if (s.getid() == n)
		{
			cout << "enter new GPA : ";
			cin >> g;
			if (no == 1)
				s.setgpa1(g);
			else
				if (no == 2)
					s.setgpa2(g);
			int pos = (-1)*int(sizeof(s));
			File.seekp(pos, ios::cur);
			File.write(reinterpret_cast<char *> (&s), sizeof(s));
			cout << "\n\n\t Record Updated ";
			t = 1;
			s.show();
		}
	}
	File.close();
}
void showall()
{
	student s;
	ifstream in;
	in.open("student.dat", ios::binary);
	while (in.read(reinterpret_cast<char *> (&s), sizeof(s)))
	{
		s.show();
		cout << "\n___________________________________________________________\n";
	}
	in.close();
}
void display_sp()
{
	int id, n;
	int t = 0;
	cout << "enter id you want to see : ";
	cin >> id;
	cout << "\nenter semester whose gpa you want to see : ";
	cin >> n;
	student s;
	fstream File;
	File.open("student.dat", ios::binary | ios::in | ios::out);
	while (!File.eof() && t == 0)
	{
		File.read(reinterpret_cast<char*>(&s), sizeof(s));

		if (s.getid() == id)
		{
			s.specific(n);
			t = 1;
		}
	}
	File.close();
}