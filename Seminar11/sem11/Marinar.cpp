#include "Marinar.h"

Marinar::Marinar(int varsta, string nume, char* telefon, int orePeMare)
	:Persoana(varsta, nume, telefon)
{
	this->orePeMare = orePeMare;
}
