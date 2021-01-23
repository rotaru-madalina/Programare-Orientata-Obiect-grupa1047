#pragma once

#include "Persoana.h"

class Companie
{
public:
	string denumire;
	Persoana** angajati;
	int nrAngajati;

	Companie(string denumire, Persoana** angajati, int nrAngajati);

	Companie(const Companie& c);

	~Companie();

	void adaugareAngajat(Persoana* p);

	friend ostream& operator<<(ostream& iesire, Companie& c);
};

