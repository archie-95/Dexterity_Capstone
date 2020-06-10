#pragma once
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

	class user
	{
	public:
		char usn[15], name[20], age[5], branch[6], sem[5], a[1],pass[20];
		void opener(fstream &sfile, const char *fn, int mode);
		void read();
		void pack();
		void display();
		void unpack();
		int search();
		void modify(int);
		int login();
	};


