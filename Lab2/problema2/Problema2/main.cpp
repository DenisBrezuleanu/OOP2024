#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "Globals.h"
#include "Student.h"

using namespace std;

int main()
{
	Student a, b;
	a.SetName("Vlad");
	printf("%s \n", a.GetName());
	a.Setgm(4.86);
	a.Setge(7.9);
	a.Setgh(5.25);
	printf("%f \n", a.GetAverage());
	b.SetName("Marius");
	printf("%s \n", b.GetName());
	b.Setgm(7.86);
	b.Setge(9.8);
	b.Setgh(9.89);
	printf("%f \n", b.GetAverage());
	printf("Valoarea comparatiei numelor celor doi studenti este: %d\n", CompareName(&a, &b));
	printf("Valoarea comparatiei mediilor celor doi studenti este: %d\n", CompareAverage(&a, &b));
	return 0;
}