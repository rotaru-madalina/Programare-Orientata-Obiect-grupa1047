#include<iostream>
#include<string>

using namespace std;

enum class GEN { FEMEIE, BARBAT = 3, NECUNOSCUT = 5 };

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
	static int anCurent;

	Student() :ID_Matricol(11111) {
		this->nume = new char[strlen("Anonim") + 1];
		strcpy_s(this->nume, strlen("Anonim") + 1, "Anonim");
	}

	Student(int id) :ID_Matricol(id) {
		this->nume = new char[strlen("Anonim") + 1];
		strcpy_s(this->nume, strlen("Anonim") + 1, "Anonim");
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

	Student(const Student& stud) :ID_Matricol(stud.ID_Matricol) {
		this->nume = new char[strlen(stud.nume) + 1];
		strcpy_s(this->nume, strlen(stud.nume) + 1, stud.nume);

		this->prenume = stud.prenume;

		this->varsta = stud.varsta;

		this->nrNote = stud.nrNote;

		this->note = new double[stud.nrNote];
		for (int i = 0; i < stud.nrNote; i++) {
			this->note[i] = stud.note[i];
		}

		this->gen = stud.gen;
	}

	~Student() {
		cout << "destructor" << endl;
		if (this->nume != nullptr) {
			delete[] this->nume;
		}
		if (this->note != nullptr) {
			delete[] this->note;
		}
	}

	//op egal
	Student& operator=(const Student& stud) {
		if (this != &stud) {
			delete[] this->nume;
			delete[] this->note;

			this->nume = new char[strlen(stud.nume) + 1];
			strcpy_s(this->nume, strlen(stud.nume) + 1, stud.nume);

			this->prenume = stud.prenume;

			this->varsta = stud.varsta;

			this->nrNote = stud.nrNote;

			this->note = new double[stud.nrNote];
			for (int i = 0; i < stud.nrNote; i++) {
				this->note[i] = stud.note[i];
			}

			this->gen = stud.gen;
		}

		return *this;
	}

	int getIDMatricol() {
		return ID_Matricol;
	}

	int getAnCurent() {
		return anCurent;
	}

	void setAnCurent(int anCurent) {
		this->anCurent = anCurent;
	}

	GEN getGen() {
		return gen;
	}

	void setGen(GEN gen) {
		this->gen = gen;
	}

	char* getNume() {
		return nume;
	}

	void setNume(char* nume) {
		if (nume != nullptr) {
			delete[] this->nume;//pt a evita memory leaks
			this->nume = new char[strlen(nume) + 1];
			strcpy_s(this->nume, strlen(nume) + 1, nume);
		}
		else
		{
			throw new exception("Numele primit ca input este nullptr.");
		}
	}

	int getVarsta() {
		return varsta;
	}

	void setVarsta(int varsta) {
		this->varsta = varsta;
	}

	string getPrenume() {
		return prenume;
	}

	void setPrenume(string prenume) {
		if (prenume.empty()) {
			throw new exception("Prenumele primit ca input este gol.");
		}
		this->prenume = prenume;
	}

	int getNrNote() {
		return nrNote;
	}

	void setNrNote(int nrNote) {
		this->nrNote = nrNote;
	}

	double* getNote() {
		return note;
	}

	void setNote(double* note, int nrNote) {
		if (note != nullptr && nrNote > 0) {
			this->nrNote = nrNote;

			delete[] this->note;//pt a evita memory leaks

			this->note = new double[nrNote];
			for (int i = 0; i < nrNote; i++) {
				this->note[i] = note[i];
			}
		}
		else {
			throw new exception("Exception: Note este nullptr sau nrNote <= 0.");
		}
	}

	const char* getGenInCaractere() {
		switch (gen)
		{
		case GEN::FEMEIE:
			return "femeie";
			break;
		case GEN::BARBAT:
			return "barbat";
			break;
		case GEN::NECUNOSCUT:
			return "necunoscut";
			break;
		default:
			break;
		}
	}

	void afisare() {
		cout << "Studentul cu ID-ul matricol " << ID_Matricol << " are numele " <<
			(nume == nullptr ? "\"null\"" : nume) << " si prenumele " << prenume
			<< " varsta de " << varsta << " ani" << " si este " << getGenInCaractere()
			<< " si este in anul: " << anCurent << ", are notele:" << endl;

		for (int i = 0; i < nrNote; i++) {
			cout << "Nota " << i + 1 << ": " << note[i] << endl;
		}

		cout << endl;
	}
};

int Student::anCurent = 0;

int main() {
	Student s1, s2, s3, s4(4444);
	s2.setAnCurent(2);

	s1.afisare();
	s1.setAnCurent(1);
	s4.afisare();
	s4.setAnCurent(3);

	double v[] = { 6.4,10,6.7,3 };
	//char nume[] = { 'P','o','p','e','s','c','u' };
	Student s5(1000, "Popescu", "Ionut", 21, 4, v, GEN::BARBAT);

	s5.afisare();

	cout << s5.getIDMatricol() << " " << s5.getGenInCaractere()
		<< " " << s5.getNume() << " " << s5.getPrenume() << endl;

	s5.setGen(GEN::FEMEIE);
	char nume[] = "Ionescu";
	s5.setNume(nume);
	s5.setPrenume("Mihaela");
	s5.setVarsta(23);
	double vv[] = { 8.4,9,5.7,4.5,9,10 };
	s5.setNote(vv, 6);

	s5.afisare();

	//constr compiere
	Student s6(s4);
	cout << "s6\n\n";
	s6.afisare();
	Student s7 = s5;
	cout << "s7\n\n";
	s7.afisare();

	//op egal
	s6 = s7;
	s6.afisare();
}
