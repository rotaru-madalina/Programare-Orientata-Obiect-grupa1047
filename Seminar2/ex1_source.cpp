#include<iostream>
using namespace std;

void afisare(int x, float* y) {
	cout << x << " ";
	if (y == nullptr) {
		cout << "nullptr";
	}
}
int main() {
	int x = 10, y = 20, z = 30;

	const int t = 100;

	//t = 200;//error

	//pointer constant la o zona de memorie
	int* const p1 = &x;
	*p1 = 200;
	//p1 = &y;//error

	//pointer la o zona de momorie constanta
	const int* p2 = &y; //sau se mai poate scrie: int const* p3 = &z;
	p2 = &x;
	//*p2 = 300;//error

	//pointer constant la o zona de memorie constanta
	const int* const p3 = &z;
	//p3 = &y;//error
	//*p3 = 400;//error

	afisare(NULL, nullptr);
	int oo;
	int* px = NULL;
	int* py = nullptr;
}
