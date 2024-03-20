#define _CRT_SECURE_NO_WARNINGS
#include "Sort.h"
#include <cstring>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdarg.h>

Sort::Sort(int nr, int minx, int maxx) {
	this->vector = (int*)(malloc(nr * sizeof(int)));
	this->cate = nr;
	time_t t;
	srand((unsigned)time(&t));
	for (int i = 0; i < nr; i++)
		this->vector[i] = minx + rand() % (maxx - minx + 1);
}
Sort::Sort(int* v, int nr) {
	this->vector = (int*)(malloc(nr * sizeof(int)));
	this->cate = nr;
	for (int i = 0; i < nr; i++)
		this->vector[i] = v[i];
}
Sort::Sort(int count, ...) {
	this->vector = (int*)(malloc(count * sizeof(int)));
	this->cate = count;
	va_list vl;
	va_start(vl, count);
	for (int i = 0; i < count; i++)
	{
		this->vector[i] = va_arg(vl, int);
	}
	va_end(vl);
}
Sort::Sort(char* c)
{
	this->vector = (int*)(malloc(1000 * sizeof(int)));
	int nr = 0;
	char* p = strtok(c, ",");
	while (p != NULL)
	{
		int lg = strlen(p);
		this->vector[nr] = 0;
		for (int i = 0; i < lg; i++)
			this->vector[nr] = this->vector[nr] * 10 + (p[i] - '0');
		nr++;
		p = strtok(NULL, ",");
	}
	this->vector = (int*)(realloc(this->vector, nr * sizeof(int)));
	this->cate = nr;
}
Sort::Sort() : vector(new int[6] { 6, 2, 3, 4, 5, 1 }) {
	this->cate = 6;
}
void Sort::InsertSort(bool ascendent) {
	int i, key, j;
	int n = this->cate;
	for (i = 1; i < n; i++)
	{
		key = this->vector[i];
		j = i - 1;
		while (j >= 0 && this->vector[j] > key)
		{
			this->vector[j + 1] = this->vector[j];
			j = j - 1;
		}
		this->vector[j + 1] = key;
	}
	this->sortat = true;
}

void Sort::QuickSort(bool ascendent) {
	quickSort(this->vector, 0, this->cate - 1);
	this->sortat = true;
}
int Sort::partition(int* arr, int st, int dr)
{
	int pivot = arr[dr], aux;
	int i = st - 1;
	for (int j = st; j <= dr - 1; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			aux = arr[i];
			arr[i] = arr[j];
			arr[j] = aux;
		}
	}
	aux = arr[i + 1];
	arr[i + 1] = arr[dr];
	arr[dr] = aux;
	return (i + 1);
}
void Sort::quickSort(int* arr, int st, int dr)
{
	if (st < dr)
	{
		int pi = partition(arr, st, dr);
		quickSort(arr, st, pi - 1);
		quickSort(arr, pi + 1, dr);
	}
}

void Sort::BubbleSort(bool ascendent) {
	int i, j, aux;
	int n = this->cate;
	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++)
			if (this->vector[j] > this->vector[j + 1])
			{
				aux = this->vector[j];
				this->vector[j] = this->vector[j + 1];
				this->vector[j + 1] = aux;
			}
	this->sortat = true;
}

void Sort::Print() {
	for (int i = 0; i < this->cate; i++)
		printf("%d ", this->vector[i]);
	printf("\n");
}

int Sort::GetElementsCount() {
	return this->cate;
}

int Sort::GetElementFromIndex(int index) {
	return this->vector[index];
}