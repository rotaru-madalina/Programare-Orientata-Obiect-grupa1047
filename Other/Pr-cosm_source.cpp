#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
enum TipProdusCosmetic {
	DEODORANT = 100, PARFUM, SAMPON, SAPUN
};
string conversieCategorieProdus(TipProdusCosmetic tip) {
	switch (tip) {
	case DEODORANT:
		return "Deodorant";
		break;
	case PARFUM:
		return "Parfum";
		break;
	case SAMPON:
		return "Sampon";
		break;
	case SAPUN:
		return "Sapun";
		break;
	default: return "Categorie nedefinita";
		break;
	}
}
class ProdusCosmetic {
private:
	const int idProdus;
	char* denumire;
	string culoare;
	TipProdusCosmetic tip;
	int nrRecnzii;
	int* note;
	static int nrProduseInregistrate;
public:
	//constructorul implicit
	ProdusCosmetic() : idProdus(nrProduseInregistrate + 200)
	{
		nrProduseInregistrate++;
		this->denumire = new char[strlen("Anonim") + 1];
		strcpy(this->denumire, "Anonim");
		this->culoare = "Alb";
		this->tip = SAPUN;
		this->nrRecnzii = 2;
		this->note = new int[2];
		this->note[0] = 10;
		this->note[1] = 9;
	}
	ProdusCosmetic(const char* den, string cul, TipProdusCosmetic tip, int dim, int* note) : idProdus(nrProduseInregistrate + 200) {
		nrProduseInregistrate++;
		this->denumire = new char[strlen(den) + 1];
		strcpy(this->denumire, den);
		this->culoare = cul;
		this->tip = tip;
		this->nrRecnzii = dim;
		this->note = new int[dim];
		for (int i = 0; i < dim; i++) {
			this->note[i] = note[i];
		}

	}
	int getNrReceznii() {
		return this->nrRecnzii;
	}
	void setVectorNote(int nr, int* note) {
		if (nr > 1 && note != nullptr) {
			//dezalocam memoria
			if (this->note != NULL)
				delete[] this->note;
			//alocam memorie
			this->note = new int[nr];
			for (int i = 0; i < nr; i++) {
				this->note[i] = note[i];
			}
			this->nrRecnzii = nr;
		}
		else {
			throw "Parametri incorecti";
		}
	}
	void setDenumireProdus(const char* denumire) {
		if (denumire != nullptr) {
			if (strlen(denumire) > 1) {
				if (this->denumire != nullptr) {
					delete[] this->denumire;
				}
				this->denumire = new char[strlen(denumire) + 1];
				strcpy(this->denumire, denumire);
			}
			else {
				throw "Nume insuficient";
			}
		}
		else {
			throw "Nu exista denumire";
		}
	}
	const char* getDenumire() {
		return this->denumire;
	}
	void setCuloare(string culoare) {
		this->culoare = culoare;
	}
	string getCuloare() {
		return this->culoare;
	}
	void setTip(TipProdusCosmetic tip) {
		this->tip = tip;
	}
	TipProdusCosmetic getTip() {
		return this->tip;
	}
	static int getNrProduse() {
		return nrProduseInregistrate;
	}
	const int getidprodus() {
		return this->idProdus;
	}
	void afisare() {
		cout << "\nId: " << this->idProdus << " ";
		cout << "\nDenumire: " << this->denumire << " ";
		cout << "\nCuloarea etse: " << this->culoare << " ";
		cout << "\nTip produs: " << conversieCategorieProdus(this->tip) << " ";
		cout << "\nNr recenzii: " << this->nrRecnzii << " ";
		cout << "\nNote: ";
		for (int i = 0; i < this->nrRecnzii; i++) {
			cout << "\n" << this->note[i] << " ";
		}

	}
	ProdusCosmetic(const ProdusCosmetic& p) :idProdus(nrProduseInregistrate + 200) {
		nrProduseInregistrate++;
		this->denumire = new char[strlen(p.denumire) + 1];
		strcpy(this->denumire, p.denumire);
		this->culoare = p.culoare;
		this->tip = p.tip;
		this->nrRecnzii = p.nrRecnzii;
		this->note = new int[p.nrRecnzii];
		for (int i = 0; i < p.nrRecnzii; i++) {
			this->note[i] = p.note[i];
		}
	}
	ProdusCosmetic operator=(const ProdusCosmetic& p) {
		if (this->denumire != nullptr) {
			delete[] this->denumire;
		}
		this->denumire = new char[strlen(p.denumire) + 1];
		strcpy(this->denumire, p.denumire);
		this->culoare = p.culoare;
		this->tip = p.tip;
		this->nrRecnzii = p.nrRecnzii;
		if (this->note != nullptr) {
			delete this->note;
		}
		this->note = new int[p.nrRecnzii];
		for (int i = 0; i < p.nrRecnzii; i++) {
			this->note[i] = p.note[i];
		}
		return *this;
	}
	friend ostream& operator<<(ostream& cout, ProdusCosmetic& p) {
		cout << "\nId: " << p.idProdus << " ";
		cout << "\nDenumire: " << p.denumire << " ";
		cout << "\nCuloarea etse: " << p.culoare << " ";
		cout << "\nTip produs: " << conversieCategorieProdus(p.tip) << " ";
		cout << "\nNr recenzii: " << p.nrRecnzii << " ";
		cout << "\nNote: ";
		for (int i = 0; i < p.nrRecnzii; i++) {
			cout << "\n" << p.note[i] << " ";
		}
		return cout;
	}
	float medieRecenzii() {
		float medie = 0;
		for (int i = 0; i < this->nrRecnzii; i++)
		{
			medie += this->note[i];
		}
		if (nrRecnzii == 0) {
			throw "Nu se poate imparti la 0";
		}
		else {
			medie = medie / (this->nrRecnzii);
		}
		return medie;
	}
	bool operator<(ProdusCosmetic p) {
		if (this->medieRecenzii() < p.medieRecenzii())
			return 1;
		else return 0;
	}
	~ProdusCosmetic() {
		if (this->denumire != nullptr) {
			delete[] this->denumire;
		}
		if (this->note != nullptr) {
			delete this->note;
		}
	}
};
int ProdusCosmetic::nrProduseInregistrate = 0;
void main() {
	ProdusCosmetic p;
	p.afisare();
	ProdusCosmetic p1(new char[5]{ "Dove" }, "albastru", SAMPON, 3, new int[3]{ 10,9,8 });
	p1.afisare();
	p1.setVectorNote(5, new int[5]{ 10,10,7,6,9 });
	p1.afisare();
	cout << "\nNumar recenzii p1: " << p1.getNrReceznii() << " ";
	p1.setDenumireProdus("Nivea");
	cout << "\nNoua denumire: " << p1.getDenumire() << " ";
	p1.setCuloare("mov");
	cout << "\nNoua culoare: " << p1.getCuloare() << " ";
	p1.setTip(PARFUM);
	cout << "\nNoul tip de produs: " << conversieCategorieProdus(p1.getTip()) << " ";
	cout << "\nNumar produse: " << p1.getNrProduse() << " ";
	cout << "\nID p1: " << p1.getidprodus() << " ";
	ProdusCosmetic p2 = p1; //constr de copiere
	p2.afisare();
	ProdusCosmetic p3;
	p3 = p2;
	p3.afisare();
	cout << "\nOperator<<";
	cout << p3;

	if (p1 < p2) {
		cout << "\nP1 are media mai mica";
	}
	else {
		cout << "\nP2 are media mai mica";
	}
}
