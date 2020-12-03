class Elev {
	const string serieDeIdentificare;
	char* numeElev;
	string prenumeElev;
	int nrAbsente;
	int nrNote;
	double *note;

public:
	//ex 1 - constructor default - 0.05p

	//ex 2 - constructor cu parametri SI validari pentru variabilile primite ca input - 0.1p
	Elev(int nrNote, double* note);

	//ex 3 - constructor de copiere - 0.1p

	//ex 4 - destructor - 0.05p

    //ex 5 - operatorul =  - 0.1p

	//ex 6 - getteri pentru membrii: numeElev, prenumeElev si note; - 0.1p

	//ex 7 - setteri pentru membrii: numeElev, prenumeElev si note; SI validari pe variabilile primite ca input - 0.1p

	//ex 8 - implementati op << si op >> - 0.1p

	//ex 9 - operatorul [] - 0.1p

	//ex 10 - operatorul + ce mareste notele elevului mai mici sau egale decat 7.5 cu o valoare primita ca input.
	//Notele trebuie marite doar daca valoarea primita este mai mica ca 1.5 si pozitiva, altfel se arunca o eroare. - 0.1p

	//ex 11 - calculeaza si afiseaza in consola media notelor, cea mai mica nota si cea mai mare nota si cate note mai mici ca 5 are elevul. - 0.1p
	void functieEx11();
};

// === Testati in main() toate cerintele. Ce NU este testat este punctat la jumatate de punctaj.

// === Sursele cu erori de compilare sunt evaluate cu 1.

int main() {
	//ex 1

	//ex 2

	//ex 3

	//ex 4

	//ex 5

	//ex 6

	//ex 7

	//ex 8

	//ex 9

	//ex 10

	//ex 11
}
