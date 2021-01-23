#include "Programator.h"

Programator::Programator(int varsta, string nume, const char* telefon, string limbajProgramare, double salariu)
	:Persoana(varsta, nume, telefon, salariu)
{
	this->limbajProgramare = limbajProgramare;
}

double Programator::calculeazaSalariuDupaMarireProcentuala(double procent)
{
	salariu += salariu * procent / 100 + 500;
	return salariu;
}
