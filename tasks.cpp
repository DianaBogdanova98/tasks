#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

struct deadline {
	string task;
	string day;
	string month;
	string year;
};
int main()
{
	int action = 0;
	string task;



	struct deadline d[5];
	struct deadline sort[5];
	int date[5];

	ofstream fout;
	for (int i = 0; action != 2 && action != 3; i++) {
		system("cls");
		cout << "If you want to add a task, click 1! " << endl << "If you want to view or delete your tasks, click 2 " << endl;
		cin >> action;
		if (action == 1) {
			ofstream fout("tasks.txt", ios_base::app);
			cout << "Enter your task: ";
			cin >> d[i].task;

			cout << "Please enter the deadline for task : " << (i + 1) << endl << "day: ";

			cin >> d[i].day;
			size_t found1 = d[i].day.find_first_not_of("1234567890");
			if (found1 != string::npos) {
				cout << "Incorrect date format!" << endl;
				break;
			}



			cout << "month: ";

			cin >> d[i].month;
			size_t found2 = d[i].month.find_first_not_of("1234567890");
			if (found2 != string::npos) {
				cout << "Incorrect date format! " << endl;
				break;
			}

			cout << "year: ";
			cin >> d[i].year;
			size_t found3 = d[i].year.find_first_not_of("1234567890");
			if (found3 != string::npos) {
				cout << "Incorrect date format!" << endl;
				break;
			}

			fout << d[i].day << "." << d[i].month << "." << d[i].year << d[i].task << endl;
			fout.close();


		}
	}


	if (action == 2) {
		ifstream fin("tasks.txt");
		int counter = 0;
		string line[50];
		string year[50];
		int year_i[50];
		string month[50];
		int month_i[50];
		string day[50];
		int day_i[50];
		int date[50];
		for (int i = 0; !fin.eof(); i++) {
			getline(fin, line[i]);
			if (line[i] != "") {
				year[i] = line[i].substr(6, 4);
				year_i[i] = atoi(year[i].c_str());
				month[i] = line[i].substr(3, 2);
				month_i[i] = atoi(month[i].c_str());
				day[i] = line[i].substr(0, 2);
				day_i[i] = atoi(day[i].c_str());;
				date[i] = year_i[i] * 365 + month_i[i] * 30 + day_i[i];
				counter++;
			}
		}

		int temp_d;
		string temp_ly;


		for (int i = 0; i < counter - 1; i++) {
			for (int j = 0; j < (counter - i - 1); j++) {
				if (date[j] > date[j + 1]) {
					temp_d = date[j];
					date[j] = date[j + 1];
					date[j + 1] = temp_d;
					temp_ly = line[j];
					line[j] = line[j + 1];
					line[j + 1] = temp_ly;
				}
			}
		}
		fin.close();
		for (int i = 0; i < counter; i++) {
			cout << line[i] << endl;
		}
		cout << "If you want to delete a task, click 3" << endl;
		cin >> action;
		if (action == 3) {
			int del;
			cout << "Enter the task number: ";
			cin >> del;
			line[del - 1] = "";
			ofstream fout("tasks.txt", ios_base::trunc);
			for (int i = 0; i < counter; i++) {
				if (line[i] != "") {
					fout << line[i] << endl;
					cout << line[i] << endl;
				}

			}
			fout.close();
		}
	}

}
