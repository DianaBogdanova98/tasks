#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main()
{
	int action = 0;
	string task;

	char buff[50];
	ofstream fout;
	while (action != 2) {
		system("cls");
		cout << "If you want to add a task, click 1! " << endl << "If you want to view your tasks, click 2 ";
		cin >> action;
		if (action == 1) {


			ofstream fout("tasks.txt", ios_base::app);
			cout << "Enter your task: ";
			cin >> task;
			fout << task << endl;
			fout.close();


		}
	}

	if (action == 2) {




		ifstream fin("tasks.txt");
		while (!fin.eof()) {

			fin.getline(buff, 50);

			cout << buff << endl;

		}
		fin.close();

	}
}

