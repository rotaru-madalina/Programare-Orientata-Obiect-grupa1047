#pragma once
#include<iostream>
#include<fstream>

#include<string>
using namespace std;
class Persoana
{
public:
	int varsta;
	string nume;
	char* telefon;

	Persoana();

	Persoana(int varsta, string nume, const char* telefon);

	Persoana(const Persoana& p);

	Persoana& operator=(const Persoana& p);

	~Persoana();

	friend ostream& operator<<(ostream& iesire, Persoana& p);

	friend ofstream& operator<<(ofstream& iesire, Persoana& p);

	friend ifstream& operator>>(ifstream& citire, Persoana& p);

	void scrieInFisierBinar(ofstream& iesire);

	void citireDinFisierBinar(ifstream& citire);
};
