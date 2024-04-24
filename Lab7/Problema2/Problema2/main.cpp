#include "Template.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int main() {

    Array<int>c;
    c.Push(9);
    c.Push(6);
    c.Push(8);
    c.Push(123);
    c.Push(89);
    c.Push(-1);

    c.Set(0, 18);// setez elemntul de pe poz 0 cu 18
    c.Print();

    c.BubbleSort(Compare);
    c.Print();

    cout << "Ultimul element are valoarea: " << c.Pop() << '\n';
    c.Insert(45, 0);// inserez 45 pe poz 0
    c.Print();

    cout << "Primul element cu valoarea 89 se afla pe pozitia: " << c.firstIndexOf(89, Equal) << '\n';
    cout << "Elementul de pe pozitia 0 este: " << c.Get(0) << '\n';
    c.Delete(5);//sterg elementul de poz 5
    c.Print();
    cout << "Numarul de elemente din vector este: " << c.Count() << '\n';
    return 0;
}