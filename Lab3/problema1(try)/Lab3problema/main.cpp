#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "Canvas.h"
using namespace std;
int main()
{
	Canvas a;
	printf("%d\n", a.Add(12, 13));
	printf("%d\n", a.Add(12, 13, 22));
	printf("%d\n", a.Add(12.8, 13.9));
	printf("%d\n", a.Add(12.9, 13.7, 18.2));
	printf("%d\n", a.Mul(12, 13));
	printf("%d\n", a.Mul(12, 13, 22));
	printf("%d\n", a.Mul(12.8, 13.9));
	printf("%d\n", a.Mul(12.9, 13.7, 18.2));
	printf("%d\n", a.Add(4, 1, 2, 4, 5));
	printf("%s\n", a.Add("Masina", "Casa"));


	return 0;
}