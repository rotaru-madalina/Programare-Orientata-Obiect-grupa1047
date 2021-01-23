#include<iostream>
#include<fstream>

#include "Persoana.h"
#include "Marinar.h"
#include "Programator.h"

using namespace std;

int main() {
	Persoana p1(33, "Popescu Ionel", "0743 221 231");

	ofstream fisTextOut("aaaa.txt");
	if (fisTextOut.is_open()) {
		//op << pt fisiere
		fisTextOut << p1;

		fisTextOut.close();
	}
	else {
		cout << "Fisierul aaaa.txt nu poate fi deschis pentru scriere.\n";
	}

	//op << pt scriere la tastatura
	cout << "p1:   " << p1 << endl;

	Persoana p2;
	ifstream fisTextIn("aaaa.txt");
	if (fisTextIn.is_open()) {
		fisTextIn >> p2;
		cout << "p2 fisier text:   " << p2 << endl;

		fisTextIn.close();
	}
	else {
		cout << "Fisierul aaaa.txt nu poate fi deschis pentru citire.\n";
	}

	//fisiere
	//flag-uri
	//ios::app - adauga informatii la un fisier existent
	//ios::nocreate - deschide fisierul daca exista deja.
	//ios::in - pt citire dintr-un fisier
	//ios::out - scriere intr-un fisier
	//ios::truc - sterge tot din fisier inainte sa scrii in el 
	//ios::noreplace - doar pt a crea un nou fisier
	//ios::ate - deschide fisierul si merge la sfarsitul lui - fol pt adaugare info la final
	//ios::binary - fisierul deschis va contine doar informatii binare

	ofstream fisBinarOut("wwww.bin", ios::out | ios::binary | ios::app);
	if (fisBinarOut.is_open()) {
		p2.scrieInFisierBinar(fisBinarOut);

		fisBinarOut.close();
	}
	else {
		cout << "Fisierul wwww.dat nu poate fi deschis pentru scriere.\n";
	}

	Persoana p3;
	ifstream fisBinarIn("wwww.bin", ios::in | ios::binary);
	if (fisBinarIn.is_open()) {
		p3.citireDinFisierBinar(fisBinarIn);
		cout << "p3 fisier binar:   " << p3 << " ";
		fisBinarIn.close();
	}
	else {
		cout << "Fisierul wwww.dat nu poate fi deschis pentru citire.\n";
	}
}
