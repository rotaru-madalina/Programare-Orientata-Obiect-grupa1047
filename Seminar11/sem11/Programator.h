#pragma once
#include "Persoana.h"
class Programator :
    public Persoana
{
public:
    string limbajProgramare;

    Programator(int varsta, string nume, char* telefon, string limbajProgramare);
};
