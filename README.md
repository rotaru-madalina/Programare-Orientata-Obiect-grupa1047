# POO---seminar-1

#include<iostream>
using namespace std;
int
main ()
{
  int x = 10;

  cout << "Refx= " << &x << endl;

  int *px = &x;
  cout << "px=" << px << "\n *px=" << *px << endl;
  cout << "Refpx=" << &px << endl;

  int *py = new int (5);	//asta stocheaza in heap
  cout << py << endl;		//memorie pe heap

  delete py;			//trebuie sa dezalocam memoria de pe heap; NI SE SCADE DACA NU FACEM ASTA

  int arr[] = { 221, 21, 21, 21 };	//este un pointer catre primul element din lista

  int *v = new int[5];
  for (int i = 0; i < 5; i++)
    {
      v[i] = i + 2;
    }
  for (int i = 0; i < 5; i++)
    {
      cout << v[i] << " ";
    }
  cout << endl << endl;
  delete v;


  int **matrice = new int *[2];	//am creat un vector de pointeri
  for (int i = 0; i < 2; i++)
    {
      matrice[i] = new int[3];
      for (int j = 0; j < 3; j++)
	{
	  matrice[i][j] = (i + j + 1) * 2;
	}
    }

  for (int i = 0; i < 2; i++)
    {
      for (int j = 0; j < 3; j++)
	{
	  cout << matrice[i][j] << " ";
	}
      cout << endl;
    }
  for (int i = 0; i < 2; i++)	//dezalocam liniile
    {
      delete matrice[i];
    }
  delete[]matrice;		//asa se sterge o matrice

  //////////////

  int N;
  int elementNou;
  cout << "N=";
  cin >> N;

  int *w = new int[N];

  for (int i = 0; i < N; i++)
    {
      cout << "w[" << i << "]=";
      cin >> w[i];
    }

  cout << "ElementNou= ";
  cin >> elementNou;

  int *aux = new int[N + 1];
  for (int i = 0; i < N; i++)
    {
      aux[i] = w[i];
    }
  aux[N++] = elementNou;
  delete w;
  w = aux;

  for (int i = 0; i < N; i++)
    cout << w[i] << " ";
  delete w;


}
