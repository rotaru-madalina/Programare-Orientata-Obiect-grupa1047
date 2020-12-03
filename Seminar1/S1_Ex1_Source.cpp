#include<iostream>

using namespace std;

typedef struct {
	int varsta;
	bool gen;//0 pt F, 1 pt B
	char nume[100];
	double greutate;
}persoana;

void fct1(int a, int b) {
	cout << "FCT1:    refa=" << &a << " refb=" << &b << endl;

	a = 1829;
	b = 837;
}

void fct2(int &a, int &b) {
	cout << "FCT2:    refa=" << &a << " refb=" << &b << endl;

	a = 1009;
	b = 117;
}

int main() {
	cout << "Asta este o afisare" << endl << "\n";

	//int x;
	//cout << "x = "; cin >> x;
	//cout << "x=" << x << endl;

	persoana p;
	strcpy_s(p.nume, "Popescu Ioana");
	p.greutate = 61.5;
	p.varsta = 21;
	p.gen = false;//echivalent cu p.gen=0;

	cout << "Persoana p are numele: " << p.nume << " varsta: " << p.varsta << " greutatea " << p.greutate << " gen"
		<< ((p.gen == false) ? " Femeie" : "Barbat") << endl;

	int vector[] = { 2,23,41,29 };
	for (int i = 0; i < 4; i++) {
		cout << "vector[" << i << "]=" << vector[i] << " ";
	}

	cout << endl;

	int a = 0, b = 0; 
	fct1(a, b);
	cout << "a=" << a << " b=" << b;
	cout << endl;

	cout << "refa=" << &a << " refb=" << &b << endl;
	fct2(a, b);
	cout << "a=" << a << " b=" << b;
}