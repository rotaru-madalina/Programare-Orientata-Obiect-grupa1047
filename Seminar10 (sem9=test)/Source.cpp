#include<iostream>
using namespace std;

class ExceptieCustomAnimal :public exception{
public:
	const char* what() const throw() {
		return "Varsta animalului trebuie sa fie >0 si <30\n";
	}
};

class Animal {
public:
	string nume;
	string culoare;
	int varsta;


	Animal(string nume, string culoare, int varsta) {
		this->nume = nume;
		this->culoare = culoare;
		this->varsta = varsta;
	}

	virtual int determinaVarstaInAniOmenesti() = 0;

	virtual void scoateSunet() {
		cout << "\nAnimalul a scos un sunet.\n";
	}

	void setNume(string nume) {
		if (nume.size() < 3) {
			throw new exception("Eroare: Numele animalului trebuie sa aiba minim 3 caractere.\n");
		}
		else {
			this->nume = nume;
		}
	}

	void setVarsta(int varsta) {
		if (varsta < 0 || varsta>30) {
			throw new ExceptieCustomAnimal();
		}
		else {
			this->varsta = varsta;
		}
	}
};

class InterfataPisica {
	virtual void afisarePisica() = 0;
};

class Pisica : public Animal, InterfataPisica {
	int nrVieti;

public:
	Pisica(string nume, string culoare, int varsta, int nrVieti) :Animal(nume, culoare, varsta) {
		this->nrVieti = nrVieti;
	}

	void scoateSunet() {
		cout << "\nPisica face miau miau.\n";
	}

	int determinaVarstaInAniOmenesti() {
		return this->varsta * 2;
	}

	void afisarePisica() {
		cout << "Pisica " << nume << " are culoarea " << culoare << ", varsta de" << varsta
			<< " ani si " << nrVieti << " vieti.\n";
	}
};

class Caine : public Animal {
	bool faceParteDinHaita;

public:
	Caine(string nume, string culoare, int varsta, bool faceParteDinHaita) :Animal(nume, culoare, varsta) {
		this->faceParteDinHaita = faceParteDinHaita;
	}

	void scoateSunet() {
		cout << "\nCainele face ham ham.\n";
	}

	int determinaVarstaInAniOmenesti() {
		return this->varsta * 3;
	}
};

//polimorfism - supraincarcare + suprascriere
int main() {
	Animal* ap1 = new Pisica("Nume_Animal1", "alb", 4, 7);
	Animal* ap2 = new Caine("Nume_Animal2", "negru", 5, false);

	Pisica p1("Nume_Pisica1", "maro", 6, 9), p2("Nume_Pisica2", "gri", 2, 8);

	Caine c1("Nume_Caine1", "portocaliu", 11, true), c2("Nume_Caine2", "alb-negru", 10, false);

	//early - binding -> se stie de la compilare ce versiune a functiei se va apela
	cout << "\n+++early-binding+++\n";
	//a1.scoateSunet();

	p1.Animal::scoateSunet();

	//late - binding -> se stie de la momentul executiei ce versiune a functiei se va apela
	cout << "\n+++late-binding+++\n";

	//obiecte si pointeri la obiecte

	cout << "\n==obiecte si pointeri de obiecte==\n";
	/*Animal* ap1, * ap2;
	ap1 = &a1;
	ap2 = &a2;
	*/

	//a1.scoateSunet();
	//a2.scoateSunet();
	ap1->scoateSunet();
	ap2->scoateSunet();

	Pisica* pp1, * pp2;
	pp1 = &p1;
	pp2 = &p2;

	p1.scoateSunet();
	p2.scoateSunet();
	pp1->scoateSunet();
	pp2->scoateSunet();
	pp2->afisarePisica();

	Caine* cp1, * cp2;
	cp1 = &c1;
	cp2 = &c2;

	c1.scoateSunet();
	c2.scoateSunet();
	cp1->scoateSunet();
	cp2->scoateSunet();


	//conversie in pointer la obiect de baza
	cout << "\n==pointer catre obiect de baza==\n";
	ap1->scoateSunet();
	cout << ap1->determinaVarstaInAniOmenesti() << " ani omenesti" << endl;

	ap1 = pp1;
	ap1->scoateSunet();
	cout << ap1->determinaVarstaInAniOmenesti() << " ani omenesti" << endl;

	ap2 = pp2;
	ap2->scoateSunet();
	cout << ap1->determinaVarstaInAniOmenesti() << " ani omenesti" << endl;

	ap1 = cp1;
	ap1->scoateSunet();
	cout << ap1->determinaVarstaInAniOmenesti() << " ani omenesti" << endl;

	ap2 = cp2;
	ap2->scoateSunet();
	cout << ap1->determinaVarstaInAniOmenesti() << " ani omenesti" << endl;


	//vector dinamic de pointeri
	cout << "\n\n\n===Vector de animale===\n"; //*p1.scoateSunet(); *p2.scoateSunet()
	Animal** animale = new Animal * [6]{ /*&a1, &a2,*/ &p1, &p2, &c1, &c2 };
	for (int i = 0; i < 4; i++) {
		animale[i]->scoateSunet();
	}

	//try catch
	cout << "\n\ntry-catch\n\n";
	try {
		ap1->setNume("xxxx");

		ap1->setVarsta(60);
	}
	catch (exception* e) { /// prinzi ce arunci
		cout << e->what() << "Eroare nu este fatala. Programul poate sa mearga mai departe" << endl;
	}
	catch (ExceptieCustomAnimal *e) {
		cout << e->what() << "Eroare nu este fatala. Programul poate sa mearga mai departe" << endl;
	}
}
