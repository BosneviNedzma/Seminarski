#include "Osoba.h"
#include <iostream>

const string& Osoba::getJmbg() const {
	return JMBG;
}

void Osoba::setJmbg(const string& jmbg) {
	JMBG = jmbg;
}

const string& Osoba::getIme() const {
	return ime;
}

void Osoba::setIme(const string& _ime) {
	ime = _ime;
}

const string& Osoba::getPrezime() const {
	return prezime;
}

void Osoba::setPrezime(const string& _prezime) {
	prezime = _prezime;
}

int Osoba::getBrGodina() const {
	return brGodina;
}

void Osoba::setBrGodina(int _brGodina) {
	brGodina = _brGodina;
}

ostream& operator<<(ostream& out, const Osoba& o) {
	return out << o.ime << " " << o.prezime << " (ime " << o.brGodina << " godina), JMBG - " << o.JMBG << endl;
}

istream& operator>>(istream& in, Osoba& o) {
	string buf;
	cout << "Unesite ime osobe: ";
	getline(in, buf);
	o.setIme(buf);
	cout << "Unesite prezime osobe: ";
	getline(in, buf);
	o.setPrezime(buf);
	cout << "Unesite maticni broj osobe: ";
	getline(in, buf);
	o.setJmbg(buf);
	cout << "Unesite broj godina osobe: ";
	int pom;
	in >> pom;
	o.setBrGodina(pom);
	return in;
}