#include "Marinar.h"

Marinar::Marinar(int varsta, string nume, const char* telefon, int orePeMare, double salariu)
	:Persoana(varsta, nume, telefon, salariu)
{
	this->orePeMare = orePeMare;
}

double Marinar::calculeazaSalariuDupaMarireProcentuala(double procent)
{
	salariu += salariu * procent / 100 + 400;
	return salariu;
}
