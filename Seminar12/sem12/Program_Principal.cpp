//CLASE - STL
//• reprezinta o librarie de clase template standard(standard template library)
//• acopera principalele structuri de date : vector, lista, stiva, coada, tabela de dispersie(hash - table);
//• pot fi utilizate fara alte modificari pentru tipuri fundamentale sau definite de programator.

//STL=Containere + ITERATORI + ALGORITMI

//Containere: 
//• un obiect ce stocheaza alte obiecte si are metode pentru a le accesa;

//TIP CONTAINERE
//• secventiale : 
		//• vector;
		//• list;
		//• deque; 
//• asociative(valoare – cheie) :
		//• set(multime de chei unice, sortate)
		//• multiset(multime de chei, sortate)
		//• map(multime valori - chei unice, sortate)
		//• multimap(multime valori - chei sortate)
//• adaptive :
		//• stack 
		//• queue
		//• priority_queue


//ITERATORI
	//• forma generalizata a pointerilor; 
	//• utilizati pentru a itera prin elementele containerelor
	//• se comporta ca interfata intre containere si algoritmi
	//• iteratori predefiniti :
			//• ostream_iterator; 
			//• istream_iterator;
			//• reverse_iterator; 
			//• insert_iterator;

//ALGORITMI
	//• functii generice independente de tipul containerului; 
	//• utilizate pentru a prelucra elementele containerelor
	//• folosesc iteratori pentru acces la elemente
	//• functii importante : 
		//• copy;
		//• for_each;
		//• sort;
		//• find;
		//• transform

////Mai multe exemple: https://www.sanfoundry.com/cpp-programming-examples-stl/


//pt containerul vector trebuie sa adaugi #include <vector> 
//pt containerul list trebuie sa adaugi #include <list> 
//pt containerul map trebuie sa adaugi #include <map> 
//la fel si pt alte containere...

#include<iostream>
#include<fstream>

#include<vector>
#include<list>
#include<map>

#include "Persoana.h"
#include "Marinar.h"
#include "Programator.h"
#include "Companie.h"

using namespace std;

int main() {
	Persoana p1(33, "Popescu Ionel", "0743 221 231", 3000);

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

	ofstream fisBinarOut("wwww.bin", ios::out | ios::binary);
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


	Marinar* pm1 = new Marinar(44, "Baciu Vasile", "0767 222 212", 4300, 6000);

	Programator* pprog1 = new Programator(30, "Popa Alin", "0782 111 333", "Java", 10000);

	Persoana* pp1 = new Persoana(24, "Baciu Vasile", "0766 444 666", 2400);

	//STL
	cout << "\nvector STL\n";

	vector<Persoana*> vectorPersoane;
	vectorPersoane.push_back(pp1);
	vectorPersoane.push_back(pm1);
	vectorPersoane.push_back(pprog1);
	for (int i = 0; i < vectorPersoane.size(); i++) {
		cout << *vectorPersoane[i];
		vectorPersoane[i]->calculeazaSalariuDupaMarireProcentuala(10);
	}

	//vectorPersoane.pop_back(); //sterge ultima val din vector

	cout << "\nIterator vector\n";
	vector<Persoana*>::iterator iteratorVectorPersoane;

	for (iteratorVectorPersoane = vectorPersoane.begin(); iteratorVectorPersoane != vectorPersoane.end(); iteratorVectorPersoane++) {
		cout << *(*iteratorVectorPersoane); //iteratorVectorPersoane -> pointer ce va contine adresa catre pointerul vectorPersoane[0],....
	}


	//lista
	cout << "\nlista STL\n";
	list<Persoana*> listaPersoane;
	list<Persoana*>::iterator iteratorListaPersoane;

	listaPersoane.push_back(pp1);	
	listaPersoane.push_back(pm1);
	listaPersoane.push_front(pprog1);
	for (iteratorListaPersoane = listaPersoane.begin(); iteratorListaPersoane != listaPersoane.end(); iteratorListaPersoane++) {
		cout << *(*iteratorListaPersoane);
	}

	//map
	cout << "\nmap STL\n";

	map<int, Persoana*> mapPersoane;
	map<int, Persoana*>::iterator iteratorMapPersoane;

	mapPersoane.insert(pair<int, Persoana*>(100, pm1));
	mapPersoane.insert(pair<int, Persoana*>(200, pp1));
	mapPersoane.insert(pair<int, Persoana*>(310, pprog1));

	for (iteratorMapPersoane = mapPersoane.begin(); iteratorMapPersoane != mapPersoane.end(); iteratorMapPersoane++) {
		cout << "La cheia: " << (*iteratorMapPersoane).first << " se afla valoarea: " << *(*iteratorMapPersoane).second;
	}

	//dimensiunea lui mapPersoane
	cout << "dimensiunea lui mapPersoane: " << mapPersoane.size() << endl;
	cout << "La cheia 200 se afla valoarea " << *mapPersoane.find(200)->second << endl;

	//vector dinamic de pointeri
	cout << endl;
	Persoana** vectorDePersoane = new Persoana * [3]{ pp1,pm1,pprog1 };
	Companie c("Rares SRL", vectorDePersoane, 3);
	cout << c << endl;

	Persoana* pp2 = new Persoana(40, "Ioana Popescu", "0783 222 555", 4000);
	c.adaugareAngajat(pp2);

	cout << c << endl;
	for (int i = 0; i < c.nrAngajati; i++) {
		c.angajati[i]->calculeazaSalariuDupaMarireProcentuala(20);
	}
	cout << c << endl;
}