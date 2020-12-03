#include<iostream>

using namespace std;

int main() {
	int x = 10;

	cout << "refX=" << &x << endl;

	int* px = &x;
	cout << "px=" << px << "\n*px=" << *px << endl;
	cout << "Refpx=" << &px << endl << endl;


	int* py = new int(5);
	cout << *py << endl;

	delete py;

	int arr[] = { 221,21,21,21 };

	int* v = new int[5];
	for (int i = 0; i < 5; i++) {
		v[i] = i + 2;
	}

	for (int i = 0; i < 5; i++) {
		cout << v[i] << " ";
	}
	cout << endl << endl;
	delete v;

	int** matrice = new int* [2];
	for (int i = 0; i < 2; i++) {
		matrice[i] = new int[3];
		for (int j = 0; j < 3; j++) {
			matrice[i][j] = (i + j + 1) * 2;
		}
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			cout << matrice[i][j] << " ";
		}
		cout << "\n";
	}

	for (int i = 0; i < 2; i++) {
		delete matrice[i];
	}
	delete[] matrice;

	////////////////////
	int N;
	int elementNou;
	cout << "N="; cin >> N;

	int* w = new int[N];

	for (int i = 0; i < N; i++) {
		cout << "w[" << i << "]=";
		cin >> w[i];
	}

	cout << "ElementNou="; cin >> elementNou;

	int* aux = new int[N + 1];
	for (int i = 0; i < N; i++) {
		aux[i] = w[i];
	}

	aux[N++] = elementNou;
	delete w;
	w = aux;

	for (int i = 0; i < N; i++) {
		cout << w[i] << " ";
	}

	delete w;
}