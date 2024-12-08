#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
using namespace std;
int main() {
	string name;
	float mt1, mt2,final, avg;
	ifstream fin; //Create file input stream object
	ofstream fout; // Create file output stream object
	fin.open("C:/Users/Ahmad/source/repos/DSA Lab 1/input.dat"); //Open input file
	fout.open("C:/Users/Ahmad/source/repos/DSA Lab 1/output.dat"); //Open output file
	if (!fin) {
		cout << "Error opening input file" << endl;
		return 1;
	}
	if (!fout) {
		cout << "Error opening output file" << endl;
		return 1;
	}
	fout << "Name" << setw(15) << "MT1" << setw(15) << "MT2" << setw(15) << "Final" << setw(15) << "Average" << endl;
	while (fin >> name >> mt1 >> mt2 >> final) {
		avg = 0.25 * mt1 + 0.25 * mt2 + 0.5 * final;
		fout <<  name << setw(15) << mt1 << setw(15) << mt2 << setw(15) << final << setw(15) << avg << endl;
	}
	fin.close(); //Close input file
	fout.close(); //Close output file
	cout << "Data saved successfully" << endl;
	return 0;
}