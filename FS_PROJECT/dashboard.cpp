#pragma once
#include "pch.h"
#include "dashboard.h"
#include "user.h"
#include<iostream>
#include<fstream>
#include<conio.h>
#include<stdio.h>
#include<iomanip>
#include<stdlib.h>
#include<string.h>
extern fstream ifile;
fstream ques,answer;
int c, uans[10], i = 0, total = 0, j=0;

void dashboard::opener(fstream &sfile, const char *fn, int mode)
{
	sfile.open(fn, mode);
	if (!sfile)
	{
		cout << "unable to open a file" << endl;

		exit(1);
	}
}

void dashboard::unpack()
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
void dashboard::qunpack()
{
	char dummy[250];
	ques.getline(question, 200, '|');
	ques.getline(op[0], 20, '|');
	ques.getline(op[1], 20, '|');
	ques.getline(op[2], 20, '|');
	ques.getline(op[3], 20, '|');
	ques.getline(ans, 20, '|');
	ques.getline(dummy, 250, '\n');
	

}
void dashboard::welcome(int f)
{
	ifile.seekg(f);
	unpack();
	system("cls");
	cout << "welcome:-" <<name << endl;
	cout << "press 1 to start test";
	cin >> c;
	if(c==1)
		{
		cout << "i came inside";
		opener(ques,"ques.txt", ios::in);
			opener(answer, usn, ios::out);
			char buffer[250];
			cout << setiosflags(ios::left);

			while (1)
			{
				i = 0;
				qunpack();
				if (ques.eof())
				{
					break;
					cout << "file ends here";
				}
				if (question[0] != '$')
				{

					cout << "question:=" << question << endl << "option 1:=" << op[0] << "\t\toption 2:=" << op[1];
					cout << endl << "option 3:=" << op[2] << "\t\toption 4:=" << op[3] << endl;
					cout << "enter your option";
					cin >> uans[i];
					cout << endl << "option u put=" << uans[i];
					j = uans[i];
					cout << "j="<<j;
					cout << endl <<"ans:="<< op[j];
					i++;
					
					if (strcmp(op[j-1], ans) == 0)
						total++;
					cout <<"\ntotal is" <<total;
					
				}
			}
	}
	

	
}

