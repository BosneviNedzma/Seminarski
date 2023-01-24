#include <iostream>
#include "Seminarski.h"
using namespace std;

istream& operator>>(istream& in, Seminarski& s) {
	cout << "Unesite ID profesora: ";
	in >> s.profesorId;
	cout << "Unesite broj indeksa studenta: ";
	in >> s.studentIndeks;
	cout << "Unesite naziv seminarskog rada: ";
	getline(in, s.naziv);

	return in;
}