#pragma once
#include<iostream>
#include<fstream>
#include<string>

#include "InterfataCalcule.h"

using namespace std;

class Persoana : InterfataCalcule
{
public:
	int varsta;
	string nume;
	char* telefon;
	double salariu;

	Persoana();

	Persoana(int varsta, string nume, const char* telefon, double salariu);

	Persoana(const Persoana& p);

	Persoana& operator=(const Persoana& p);

	~Persoana();

	friend ostream& operator<<(ostream& iesire, Persoana& p);

	friend ofstream& operator<<(ofstream& iesire, Persoana& p);

	friend ifstream& operator>>(ifstream& citire, Persoana& p);

	void scrieInFisierBinar(ofstream& iesire);

	void citireDinFisierBinar(ifstream& citire);

	double calculeazaSalariuDupaMarireProcentuala(double procent);
};

