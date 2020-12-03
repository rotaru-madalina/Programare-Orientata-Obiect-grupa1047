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

	Vehicul() {
		this->serie = new char[strlen("NJK29821032") + 1];
		strncpy(this->serie, "NJK29821032", strlen("NJK29821032") + 1);
	}

	Vehicul(int nrKm, int anFabricatie) {
		this->nrKm = nrKm;
		this->anFabricatie = anFabricatie;

		this->serie = new char[strlen("NJK29821032") + 1];
		strncpy(this->serie, "NJK29821032", strlen("NJK29821032") + 1);
	}

	Vehicul(string culoare, int nrKm, int anFabricatie, const char* serie) {
		this->culoare = culoare;
		this->nrKm = nrKm;
		this->anFabricatie = anFabricatie;

		this->serie = new char[strlen(serie) + 1];
		strncpy(this->serie, serie, strlen(serie) + 1);
	}

	Vehicul(const Vehicul& v) {
		this->culoare = v.culoare;
		this->nrKm = v.nrKm;
		this->anFabricatie = v.anFabricatie;

		this->serie = new char[strlen(v.serie) + 1];
		strncpy(this->serie, v.serie, strlen(v.serie) + 1);
	}

	friend ostream& operator<<(ostream& out, Vehicul v);

	Vehicul& operator=(const Vehicul& v)
	{
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

	bool operator==(Vehicul vehicul) {
		if (this == &vehicul) {
			return true;
		}

		return this->culoare == vehicul.culoare &&
			this->nrKm == vehicul.nrKm &&
			this->anFabricatie == vehicul.anFabricatie &&
			strcmp(this->serie, vehicul.serie) == 0;
	}

	~Vehicul() {
		if (serie != nullptr)
			delete[] this->serie;
	}
};

// Motocicleta "is a" Vehicul
class Motocicleta :public Vehicul {
public:
	static int randomNr;
	const int ID;
	bool areSa;

	Motocicleta() :Vehicul(200000, 2014), ID(100) {
		this->areSa = false;
	}

	Motocicleta(string culoare, int nrKm, int anFabricatie, const char* serie, bool areSa)
		:Vehicul(culoare, nrKm, anFabricatie, serie), ID(randomNr++) {
		this->areSa = areSa;
	}

	Motocicleta(const Motocicleta& m) :Vehicul(m), ID(m.ID) {
		this->areSa = m.areSa;
	}

	Motocicleta& operator=(Motocicleta& m) {
		if (this != &m) {
			Vehicul::operator=(m);

			this->areSa = m.areSa;
		}

		return *this;
	}

	bool operator==(Motocicleta motocicleta) {
		return this->areSa == motocicleta.areSa &&
			Vehicul::operator==(motocicleta);
	}

	~Motocicleta() {
	}

	void fct2() {
		this->nrKm;
		this->serie;
	}

	friend ostream& operator<<(ostream& out, Motocicleta m);
};
int Motocicleta::randomNr = 1000;

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
	out << "Are sa: " << m.areSa << endl;
	out << "ID: " << m.ID << endl;

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
class ReprezentantaDeMotociclete {
	string denumire;
	Motocicleta* motociclete;
	int nrMotociclete;

public:
	ReprezentantaDeMotociclete(string denumire, Motocicleta* motociclete, int nrMotociclete) {
		this->denumire = denumire;

		this->nrMotociclete = nrMotociclete;

		this->motociclete = new Motocicleta[nrMotociclete];
		for (int i = 0; i < nrMotociclete; i++) {
			this->motociclete[i] = motociclete[i];
		}
	}

	ReprezentantaDeMotociclete(const ReprezentantaDeMotociclete& reprezentanta) {
		this->denumire = reprezentanta.denumire;

		this->nrMotociclete = reprezentanta.nrMotociclete;

		this->motociclete = new Motocicleta[reprezentanta.nrMotociclete];
		for (int i = 0; i < reprezentanta.nrMotociclete; i++) {
			this->motociclete[i] = reprezentanta.motociclete[i];
		}
	}

	~ReprezentantaDeMotociclete() {
		if (this->motociclete != nullptr) {
			delete[] this->motociclete;
		}
	}

	ReprezentantaDeMotociclete& operator=(const ReprezentantaDeMotociclete& reprezentanta) {
		if (this != &reprezentanta) {
			if (this->motociclete != nullptr) {
				delete[] this->motociclete;
			}

			this->denumire = reprezentanta.denumire;

			this->nrMotociclete = reprezentanta.nrMotociclete;


			this->motociclete = new Motocicleta[reprezentanta.nrMotociclete];
			for (int i = 0; i < reprezentanta.nrMotociclete; i++) {
				this->motociclete[i] = reprezentanta.motociclete[i];
			}
		}
		return *this;
	}


	int getNrMotociclete() {
		return this->nrMotociclete;
	}

	Motocicleta& operator[](int index) {
		if (index >= 0 && index < nrMotociclete) {
			return this->motociclete[index];
		}
		else {
			throw new exception("Eroare: Motocicleta& operator[](int index)");
		}
	}

	void adaugareMotociclete(Motocicleta motocicleta) {
		Motocicleta* aux = new Motocicleta[nrMotociclete + 1];

		for (int i = 0; i < nrMotociclete; i++) {
			aux[i] = motociclete[i]; 
		}

		aux[nrMotociclete++] = motocicleta;
		delete[] motociclete;
		motociclete = aux;
	}

	//stergere element si toate aparitiile sale
	void stergereMotocicleta(Motocicleta motocicleta) {
		int nrDuplicate = 0;
		for (int i = 0; i < nrMotociclete; i++) {
			if (motocicleta == motociclete[i])
			{
				nrDuplicate++;
			}
		}

		if (nrDuplicate > 0) {
			for (int i = 0; i < nrMotociclete; i++) {
				if (this->motociclete[i] == motocicleta) {
					for (int j = i; j < nrMotociclete - 1; j++) {
						this->motociclete[j] = motociclete[j + 1];
					}
					nrMotociclete--;
				}
			}

			Motocicleta* aux = new Motocicleta[nrMotociclete];
			for (int i = 0; i < nrMotociclete; i++) {
				aux[i] = motociclete[i];
			}

			delete[] motociclete;
			motociclete = aux;
		}
	}
};

void afisareReprezentanta(ReprezentantaDeMotociclete reprezentanta, int nrMotociclete) {
	for (int i = 0; i < nrMotociclete; i++) {
		cout << reprezentanta[i] << endl;
	}
}
int main() {
	Vehicul aaa("verde", 500000, 2009, "JDHKC21");
	cout << aaa << endl << endl;


	Motocicleta motocicleta1;
	cout << endl;
	Motocicleta motocicleta2("albastru", 350000, 2019, "IHY&06HKC21", true);
	Motocicleta motocicleta3("verde", 130000, 2018, "AAAAAKC21", true);
	cout << endl;

	cout << "motocicleta1\n\n" << motocicleta1 << endl << endl;
	cout << "motocicleta2\n\n" << motocicleta2 << endl << endl;

	//Masina masina();
	//masina.serie; //nu ai acces la datele din parinte pentru ca mostenirea este protected

	//TIR tir;
	//tir.serie; //nu ai acces la datele din parinte pentru ca mostenirea este privata

	//compunere
	cout << "\ncompunere\n";
	Motocicleta motociclete[] = { motocicleta1, motocicleta2 };
	ReprezentantaDeMotociclete reprezentanta1("Moto Sport Rares SRL", motociclete, 2);
	afisareReprezentanta(reprezentanta1, reprezentanta1.getNrMotociclete());

	cout << "\nadaugare\n";
	reprezentanta1.adaugareMotociclete(motocicleta3);
	reprezentanta1.adaugareMotociclete(motocicleta2);
	reprezentanta1.adaugareMotociclete(motocicleta2);
	afisareReprezentanta(reprezentanta1, reprezentanta1.getNrMotociclete());

	cout << "\nstergere\n";
	reprezentanta1.stergereMotocicleta(motocicleta2);
	afisareReprezentanta(reprezentanta1, reprezentanta1.getNrMotociclete());
}
