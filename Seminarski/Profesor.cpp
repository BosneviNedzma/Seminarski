#include "Profesor.h"
#include <iostream>
using namespace std;

int Profesor::getId() const {
	return id;
}

void Profesor::setId(int id) {
	Profesor::id = id;
}

const string& Profesor::getZvanje() const {
	return zvanje;
}

void Profesor::setZvanje(const string& zvanje) {
	Profesor::zvanje = zvanje;
}

ostream& operator<<(ostream& out, const Profesor& p) {
	p.ispisOsobe(out);
	return out << p.id << "->" << p.zvanje << endl;
}

istream& operator>>(istream& in, Profesor& p) {
	p.unosOsobe(in);

	int pom;
	cout << "Unesite ID profesora: ";
	in >> pom;
	p.setId(pom);
	in.ignore();

	string buf;
	cout << "Unesite zvanje profesora: ";
	getline(in, buf);
	p.setZvanje(buf);

	return in;
}