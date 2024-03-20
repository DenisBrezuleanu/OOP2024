#define _CRT_SECURE_NO_WARNINGS
#include "Sort.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <cstring>

using namespace std;
int main()
{
	Sort a(5, 30, 100);
	a.InsertSort();
	a.Print();

	int* myv = new int[3] { 1, 90, 8 };
	Sort b(myv, 3);
	b.InsertSort();
	b.Print();

	Sort c(5, 3, 4, 1, 88, 5);
	c.BubbleSort();
	c.Print();

	Sort d;
	d.BubbleSort();
	d.Print();

	char cc[] = "0,250,100,300,50,150,200,400,350";
	Sort e(cc);
	e.QuickSort();
	e.Print();

	printf("%d\n", e.GetElementsCount());
	printf("%d\n", e.GetElementFromIndex(2));
	return 0;
}