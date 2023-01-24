#include "Student.h"
#include <iostream>

int Student::getBrIndeksa() const {
	return brIndeksa;
}

void Student::setBrIndeksa(int brIndeksa) {
	Student::brIndeksa = brIndeksa;
}

int Student::getGodinaStudija() const {
	return godinaStudija;
}

void Student::setGodinaStudija(int godinaStudija) {
	Student::godinaStudija = godinaStudija;
}

const string& Student::getFakultet() const {
	return fakultet;
}
void Student::setFakultet(const string& fakultet) {
	Student::fakultet = fakultet;
}

ostream& operator<<(ostream& out, const Student& s) {
	s.ispisOsobe(out);
	return out << s.brIndeksa << "/" << s.godinaStudija << ". godina studija - " << s.fakultet << endl;
}

istream& operator>>(istream& in, Student& s) {
	s.unosOsobe(in);

	int pom;
	cout << "Unesite broj indeksa studenta: ";
	in >> pom;
	s.setBrIndeksa(pom);

	cout << "Unesite godinu studija studenta: ";
	in >> pom;
	s.setGodinaStudija(pom);
	in.ignore();

	string buf;
	cout << "Unesite naziv fakulteta: ";
	getline(in, buf);
	s.setFakultet(buf);

	return in;
}