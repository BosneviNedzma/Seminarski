#pragma once
#include <string>
using namespace std;

class Osoba {
	string JMBG;
public:
	string ime, prezime;
	int brGodina;
	const string& getJmbg() const;
	void setJmbg(const string& jmbg);
	const string& getIme() const;
	void setIme(const string& ime);
	const string& getPrezime() const;
	void setPrezime(const string& prezime);
	int getBrGodina() const;
	void setBrGodina(int brGodina);

	inline void unosOsobe(istream& in) {
		in >> *this;
	}
	inline void ispisOsobe(ostream& out) const {
		out << *this;
	}

	friend ostream& operator<<(ostream& out, const Osoba& o);
	friend istream& operator>>(istream& in, Osoba& o);
};