#pragma once
#include "Persoana.h"
class Programator :
    public Persoana
{
public:
    string limbajProgramare;

    Programator(int varsta, string nume, const char* telefon, string limbajProgramare, double salariu);

    double calculeazaSalariuDupaMarireProcentuala(double procent);
};

