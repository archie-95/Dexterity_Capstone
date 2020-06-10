#include "pch.h"
#include "dashboard.h"
#include"leaderboard.h"
#include "user.h"
#include<iostream>
#include<fstream>
#include<conio.h>
#include<stdio.h>
#include<iomanip>
#include<stdlib.h>
#include<string.h>
answers a;
 ansindex id[5], in;
 anssindex sid[5], sien;
using namespace std;
 extern int i, indsize, sindsize,k;
 char scode[5], spos[5], stotal[5],stans[10][10];
 char file[20], priindex[20], secindex[20];
extern char  buffer[205];
extern int j;
  fstream adfile,aifile,asifile;
 void update(int code, int ans[], int total,char *usn)
 {
	 
	 strcpy_s(file, usn);
	 strcat_s(file, ".txt");
	 strcpy_s(priindex, usn);
	 strcat_s(priindex, "p.txt");
	 strcpy_s(secindex, usn);
	 strcat_s(secindex, "s.txt");

	 in.initial();
	 sien.sinitial();
	 a.read( code, ans, total);
	 in.write();
	 sien.swrite();
	 leader(usn,code, total);

 }
void aopener(fstream &file, const char *fn, int mode)
{
	cout << "fliename came:=" << fn << endl;
	file.open(fn, mode);
	if (!file)
	{
		cout << "unable to open a file";

		exit(1);
	}
}
void ansindex::initial()
{
	aifile.open(priindex, ios::in);
	
	if (!aifile)
	{
		cout << "primary file empty for the first time" << endl;
		indsize = 0;
		return;
	}
	
	for (indsize = 0;; indsize++)
	{
		cout << "\n\nincrement time";
		aifile.getline(id[indsize].code, 5, '|');
		aifile.getline(id[indsize].pos, 5, '\n');
		if (aifile.eof())
		{
			cout << "indsize when break" << indsize;
			break;
		}
	}
	aifile.close();
}
//function to copy sindex file to array structure
void anssindex::sinitial()
{
	asifile.open(secindex, ios::in);
	
	if (!asifile)
	{
		cout << "secondary file empty for the first time" << endl;
		sindsize = 0;
		return;
	}
	for (sindsize = 0;; sindsize++)
	{
		asifile.getline(sid[sindsize].code, 5, '|');
		asifile.getline(sid[sindsize].total,5, '\n');
		if (asifile.eof())
		{
			cout << "sindsize when break" << sindsize;
			break;
		}
	}
	asifile.close();
}
// function to update the index file
void ansindex::write()
{
	aopener(aifile, priindex, ios::out);
	aifile.seekg(0, ios::end);
	
	for (i = 0; i < indsize; i++) {
		cout << id[i].code << "|" << id[i].pos << "\n";
		aifile <<id[i].code<< "|" << id[i].pos << "\n";
		
	}
	aifile.close();
}
//function to upadate the secondary file
void anssindex::swrite()
{
	aopener(asifile, secindex, ios::out);
	asifile.seekg(0, ios::end);
	cout << "\n\nloc of cursor-" << asifile.tellg() << endl;
	cout << "secondary file opened" << endl;
	cout << "\n\nloc of cursor after printing" << asifile.tellg() << endl;
	for (i = 0; i < sindsize; i++)
	{
		cout << "\n\nloc of cursor-" << asifile.tellg() << endl;
		cout << sid[i].code << "|" << sid[i].total << "\n";
		asifile << sid[i].code << "|" << sid[i].total << "\n";
		cout << "\n\nentered secondary file";
	}
	asifile.close();
}
/*int search(char * fusn)
{
	int low = 0, high = indsize - 1, mid;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (strcmp(fusn, id[mid].code) == 0)
			return mid;
		if (strcmp(fusn, id[mid].code) > 0)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return -1;
}*/
// function to read the student record
void answers::read(int code, int ans[], int total)
{
	cout << "\nindsize entering" << indsize;
	cout << "\nsindsize entering" << sindsize;

	_itoa_s(code, scode, 10);
	_itoa_s(total, stotal, 10);
	for (i = indsize; i > 0; i--)
	{
		if (strcmp(scode, id[i - 1].code) < 0)
			id[i] = id[i - 1];
		else
			break;
	}

	
	adfile.open(file, ios::app);
	
	pack( code, ans,total);	
	adfile.seekg(0, ios::end);
	k = adfile.tellg();
	
	adfile << buffer <<"\n";
	_itoa_s(code,id[i].code,10 );
	
	_itoa_s(k, id[i].pos, 10);
	adfile.close();

	indsize++;
	for (i = sindsize; i > 0; i--)
	{
		if (strcmp(scode, sid[i - 1].code) < 0)
			sid[i] = sid[i - 1];
		else if ((strcmp(scode, sid[i - 1].code) == 0) && (strcmp(stotal, sid[i - 1].total) < 0))
			sid[i] = sid[i - 1];
		else
			break;
	}
	strcpy_s(sid[i].code, scode);
	strcpy_s(sid[i].total, stotal);
	sindsize++;

	cout << "\nindsize=" << indsize << endl;
	cout << "sindsize=" << sindsize << endl;
	adfile.close();
}
//function to pack
void answers::pack(int code, int ans[], int total)
{
	_itoa_s(code, scode, 10);
	_itoa_s(total, stotal, 10);
	for (j = 0; j < 10; j++)
		_itoa_s(ans[j], stans[j], 10);
	strcpy_s(buffer, scode); strcat_s(buffer, "|");
	for (j = 0; j < 10; j++)
	{
		strcat_s(buffer, stans[j]);
		strcat_s(buffer, "|");
	}
	
	strcat_s(buffer,stotal); strcat_s(buffer, "|");
	cout << "buffering done"<<endl;
}

/*int sec_search()
{
	int pos, j, flag = -1;
	cout << "\nenter the name to search(sec key):";
	gets_s(b);
	gets_s(skey);
	cout << "the searched record details are :" << endl;
	cout << setiosflags(ios::left);
	cout << "usn" << "\t\tname" << endl;
	opener(dfile, datafile, ios::in | ios::out);
	for (j = 0; j < sindsize; j++)
		if (strcmp(skey, sid[j].sname) == 0)
		{
			cout << sid[j].susn << "\t\t" << sid[j].sname << endl;
			flag = j;
		}
	return flag;
}
void user::unpack()
{
	cout << "inside unpacking";
	char dummy[100];
	adfile.getline(dusn, 15, '|');
	adfile.getline(name, 20, '|');
	adfile.getline(pass, 20, '|');
	adfile.getline(age, 5, '|');
	adfile.getline(branch, 6, '|');
	adfile.getline(sem, 5, '|');
	adfile.getline(dummy, 100, '\n');
	cout << endl << dusn << "\t" << name << "\t" << pass << "\t" << age << "\n";
}*/


