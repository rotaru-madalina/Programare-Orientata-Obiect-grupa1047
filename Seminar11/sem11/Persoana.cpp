#include "Persoana.h"

Persoana::Persoana()
{
	this->varsta = 0;
	this->nume = "default name value";

	this->telefon = new char[strlen("Anonim") + 1];
	strcpy_s(this->telefon, strlen("Anonim") + 1, "Anonim");
}

Persoana::Persoana(int varsta, string nume, const char* telefon)
{
	this->varsta = varsta;
	this->nume = nume;
	this->telefon = new char[strlen(telefon) + 1];
	strcpy_s(this->telefon, strlen(telefon) + 1, telefon);
}

Persoana::Persoana(const Persoana& p)
{
	this->varsta = p.varsta;
	this->nume = p.nume;
	this->telefon = new char[strlen(p.telefon) + 1];
	strcpy_s(this->telefon, strlen(p.telefon) + 1, p.telefon);
}

Persoana& Persoana::operator=(const Persoana& p)
{
	if (this != &p) {
		if (this->telefon != nullptr) {
			delete[] telefon;
		}

		this->varsta = p.varsta;
		this->nume = p.nume;
		this->telefon = new char[strlen(p.telefon) + 1];
		strcpy_s(this->telefon, strlen(p.telefon) + 1, p.telefon);
	}
	return *this;
}

Persoana::~Persoana()
{
	if (this->telefon != nullptr) {
		delete[] telefon;
	}
}

//Cum se scrie de fapt in fis binar.
//14
//popescu ionel
//33
//13
//0764 433 321
void Persoana::scrieInFisierBinar(ofstream& iesire)
{
	//pentru string si char* trebuie sa scrie intai dimensiunea sirului de caract. + 1 (pt '\0') pt ca
	//avem nevoie de dimensiune la citire

	int dim1 = nume.size() + 1; //+1 - pt '\0'
	iesire.write((char*)&dim1, sizeof(dim1));
	iesire.write(nume.c_str(), dim1);

	iesire.write((char*)&varsta, sizeof(varsta)); //DE LA ce adresa se citesc 4 bytes pt a scrie in fisierul binar

	int dim2 = strlen(telefon) + 1; //+1 - pt '\0'
	iesire.write((char*)&dim2, sizeof(dim2));
	iesire.write(telefon, dim2);
}

void Persoana::citireDinFisierBinar(ifstream& citire)
{
	int dim1 = 0;
	citire.read((char*)&dim1, sizeof(dim1));
	char aux1[100];
	citire.read(aux1, dim1);
	nume = aux1;

	citire.read((char*)&varsta, sizeof(varsta)); //LA CE adresa sa se scrie din fisier 4 bytes

	int dim2 = 0;
	citire.read((char*)&dim2, sizeof(dim2));
	char aux2[100];
	citire.read(aux2, dim2);

	if (telefon != nullptr) {
		delete[] telefon;
	}
	telefon = new char[dim2];
	strcpy_s(telefon, dim2, aux2);
}

ostream& operator<<(ostream& iesire, Persoana& p)
{
	iesire << "Nume: " << p.nume << " varsta: " << p.varsta << " telefon: " << p.telefon << endl;
	return iesire;
}

ofstream& operator<<(ofstream& iesire, Persoana& p)
{
	iesire << p.nume << endl << p.varsta << endl << p.telefon << endl;
	return iesire;
}

ifstream& operator>>(ifstream& citire, Persoana& p)
{
	getline(citire, p.nume); //din libraria string

	citire >> p.varsta;

	citire.ignore();

	char aux[100];
	citire.getline(aux, 100);//din libraria istream

	if (p.telefon != nullptr) {
		delete[] p.telefon;
	}
	p.telefon = new char[strlen(aux) + 1];
	strcpy_s(p.telefon, strlen(aux) + 1, aux);

	return citire;
}
