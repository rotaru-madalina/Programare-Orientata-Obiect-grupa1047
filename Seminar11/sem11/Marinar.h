#pragma once
#include "Persoana.h"
class Marinar :
    public Persoana
{
public:
    int orePeMare;

    Marinar(int varsta, string nume, char* telefon, int orePeMare);
};
