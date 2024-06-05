#include <iostream>
#include <exception>
#include "Header.h"
using namespace std;


int main()
{
	Array<int> v(12);
	Array<int> u(12);
	Derivate Mycomparator;
	int a = 8, b = 7, c = 6, d = 5, e = 4, f = 3, g = 2, h = 1;
	v += a;
	cout << "Elementele de pe pozitia 0 este:" << '\n';
	cout << v[0] << endl;
	v.Insert(1, b);
	v.Insert(2, c);
	v.Insert(3, d);
	v.Insert(4, e);
	v.Insert(5, f);
	v.Insert(6, g);
	cout << "Elementele din v:" << '\n';
	for (int i = 0; i < v.GetSize(); i++)
		cout << v[i] << ' ';
	cout << endl;
	cout << "Pozitia elementului a=8 in array este:" << '\n';
	cout << v.Find(a) << endl;
	cout << "Am sortat array-ul" << '\n';
	v.Sort(compare);
	cout << "Pozitia elementului a=8 in array-ul sortat este:" << '\n';
	cout << v.BinarySearch(a, compare) << endl;
	cout << "Dimensiunea array-ului este:" << '\n';
	cout << v.GetSize() << '\n';
	cout << "Am sters primul element:" << '\n';
	v.Delete(0);
	for (int i = 0; i < v.GetSize(); i++)
		cout << v[i] << ' ';
	cout << endl;
	cout << "Pozitia elementului a=8 in array-ul sortat este:" << '\n';
	cout << v.Find(a) << '\n';
	cout << "Dimensiunea array-ului este:" << '\n';
	cout << v.GetSize() << '\n';
	cout << "Am adaugat in array pe h=1" << '\n';
	v += h;
	cout << "Am sortat vectorul" << '\n';
	v.Sort(&Mycomparator);
	cout << "Elementele din v:" << '\n';
	for (int i = 0; i < v.GetSize(); i++)
		cout << v[i] << ' ';
	cout << endl;
	cout << "Primul element este:" << '\n';
	cout << v[0] << '\n';
	cout << "Pozitia elementului b=7 in array-ul sortat este:" << '\n';
	cout << v.BinarySearch(b, &Mycomparator) << '\n';
	cout << "Pozitia elementului b=7 in array-ul sortat este:" << '\n';
	cout << v.Find(b, &Mycomparator) << '\n';
	cout << "Pozitia elementului b=7 in array-ul sortat este:" << '\n';
	cout << v.Find(b, compare) << endl;
	cout << "Elementele din v:" << '\n';
	for (int i = 0; i < v.GetSize(); i++)
		cout << v[i] << ' ';
	cout << endl;
	u += a;
	u += b;
	cout << "Am inserat in v array-ul u (8,7) de la pozitia 1" << '\n';
	v.Insert(1, u);
	cout << "Elementele din v:" << '\n';
	for (int i = 0; i < v.GetSize(); i++)
		cout << v[i] << ' ';
	cout << endl;
	cout << "Am inserat in v array-ul u (8,7) de la o pozitie prea mare" << '\n';
	v.Insert(20, u);
	cout << "Elementele din v:" << '\n';
	for (int i = 0; i < v.GetSize(); i++)
		cout << v[i] << ' ';
	cout << endl;
	return 0;

}