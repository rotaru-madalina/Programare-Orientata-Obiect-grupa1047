#include<iostream>

using namespace std;

class Animal {
	char* nume;
	string culoare;
	int varsta;

public:
	Animal();

	Animal(const char* nume, string culoare, int varsta) {
		this->nume = new char[strlen(nume) + 1];
		strcpy_s(this->nume, strlen(nume) + 1, nume);

		this->culoare = culoare;

		this->varsta = varsta;
	}

	Animal(const Animal& animal) {
		this->nume = new char[strlen(animal.nume) + 1];
		strcpy_s(this->nume, strlen(animal.nume) + 1, animal.nume);

		this->culoare = animal.culoare;

		this->varsta = animal.varsta;
	}

	~Animal() {
		cout << "Destr" << endl;
		if (this->nume != nullptr) {
			delete[] this->nume;
		}
	}

	friend void afisare(Animal a);

	//operatori
	//op. unari
	//op ++ -- pre-incrementare
	const Animal operator++() {
		this->varsta++;

		return *this;
	}

	//op ++ -- post-incrementare
	const Animal operator++(int) {
		Animal aux(*this);

		this->varsta++;

		return aux;
	}

	//op. binari

	//op. +
	int operator+(int x) {
		return this->varsta + x;
	}

	//op. + 
	Animal& operator+(Animal& animal) {
		Animal *aux = new Animal(*this);
		aux->culoare = aux->culoare + " si " + animal.culoare;

		return *aux;
	}

	//op +
	friend int operator+(int x, Animal animal);


	//op += 
	void operator+=(int x) {
		this->varsta += x;
	}

	//op <<
	friend ostream& operator<<(ostream& out, Animal a);

	//op >>
	friend istream& operator>>(istream& in, Animal& a);

	//op egal
	Animal& operator=(const Animal& animal) {
		if (this != &animal) {
			delete[] nume;

			this->nume = new char[strlen(animal.nume) + 1];
			strcpy_s(this->nume, strlen(animal.nume) + 1, animal.nume);

			this->culoare = animal.culoare;

			this->varsta = animal.varsta;
		}

		return *this;
	}


};

int operator+(int x, Animal animal) {
	return x + animal.varsta;
}

//op <<
ostream& operator<<(ostream& out, Animal a) {
	out << "Nume:" << a.nume << " culoare: " << a.nume << " varsta: " << a.varsta << endl << endl;

	return out;
}

//op >>
istream& operator>>(istream& in, Animal& a) {
	char aux[100];
	cout << "nume: "; in >> aux;

	delete[] a.nume;
	a.nume = new char[strlen(aux) + 1];
	strcpy_s(a.nume, strlen(aux) + 1, aux);

	cout << "culoare: "; in >> a.culoare;
	cout << "varsta: "; in >> a.varsta;

	return in;
}


//op. de rezolutie
Animal::Animal() {
	this->nume = new char[strlen("Anonim") + 1];
	strcpy_s(this->nume, strlen("Anonim") + 1, "Anonim");
}

void afisare() {
	cout << "afisare()" << endl; //c=a+b;
}

void afisare(int a) {
	cout << "afisare(int a) " << a << endl;
}

void afisare(const char* b) {
	cout << "afisare(const char *b) " << b << endl;
}

void afisare(int a, double b) {
	cout << "afisare(int a, double b) " << a << " " << b << endl;
}

void afisare(double a, double b) {
	cout << "afisare(double a, double b) " << a << " " << b << endl;
}

void afisare(Animal a) {
	cout << "afisare(Animal a) -> nume:" << a.nume << " culoare: " << a.nume << " varsta: " << a.varsta << endl;
}

int main() {
	afisare();
	afisare(3);
	afisare(13.4, 44.4);
	afisare("sasaawdefcw");
	afisare(4, 21.3);

	cout << endl << endl;
	Animal a1("Animal1", "negru", 10);
	Animal a2(a1);
	afisare(a2);//daca nu avem constr. de copiere se va crea unul de catre compilator si se va face shallow-copy
	//ceea ce va declansa mai tarziu o eroare de runtime la dezalocare;

	cout << "Operatori" << endl;
	afisare(++a1);
	afisare(a1++);
	afisare(a1);


	Animal a3(a1), a4;
	//cin >> a4;
	cout << a4 << endl;

	cout << "a3: " << a3 << endl;
	cout << a3 + 2 << endl;

	cout << "a3: " << a3 << endl;
	cout << 2 + a3 << endl;
	
	Animal a5("Animal5", "verde", 7);
	cout << a3 + a5 << endl;

	a4 += 19;

	cout << a4;
}
