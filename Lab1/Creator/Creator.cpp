#include <conio.h>
#include <windows.h>
#include <fstream>
#include <iostream>
#include <string>
#include "employer.h"

using namespace std;

class Creator {
public:
	Creator(string fn) : fileName(fn) {
		outF = new ofstream(fileName, ios::binary);
	}

	void writeEmpl(int num, string name, double hours) {
		employee emp;
		emp.num = num;
		strncpy_s(emp.name, name.c_str(), sizeof(emp.name) - 1);
		emp.hours = hours;
		outF->write(reinterpret_cast<char*>(&emp), sizeof(emp));
	}

	~Creator() {
		outF->close();
	}
private:
	string fileName;
	ofstream* outF;
};



int main(int argc, char* argv[]) {
	_cputs("Hello, i'm creater.\n");

	if (argc != 3) {
		_cputs("Invalid arguments");
		_getch();
		return 1;
	}

	Creator *cr = new Creator(string(argv[1]));
	int number = atoi(argv[2]);
	
	for (int i = 0; i < number; i++) {
		string name;
		double hours;

		cout << "Employee with id " + to_string(i + 1) + ": \n";
		cout << "Enter name: ";
		cin >> name;
		cout << "Enter hours: ";
		cin >> hours;
		
		cr->writeEmpl(i + 1, name, hours);
	}

	cout << "All entered";
	_getch();
	return 0;
}