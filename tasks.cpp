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
	struct deadline {
		string task;
		int day;
		int month;
		int year;
	};
	struct deadline d[5];
	struct deadline sort[5];
	int date[5];

	ofstream fout;
	for (int i = 0; action != 2; i++) {
		system("cls");
		cout << "If you want to add a task, click 1! " << endl << "If you want to view your tasks, click 2 ";
		cin >> action;
		if (action == 1) {


			ofstream fout("tasks.txt", ios_base::app);
			cout << "Enter your task: ";
			cin >> d[i].task;

			cout << "Please enter the deadline for task : " << i << endl << "day: ";

			cin >> d[i].day;

			cout << "month: ";

			cin >> d[i].month;

			cout << "year: ";
			cin >> d[i].year;
			fout << d[i].task << " " << d[i].day << "." << d[i].year << "." << d[i].year << endl;
			
			date[i] = d[i].year * 10000 + d[i].year * 100 + d[i].day;

			fout.close();
			
		}

	}


	if (action == 2) {




		ifstream fin("tasks.txt");

		while (!fin.eof()) {
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 5 - i; j++) {
					int temp;
					
					if (date[i] > date[j])
					{
						sort[1] = d[i];
						d[i] = d[j];
						d[j] = sort[1];

					}
				}

			}
			fin.getline(buff, 50);

			cout << buff << endl;

			


		}
		fin.close();

	}



}


