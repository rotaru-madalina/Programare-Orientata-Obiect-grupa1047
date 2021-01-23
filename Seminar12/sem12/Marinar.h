#pragma once
#include "Persoana.h"
class Marinar :
	public Persoana
{
public:
	int orePeMare;

	Marinar(int varsta, string nume, const char* telefon, int orePeMare, double salariu);

	double calculeazaSalariuDupaMarireProcentuala(double procent);
};

