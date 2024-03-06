#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "NumberList.h"
using namespace std;
int main()
{
	NumberList mylist;
	mylist.Init();
	mylist.Add(123); mylist.Add(5); mylist.Add(112); mylist.Add(545); mylist.Add(84);
	printf("Vectorul nestortat este: \n");	
	mylist.Print();
	mylist.Sort();
	printf("Vectorul stortat este: \n");
	mylist.Print();
	return 0;
}