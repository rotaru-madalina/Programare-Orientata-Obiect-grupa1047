#define _CRT_SECURE_NO_WARNINGS

#include<iostream>

using namespace std;

//mostenire/derivare
class Vehicul {
	string culoare;
protected:
	long nrKm;
	int anFabricatie;
public:
	char* serie; //ex: NJK29821032

	Vehicul(string culoare, int nrKm, int anFabricatie, const char* serie) {
		cout << "Constructor Vehicul\n";

		this->culoare = culoare;
		this->nrKm = nrKm;
		this->anFabricatie = anFabricatie;

		this->serie = new char[strlen(serie) + 1];
		strncpy(this->serie, serie, strlen(serie) + 1);
	}

	Vehicul(const Vehicul& v) {
		cout << "Constructor copiere Vehicul\n";

		this->culoare = v.culoare;
		this->nrKm = v.nrKm;
		this->anFabricatie = v.anFabricatie;

		this->serie = new char[strlen(v.serie) + 1];
		strncpy(this->serie, v.serie, strlen(v.serie) + 1);

	}

	friend ostream& operator<<(ostream& out, Vehicul v);

	Vehicul& operator=(const Vehicul& v)
	{
		cout << "Operator = Vehicul\n";

		if (this != &v)
		{
			delete[] this->serie;

			this->serie = new char[strlen(v.serie) + 1];
			strncpy(this->serie, v.serie, strlen(v.serie) + 1);
			this->culoare = v.culoare;
			this->nrKm = v.nrKm;
			this->anFabricatie = v.anFabricatie;
		}

		return *this;
	}

	~Vehicul() {
		cout << "Destructor Vehicul\n";

		if (serie != nullptr)
			delete[] this->serie;
	}
};

// Motocicleta "is a" Vehicul
class Motocicleta :public Vehicul {
public:
	bool areSa;

	Motocicleta() :Vehicul("Negru", 200000, 2014, "NXIHKI3232") {
		cout << "Constructor Motocicleta()\n";

		this->areSa = false;
	}

	Motocicleta(string culoare, int nrKm, int anFabricatie, const char* serie, bool areSa)
		:Vehicul(culoare, nrKm, anFabricatie, serie) {
		cout << "Constructor Motocicleta\n";
		this->areSa = areSa;
	}

	Motocicleta(const Motocicleta& m) :Vehicul(m) {
		cout << "Constructor copiere Motocicleta\n";

		this->areSa = m.areSa;
	}

	void fct2() {
		this->nrKm;
		this->serie;
	}

	friend ostream& operator<<(ostream& out, Motocicleta m);
};

//(ostream) << Vehicul;
ostream& operator<<(ostream& out, Vehicul v) {
	out << "VEHICUL: \n";
	out << v.serie << " ";
	out << v.culoare << " ";
	out << v.nrKm << " ";
	out << v.anFabricatie << " " << endl;

	return out;
}


//(ostream) << Motocicleta;
ostream& operator<<(ostream& out, Motocicleta m) {
	out << "MOTOCICLETA: \n";

	//POTI trasforma cu copil in parinte(up-casting)
	out << (Vehicul)m;
	out << m.areSa << endl;

	return out;
}

// Masina "is a" Vehicul
class Masina :protected Vehicul {
public:
	bool areVolan;

	void fct1() {
		this->nrKm;
		this->serie;
	}
};


// TIR "is a" Vehicul
class TIR :private Vehicul {
public:
	bool areStatie;

	void fct3() {
		this->nrKm;
		this->serie;
	}
};

// compunere
class RAM {

};

// Calculator "has a" RAM
class Calculator {
	RAM ram;
};

int main() {
	Vehicul aaa("verde", 500000, 2009, "JDHKC21");
	cout << aaa << endl << endl;


	Motocicleta motocicleta;
	Motocicleta motocicleta1("albastru", 350000, 2019, "IHY&06HKC21", true);
	motocicleta.serie;
	cout << motocicleta << endl << endl;
	cout << motocicleta1 << endl << endl;

	//Masina masina();
	//masina.serie; //nu ai acces la datele din parinte pentru ca mostenirea este protected

	//TIR tir;
	//tir.serie; //nu ai acces la datele din parinte pentru ca mostenirea este privata
}
