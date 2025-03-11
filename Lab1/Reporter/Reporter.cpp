#include <conio.h>
#include <windows.h>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include "employer.h"
using namespace std;

class Reporter
{
public:
	Reporter(string name, double s)
	{
		inF = new ifstream(name, ios::binary);
		sal = s;
	}

	~Reporter()
	{
		inF->close();
	}

	void writeOnFile(string name)
	{
		ofstream out(name);
		for (auto line : lines) {
			out << line << endl;
		}

		out.close();
	}

	void Reporter::getFromFile()
	{

		while (!inF->eof())
		{
			employee emp;
			inF->read(reinterpret_cast<char*>(&emp), sizeof(emp));
			string strh = to_string(emp.hours);
			string strs = to_string(double(sal) * emp.hours);
			if (!inF->eof()) {
				lines.push_back("Employee number " + to_string(emp.num) + ": " + emp.name +
					" work for " + strh + " hours and get " + strs);
			}
		}
	}

private:
	vector<string> lines;
	ifstream* inF;
	double sal;
};



int main(int argc, char* argv[]) {
	if (argc != 4) {
		_cputs("Invalid arguments");
		_getch();
		return 1;
	}
	Reporter* r = new Reporter(argv[1], atof(argv[3]));
	
	r->getFromFile();
	r->writeOnFile(argv[2]);

	cout << "Report created";
	_getch();
	return 0;
}