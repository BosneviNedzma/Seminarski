#pragma once
#include <string>
using namespace std;

struct Seminarski {
	int studentIndeks, profesorId;
	string naziv;

	friend istream& operator>>(istream& in, Seminarski& s);
};