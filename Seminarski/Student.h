#pragma once
#include "Osoba.h"
using namespace std;

struct Student :public Osoba {
	int brIndeksa, godinaStudija;
	string fakultet;

	int getBrIndeksa() const;
	void setBrIndeksa(int brIndeksa);

	int getGodinaStudija() const;
	void setGodinaStudija(int godinaStudija);

	const string& getFakultet() const;
	void setFakultet(const string& fakultet);

	friend ostream& operator<<(ostream& out, const Student& o);
	friend istream& operator>>(istream& in, Student& o);
};
