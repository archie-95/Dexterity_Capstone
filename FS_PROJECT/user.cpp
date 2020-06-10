#include "pch.h"
#include "user.h"
#include<iostream>
#include<fstream>
#include<conio.h>
#include<stdio.h>
#include<iomanip>
#include<stdlib.h>
#include<string.h>

using namespace std;

extern fstream ifile;
void user::opener(fstream &sfile, const char *fn, int mode)
{
	sfile.open(fn, mode);
	if (!sfile)
	{
		cout << "unable to open a file" << endl;

		exit(1);
	}
}void user::read()
{
	fflush(NULL);
	gets_s(a);
	cout << "enter the usn number:"; gets_s(usn);
	cout << "enter the name:"; gets_s(name);
	cout << "enter password:"; gets_s(pass);
	cout << "enter the age:"; gets_s(age);
	cout << "enter the branch:"; gets_s(branch);
	cout << "enter the sem:"; gets_s(sem);
	pack();
}
// function to pack the student record using delimiter
void user::pack()
{
	char buffer[100];
	strcpy_s(buffer, usn); strcat_s(buffer, "|");
	strcat_s(buffer, name); strcat_s(buffer, "|");
	
	strcat_s(buffer, pass); strcat_s(buffer, "|");
	strcat_s(buffer, age); strcat_s(buffer, "|");
	strcat_s(buffer, branch); strcat_s(buffer, "|");
	strcat_s(buffer, sem); strcat_s(buffer, "|");
	ifile.fill('*');
	cout << buffer;
	ifile << setiosflags(ios::left) << setw(sizeof(user)) << buffer << endl;
	
	
}
//function to display student record
void user::display()
{
	char buffer[75];
	cout << setiosflags(ios::left);
	cout << setw(15) << "USN" << setw(20) << "NAME" << setw(15)<<"PASSWORD"<< setw(10) << "AGE";
	cout << setw(10) << "BRANCH" << setw(5) << "SEM" << endl;
	while (1)
	{
		unpack();
		if (ifile.eof())
		{
			break;
			cout << "file ends here";
		}
		if (usn[0] != '$')
		{
			
			cout << setw(15) << usn << setw(20) << name << setw(15)<<pass<<setw(10) << age;
			cout << setw(10) << branch << setw(5) << sem << endl;
		}
	}
}
void user::unpack()
{
	char dummy[75];
	ifile.getline(usn, 15, '|');
	ifile.getline(name, 20, '|');
	ifile.getline(pass, 20, '|');
	ifile.getline(age, 5, '|');
	ifile.getline(branch, 6, '|');
	ifile.getline(sem, 5, '|');
	ifile.getline(dummy, 75, '\n');
	

}
//function to search student record based on USN.
int user::search()
{
	int flag;
	char sname[20],spass[20];
	cout << "enter the name:";
	cin >> sname;
	cout << "enter the password";
		cin >> spass;
	while (!ifile.eof())
	{
		flag = ifile.tellg();
		unpack();
		if (usn[0] != '$' &&strcmp(name, sname) == 0  && strcmp(pass,spass)==0)
		{
			cout << "welcome" << name;
			cout << "USN:" << usn << "\n" << "NAME:" << name << "\n" << "AGE:" << age;
			cout << "\n" << "BRANCH:" << branch << "\n" << "SEM:" << sem << "\n";
			return flag;
		}
	}
	return -1;
}
void user::modify(int recpos)
{
	ifile.seekp(recpos, ios::beg);
	ifile.put('$');
	ifile.seekp(0, ios::end);
	read();
}
int user::login()
{
	int flag;
	char sname[20], spass[20];
	cout << "enter the name:";
	cin >> sname;
	cout << "enter the password";
	cin >> spass;
	while (!ifile.eof())
	{
		flag = ifile.tellg();
		unpack();
		if (usn[0] != '$' &&strcmp(name, sname) == 0 && strcmp(pass, spass) == 0)
		{
			return flag;
		}
	}
	return -1;
}
