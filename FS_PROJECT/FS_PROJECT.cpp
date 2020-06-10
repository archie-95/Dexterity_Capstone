// FS_PROJECT.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include"Source.h"
#include"user.h"
#include"questions.h"
#include "dashboard.h"
#include <iostream>
#include<fstream>
#include<conio.h>
#include<stdio.h>
#include<iomanip>
#include<stdlib.h>
#include<string.h>

using namespace std;
#define filename "std2.txt"
#define quesfile "ques.txt"
fstream ifile;

	
	int main()
	{
		int ch, flag;
		user s;
		questions q;
		dashboard d;
		system("cls");
		cout << "welcome to quiz compedition" << endl;
		cout << "press 1 to register or login" << endl;
		cout << "press 2 to add new question" << endl;
		
		cin >> ch;
		switch (ch)
		{
		case 1:system("cls");
			for (;;)
			{
				cout << endl << "1.- read\t2- display\t 3 .-login \t4.- modify\t5.- exit" << endl;
				cout << "enter the choice:";
				cin >> ch;
				switch (ch)
				{
				case 1: s.opener(ifile, filename, ios::app);
					cout << "enter the student details\n";
					s.read();
					break;
				case 2: s.opener(ifile, filename, ios::in);
					cout << "The student details are:" << endl;
					s.display();
					break;
				case 3:s.opener(ifile, filename, ios::in);
					cout << "Searching based on USN number" << endl;
					flag = s.login();
					if (flag == -1)
						cout << "Record not found" << endl;
					else
					{
						d.welcome(flag);
					}
					break;
				case 4: s.opener(ifile, filename, ios::in | ios::out);
					cout << "To modify the record based on USN" << endl;
					flag = s.search();
					if (flag == -1)
						cout << "Record not found" << endl;


					else
						s.modify(flag);
					break;


				default:
					exit(0);
				}
				ifile.close();
				cout << "press any key to continue";
				_getch();
			}
			
				break;

		case 2:system("cls");
			for (;;)
			{
				cout << endl << "1.- read\t2- display\t 3 .-search\t4.- modify\t5.- exit" << endl;
				cout << "enter the choice:";
				cin >> ch;
				switch (ch)
				{
				case 1: q.opener(ifile, quesfile, ios::app);
					cout << "enter the student details\n";
					q.read();
					break;
				case 2: q.opener(ifile, quesfile, ios::in);
					cout << "The student details are:" << endl;
					q.display();
					break;
				case 3:q.opener(ifile, quesfile, ios::in);
					cout << "Searching based on USN number" << endl;
					flag = q.search();
					if (flag == -1)
						cout << "Record not found" << endl;
					break;
				case 4: q.opener(ifile, quesfile, ios::in | ios::out);
					cout << "To modify the record based on USN" << endl;
			         flag =q.search();
					if (flag == -1)
						cout << "Record not found" << endl;
					else
						q.modify(flag);
					break;


				default:
					exit(0);
				}
				ifile.close();
			}
			break;

		}
	}
	


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
