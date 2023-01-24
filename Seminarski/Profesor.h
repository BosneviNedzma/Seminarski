#pragma once
#include "Osoba.h"
struct Profesor :public Osoba {
	int id;
	string zvanje;
	int getId() const;
	void setId(int id);
	const string& getZvanje() const;
	void setZvanje(const string& zvanje);

	friend ostream& operator<<(ostream& out < const Profesor& p);
	friend istream& operator>>(istream& in, Profesor& p);
};