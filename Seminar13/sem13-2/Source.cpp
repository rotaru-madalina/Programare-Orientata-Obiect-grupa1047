//S5 - Procese

#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

class Proces {
private:
	const int idProces;
	static int NUMBER;
	char* denumire;
	bool esteActiv;
	int durata;
	int prioritate;  //1, 2 sau 3;

public:
	Proces() :idProces(NUMBER) {
		this->denumire = nullptr;
		this->esteActiv = false;
		this->durata = 0;
		this->prioritate = 3;
	}

	Proces(const char* denumire, int durata, int prioritate) :idProces(++NUMBER) {
		if (denumire != nullptr) {
			this->denumire = new char[strlen(denumire) + 1];
			strcpy_s(this->denumire, strlen(denumire) + 1, denumire);
		}
		else {
			throw new exception("denumire nu poate fi nullptr.");
		}

		if (durata >= 0) {
			this->durata = durata;
		}
		else {
			throw new exception("durata trebuie sa fie >=0");
		}

		if (prioritate == 1 || prioritate == 2 || prioritate == 3) {
			this->prioritate = prioritate;
		}
		else {
			throw new exception("prioritatea poate avea valoarea 1, 2 sau 3.");
		}

	}

	Proces(const Proces& p) :idProces(p.idProces) {
		if (p.esteActiv == false) {
			if (p.denumire != nullptr) {
				this->denumire = new char[strlen(p.denumire) + 1];
				strcpy_s(this->denumire, strlen(p.denumire) + 1, p.denumire);
			}
			this->prioritate = p.prioritate;
			this->durata = p.durata;
			this->esteActiv = p.esteActiv;
		}
	}

	Proces& operator=(const Proces& p) {
		if (this != &p && this->esteActiv == false) {
			delete[] denumire;

			if (p.denumire != nullptr) {
				this->denumire = new char[strlen(p.denumire) + 1];
				strcpy_s(this->denumire, strlen(p.denumire) + 1, p.denumire);
			}
			this->prioritate = p.prioritate;
			this->durata = p.durata;
			this->esteActiv = p.esteActiv;
		}

		return *this;
	}

	~Proces() {
		if (this->denumire != nullptr) {
			delete[] this->denumire;
		}

		this->esteActiv = false;
	}

	char* getDenumire() {
		return this->denumire;
	}

	bool getEsteActiv() {
		return this->esteActiv;
	}

	void setEsteActiv(bool b) {
		this->esteActiv = b;
	}

	friend ostream& operator<<(ostream& out, const Proces& p) {
		out << "Procesul " << p.denumire << "cu id-ul" << p.idProces << " este " << ((p.esteActiv == 1) ? "activ " : "inactiv ")
			<< " si are durata " << p.durata << " cu prioritatea " << p.prioritate << endl;
	}

	virtual void executa() {
		if (this->esteActiv == false) {
			this->esteActiv = true;

			int nrTickuri = 2;
			if (prioritate == 1) {
				nrTickuri = 10;
			}
			else if (prioritate == 2) {
				nrTickuri = 5;
			}

			for (int i = 0; i < nrTickuri * durata; i++) {
				cout << "procesul " << denumire << " se executa...\n";
			}
			this->esteActiv = false;
		}
	}

	static void exportCSV(Proces* procese, int dim) {
		ofstream fisierScriereCSV("fisier.csv");
		if (fisierScriereCSV.is_open()) {

			for (int i = 0; i < dim; i++) {
				fisierScriereCSV << procese[i].denumire << ", " << procese[i].idProces << ", "
					<< ((procese[i].esteActiv == 1) ? "activ " : "inactiv ") << ", " << procese[i].durata << ", " << procese[i].prioritate << endl;
			}

			fisierScriereCSV.close();
		}
		else {
			throw new exception("Fisierul .csv nu poate fi deschis.");
		}
	}
};
int Proces::NUMBER = 1000;

class Antivirus :public Proces {
private:
	int nrVirusiDetectati;
	string* denumireVirusi; //sau char**

public:
	Antivirus(const char* denumire, int nrVirusiDetectati, string* denumireVirusi)
		:Proces(denumire, INT_MAX, 1) {
		this->nrVirusiDetectati = nrVirusiDetectati;
		this->denumireVirusi = new string[nrVirusiDetectati];
		for (int i = 0; i < nrVirusiDetectati; i++) {
			this->denumireVirusi[i] = denumireVirusi[i];
		}
	}

	Antivirus(const Antivirus& a) :Proces(a) {
		this->nrVirusiDetectati = a.nrVirusiDetectati;
		this->denumireVirusi = new string[a.nrVirusiDetectati];
		for (int i = 0; i < a.nrVirusiDetectati; i++) {
			this->denumireVirusi[i] = a.denumireVirusi[i];
		}
	}

	Antivirus& operator=(const Antivirus& a) {
		if (this != &a) {
			delete[] this->denumireVirusi;

			Proces::operator=(a);
			this->nrVirusiDetectati = a.nrVirusiDetectati;
			this->denumireVirusi = new string[a.nrVirusiDetectati];
			for (int i = 0; i < a.nrVirusiDetectati; i++) {
				this->denumireVirusi[i] = a.denumireVirusi[i];
			}
		}

		return *this;
	}

	~Antivirus() {
		if (denumireVirusi != nullptr) {
			delete[] denumireVirusi;
		}
	}

	void executa() {
		this->setEsteActiv(true);
		cout << "antivirusul " << getDenumire() << " este activ\n";
	}

	bool operator!() {
		if (nrVirusiDetectati == 0) {
			return true;
		}
		else {
			return false;
		}
	}
};

int main() {
	Proces* p1 = new Proces("Proces1", 10, 2);
	Proces* p2 = new Proces("Proces2", 6, 1);
	Proces* p3 = new Proces("Proces3", 4, 3);

	string* s1 = new string[2]{ "virus1", "virus2" };
	string* s2 = new string[3]{ "virus99", "virus71", "virus54" };

	Antivirus* a1 = new Antivirus("Antivirus1", 2, s1);
	Antivirus* a2 = new Antivirus("Antivirus2", 3, s2);

	vector<Proces*> vector;
	vector.push_back(p1);
	vector.push_back(p2);
	vector.push_back(p3);
	vector.push_back(a1);
	vector.push_back(a2);

	for (int i = 0; i < vector.size(); i++) {
		vector[i]->executa();
	}

	Proces ppp1("Proces21", 4, 2);
	Proces ppp2("Proces22", 3, 1);
	Proces ppp3("Proces23", 2, 3);
	Proces* ppp = new Proces[3]{ ppp1, ppp2, ppp3 };
	ppp1.exportCSV(ppp, 3);
}
