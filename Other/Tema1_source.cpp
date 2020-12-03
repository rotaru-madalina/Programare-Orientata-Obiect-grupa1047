#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
enum DEPARTAMENT { CIBE, INFO, STS };

class Sectie {
private:
	const int ID_Sectie;
	static int numar;
	char* nume;
	string prenume;
	float* calificative;
	int nrCal;
	bool gen = true;
	DEPARTAMENT dep;
public:
	//constructor cerinta 2
	Sectie(int id, const char* nume, float* calificative, int nrCal,
		bool gen, DEPARTAMENT dep) : ID_Sectie(id) {
		this->nume = new char[strlen(nume) + 1];
		strcpy_s(this->nume, strlen(nume) + 1, nume);

		this->nrCal = nrCal;
		this->calificative = new float[nrCal];
		for (int i = 0; i < nrCal; i++) {
			this->calificative[i] = calificative[i];
		}
		this->dep = dep;
		this->gen = gen;

	}
	//constructor copiere
	Sectie(const Sectie& prof) :ID_Sectie(prof.ID_Sectie) {
		this->nume = new char[strlen(prof.nume) + 1];
		strcpy_s(this->nume, strlen(prof.nume) + 1, prof.nume);

		this->nrCal = prof.nrCal;
		this->calificative = new float[prof.nrCal];
		for (int i = 0; i < prof.nrCal; i++) {
			this->calificative[i] = prof.calificative[i];
		}
		this->dep = prof.dep;
		this->gen = prof.gen;
	}
	//destructor
	~Sectie() {
		cout << "\nDestructor" << endl;
		if (this->nume != nullptr) {
			delete[] this->nume;
		}
		if (this->calificative != nullptr) {
			delete[] this->calificative;
		}
	}
	//getter 1
	const char* getDepInCaractere() {
		switch (dep)
		{
		case CIBE:
			return "Cibernetica";
			break;
		case INFO:
			return "Informatica";
			break;
		case STS:
			return "Statistica";
			break;
		default:
			break;
		}
	}
	//getter 2
	const int getIDSectie() {
		return this->ID_Sectie;
	}
	//getter 3
	char* getNume() {
		return nume;
	}
	//getter 4
	string getPrenume(string prenume) {
		return prenume;
	}
	//getter 5
	int getnrCal() {
		return nrCal;
	}

	//setter 1
	void setDep(DEPARTAMENT dep) {
		this->dep = dep;
	}
	//setter 2
	void setnrCal(int nrCal) {
		this->nrCal = nrCal;

	}
	//setter 3
	void setNume(char* nume) {
		if (nume != nullptr) {
			delete[] this->nume;
			this->nume = new char[strlen(nume) + 1];
			strcpy_s(this->nume, strlen(nume) + 1, nume);
		}
		else {
			throw new exception("Numele primit ca input este nullptr");
		}
	}
	//setter 4
	void setPrenume(string prenume) {
		if (prenume.empty()) {
			throw new exception("Prenumele primit ca input este gol.");
		}
		this->prenume = prenume;
	}

	//functie afisare
	void afisare() {
		cout << "\nProfesorul cu ID-ul sectiei " << ID_Sectie << ", are numele " <<
			(nume == nullptr ? "\"null\"" : nume) << ", preda la " << getDepInCaractere()
			<< " si are calificativele: " << endl;
		for (int i = 0;i < nrCal;i++) {
			cout << "Calificativul " << i + 1 << ": " << calificative[i] << endl;
		}
		cout << endl;
	}

	//op egal
	Sectie& operator=(const Sectie& prof) {
		if (this != &prof) {
			delete[] this->nume;
			delete[] this->calificative;

			this->nume = new char[strlen(prof.nume) + 1];
			strcpy_s(this->nume, strlen(prof.nume) + 1, prof.nume);

			this->nrCal = prof.nrCal;
			this->calificative = new float[prof.nrCal];
			for (int i = 0; i < prof.nrCal; i++) {
				this->calificative[i] = prof.calificative[i];
			}
			this->dep = prof.dep;
			this->gen = prof.gen;
		}
		return *this;
	}

	//constructor default
	Sectie() :ID_Sectie(123) {
		cout << "Acesta e un constructor default" << endl;
		this->nume = new char[strlen("Anonim") + 1];
		strcpy_s(this->nume, strlen("Anonim") + 1, "Anonim");
	}

	//operator <<
	friend ostream& operator<<(ostream& out, Sectie s) {
		out << "\nID: " << s.ID_Sectie << " ";
		out << "\nNume: " << s.nume << " ";
		out << "\nCalificative: ";
		for (int i = 0; i < s.nrCal; i++) {
			out << "\n" << s.calificative[i] << " ";
		}
		out << "\nNumar calificative: " << s.nrCal << " ";
		out << "\nGen: " << s.gen << " ";
		out << "\nDepartament: " << s.dep << " ";

		return out;
	}

	//operator >>
	friend istream& operator>>(istream& in, Sectie& s) {
		//	cout << "ID_Sectie: "; in >> s.ID_Sectie; 
		char aux[100];
		cout << "Nume: ";
		in >> aux;
		delete[] s.nume;
		s.nume = new char[strlen(aux) + 1];
		strcpy_s(s.nume, strlen(aux) + 1, aux);
		cout << "\nNumar calificative: "; in >> s.nrCal;
		cout << "\nCalificative: ";
		for (int i = 0; i < s.nrCal; i++) {
			in >> s.calificative[i];
		}
		cout << "\nGen: "; in >> s.gen;
		//cout << "\nDepartament: "; in >> s.dep;

		return in;
	}

	//op post-decrementare
	const Sectie operator--(int) {
		Sectie aux(*this);
		this->nrCal--;
		return aux;
	}

	//op []
	float& operator[](int index) {
		if (index >= 0 && index < nrCal) {
			return calificative[index];
		}
		else {
			throw new exception("Error: index >= 0 && index < numar calificative");
		}
	}

	//op !
	bool operator!() {
		return !gen;
	}

	void adaugareElement(float element) {
		float* aux = new float[nrCal + 1];
		for (int i = 0;i < nrCal;i++) {
			aux[i] = this->calificative[i];
		}
		aux[nrCal++] = element;
		delete[] this->calificative;
		this->calificative = aux;
	}

	void stergereElement(float element) {
		int index = -1;
		float* aux = new float[nrCal - 1];
		for (int i = 0;i < nrCal;i++) {
			if (element == calificative[i]) {
				index = i;
				break;
			}
			aux[i] = this->calificative[i];
		}
		if (index != -1) {
			for (int i = index;i < nrCal - 1;i++) {
				aux[i] = this->calificative[i + 1];
			}
			delete[] this->calificative;
			nrCal--;
			this->calificative = aux;
		}
	}
	//functie pt vector
	void elemente_identice_met1(float* calificative) {
		//alocare vector
		this->calificative = new float[sizeof(calificative)];
		for (int i = 0; i < sizeof(calificative); i++) {
			this->calificative[i] = calificative[i];
		}
		//sortare vector
		sort(calificative, calificative + sizeof(calificative));
		//parcurgere vector sortat
		int nr_id = 0;
		for (int i = 0; i < sizeof(calificative); i++) {
			while (i < sizeof(calificative) - 1 && calificative[i] != calificative[i + 1]) {
				i++;
			}
			nr_id++;
		}
		cout << "\nVectorul sortat: ";
		for (int i = 0; i < sizeof(calificative) - 1; i++) {
			cout << calificative[i] << "  ";
		}
		cout << "\nNumarul de elemente duplicate: " << nr_id << endl;
		cout << "\nMinimul din vector este = " << calificative[0] << endl;

	}
	void elemente_identice_met2(float* calificative) {
		int j, nr_dup = 0;
		float aux;
		this->calificative = new float[sizeof(calificative)];
		for (int i = 0; i < sizeof(calificative); i++) {
			this->calificative[i] = calificative[i];
		}
		//am sortat vectorul prin metoda bubble, iar minimul se afla pe prima pozitie
		for (int i = 0; i < sizeof(calificative) - 1; i++) {
			for (j = i + 1; j < sizeof(calificative); j++) {
				if (calificative[i] > calificative[j]) {
					aux = calificative[i];
					calificative[i] = calificative[j];
					calificative[j] = aux;
				}
			}
		}
		//nu inteleg de ce este afisat doar cate un duplicat (la fel si la prima metoda)
		cout << "\nVectorul sortat: ";
		for (int i = 0; i < sizeof(calificative) - 1; i++) {
			cout << calificative[i] << "  ";
		}
		cout << "\nValoarea minima este = " << calificative[0];
		//cate elemente sunt duplicate?
		for (int i = 1; i < sizeof(calificative); i++) {
			if (calificative[i] == calificative[i - 1]) {
				nr_dup++;
				while (calificative[i] == calificative[i - 1]) {
					i++;
				}
			}
		}
		cout << "\nNumarul de elemente duplicate: " << nr_dup << endl;

	}


};


void main() {
	float v[] = { 9, 10, 9 }, vector[] = { 11.5, 22, 5.4, 22, 11.5, 22, 11.5, 30, 5.4 };
	Sectie s, s3;
	s.afisare();
	Sectie s1(1, "Popescu", v, 3, true, DEPARTAMENT::INFO); //0 = B, 1 = F
	s1.afisare();
	s1.setDep(CIBE);
	s1.afisare();
	cout << "\nNume profesor s1: " << s1.getNume() << "\n ";
	//s1.setIDSectie(121) << s1.getIDSectie() << " ";
	//s1.setnrCal(3) << s1.getnrCal() << " ";
	Sectie s2 = s1; //constr copiere
	s2.afisare();
	s2.adaugareElement(7);
	s2.stergereElement(10);
	cout << s2--;
	cout << "\n Acesta este s2 inainte de modificarea numelui: \n";
	s2.afisare();
	char nume[] = "Donciu";
	s2.setNume(nume); //am folosit setter-ul pe variabila dinamica
	s2.getNume();
	s2.afisare();
	cout << "\n------------------\n";
	//s3.elemente_identice_met2(v); vector corupt?
	s3.elemente_identice_met1(vector);

}
