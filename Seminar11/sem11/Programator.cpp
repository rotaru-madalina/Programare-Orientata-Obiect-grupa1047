#include "Programator.h"

Programator::Programator(int varsta, string nume, char* telefon, string limbajProgramare)
	:Persoana(varsta, nume, telefon)
{
	this->limbajProgramare = limbajProgramare;
}
