#include "Companie.h"
Companie::Companie(string denumire, Persoana** angajati, int nrAngajati) {
	this->denumire = denumire;
	this->nrAngajati = nrAngajati;

	this->angajati = new Persoana * [nrAngajati];
	for (int i = 0; i < nrAngajati; i++) {
		this->angajati[i] = angajati[i];
	}
}

Companie::Companie(const Companie& c) {
	this->denumire = c.denumire;
	this->nrAngajati = c.nrAngajati;

	this->angajati = new Persoana * [c.nrAngajati];
	for (int i = 0; i < c.nrAngajati; i++) {
		this->angajati[i] = c.angajati[i];
	}
}

Companie::~Companie() {
	if (this->angajati != nullptr) {
		for (int i = 0; i < this->nrAngajati; i++) {
			delete this->angajati[i];
		}

		delete[] this->angajati;
	}
}


void Companie::adaugareAngajat(Persoana* p) {
	Persoana** aux = new Persoana * [this->nrAngajati + 1];
	for (int i = 0; i < this->nrAngajati; i++) {
		aux[i] = this->angajati[i];
	}

	delete[] this->angajati;

	aux[nrAngajati++] = p;
	this->angajati = aux;
}

ostream& operator<<(ostream& iesire, Companie& c) {
	iesire << "Compania: " << c.denumire << " are " << c.nrAngajati << " angajati. Angajatii sunt: \n";
	for (int i = 0; i < c.nrAngajati; i++) {
		iesire << *c.angajati[i];
	}

	return iesire;
}
