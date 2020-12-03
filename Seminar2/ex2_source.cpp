#include<iostream>
#include<string>

using namespace std;

enum GEN { FEMEIE, BARBAT = 3, NECUNOSCUT = 5 };

//private, protected, public
class Student {
	//private: //by default toti membrii si functiile clasei sunt private
	const int ID_Matricol;
	GEN gen;

public:
	char* nume;
	string prenume;
	int varsta;
	int nrNote;
	double* note;

	Student() :ID_Matricol(11111) {

	}

	Student(int id) :ID_Matricol(id) {

	}


	Student(int id, const char* nume, string prenume, int varsta, int nrNote, double* note, GEN gen) :ID_Matricol(id) {
		this->nume = new char[strlen(nume) + 1];
		strcpy_s(this->nume, strlen(nume) + 1, nume);

		this->prenume = prenume;

		this->varsta = varsta;

		this->nrNote = nrNote;

		this->note = new double[nrNote];
		for (int i = 0; i < nrNote; i++) {
			this->note[i] = note[i];
		}

		this->gen = gen;
	}

	const char* getGenInCaractere() {
		switch (gen)
		{
		case FEMEIE:
			return "femeie";
			break;
		case BARBAT:
			return "barbat";
			break;
		case NECUNOSCUT:
			return "necunoscut";
			break;
		default:
			break;
		}
	}

	void afisare() {
		cout << "Studentul cu ID-ul matricol " << ID_Matricol << " are numele " <<
			(nume == nullptr ? "\"null\"" : nume) << " si prenumele " << prenume
			<< " varsta de " << varsta << " ani" << " si este " << getGenInCaractere() << ", are notele:" << endl;

		for (int i = 0; i < nrNote; i++) {
			cout << "Nota " << i + 1 << ": " << note[i] << endl;
		}

		cout << endl;
	}
};

int main() {
	Student s1, s2, s3, s4(4444);
	s1.afisare();
	s4.afisare();

	double v[] = { 6.4,10,6.7,3 };
	//char nume[] = { 'P','o','p','e','s','c','u' };
	Student s5(1000, "Popescu", "Ionut", 21, 4, v, GEN::BARBAT);

	s5.afisare();
}
