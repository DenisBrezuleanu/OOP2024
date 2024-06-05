#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <exception>
#include <iostream>
using namespace std;
class exception1 : public exception {
public:
	virtual const char* what() const throw()
	{
		return "Index in afara range-ului";
	}
};

class Compare
{
public:
	virtual int CompareElements(void* e1, void* e2) = 0;

};
class Derivate :public Compare {
public:
	int CompareElements(void* e1, void* e2)
	{
		int x = *((int*)e1);
		int y = *((int*)e2);
		if (x < y)
			return -1;
		else if (x > y)
			return 1;
		return 0;
	}
};
template<class T>
class ArrayIterator
{
private:
	int Current;
	T** Care;
public:
	ArrayIterator(T** obj, int poz)
	{
		Care = obj;
		Current = poz;
	}
	ArrayIterator& operator ++ ()
	{
		Current++;
		return *this;
	}
	ArrayIterator& operator -- () {
		Current--;
		return *this;
	}
	ArrayIterator& operator= (ArrayIterator<T>& obj) {
		this->Care = obj.Care;
		this->Current = obj.Current;
		return *this;
	}
	bool operator!=(ArrayIterator<T> obj) {
		if (this->Care[Current] != obj.Care[obj.Current])
			return true;
		return false;
	}
	T* GetElement() {
		return this->Care[Current];
	}
};

template<class T>
int compare(const T& a, const T& b)
{
	if (a < b)
		return -1;
	else if (a > b)
		return 1;
	return 0;
}
template<class T>
class Array
{
private:
	T** List; // lista cu pointeri la obiecte de tipul T*
	int Capacity; // dimensiunea listei de pointeri
	int Size; // cate elemente sunt in lista

public:

	Array()// Lista nu e alocata, Capacity si Size = 0
	{
		Capacity = Size = 0;
	}
	~Array() // destructor
	{
		Capacity = Size = 0;
		free(List);
	}
	Array(int capacity) // Lista e alocata cu 'capacity' elemente
	{
		Size = 0;
		Capacity = capacity;
		List = (T**)malloc(Capacity * sizeof(T*));
	}
	Array(const Array<T>& otherArray) // constructor de copiere
	{
		this->Capacity = otherArray.Capacity;
		this->Size = otherArray.Size;
		this->List = otherArray.List;
		this->List = (T**)realloc(this->List, this->Capacity * sizeof(T*));
		memcpy(this->List, otherArray.List, otherArray.Capacity);
	}
	T& operator[] (int index) // arunca exceptie daca index este out of range
	{
		try {
			if (index >= Size || index < 0)
				throw exception1();
			return *List[index];
		}
		catch (exception1& myexp)
		{
			cout << myexp.what() << endl;
		}
	}
	const Array<T>& operator+=(T& newElem)// adauga un element de tipul T la sfarsitul listei si returneaza this
	{

		this->List[Size] = &newElem;
		Size++;
		return *this;
	}
	const Array<T>& Insert(int index, T& newElem) // adauga un element pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
	{
		try {
			if (index >= Capacity || index < 0)
				throw exception1();
			for (int i = Size; i > index; i--)
				List[i] = List[i - 1];
			List[index] = &newElem;
			Size++;
			return *this;
		}
		catch (exception1& myexp)
		{
			cout << myexp.what() << endl;
		}
	}
	const Array<T>& Insert(int index, Array<T>& otherArray) // adauga o lista pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
	{
		try {
			if (this->Size + otherArray.GetSize() >= this->Capacity)
				throw exception1();
			if (index >= Size || index < 0)
				throw exception1();
			for (int i = this->Size + otherArray.GetSize() - 1; i >= index + otherArray.GetSize(); i--)
				this->List[i] = this->List[i - otherArray.GetSize()];
			for (auto it = otherArray.GetBeginIterator(); it != otherArray.GetEndIterator(); ++it)
				this->List[index++] = it.GetElement();
			this->Size += otherArray.GetSize();
			return *this;
		}
		catch (exception1& myexp)
		{
			cout << myexp.what() << endl;
		}
	}
	const Array<T>& Delete(int index) // sterge un element de pe pozitia index, returneaza this. Daca index e invalid arunca o exceptie
	{
		try {
			if (index >= Size || index < 0)
				throw exception1();
			for (int i = index; i < Size; i++)
				List[i] = List[i + 1];
			Size--;
			return *this;
		}
		catch (exception1& myexp)
		{
			cout << myexp.what() << endl;
		}
	}
	void Sort() // sorteaza folosind comparatia intre elementele din T
	{
		for (int i = 0; i < Size - 1; i++)
			for (int j = i + 1; j < Size; j++)
				if ((*List[i]) > (*List[j]))
				{
					T* aux;
					aux = List[i];
					List[i] = List[j];
					List[j] = aux;
				}
	}
	void Sort(int(*compare)(const T&, const T&)) // sorteaza folosind o functie de comparatie
	{
		for (int i = 0; i < Size - 1; i++)
			for (int j = i + 1; j < Size; j++)
				if (compare(*List[i], *List[j]) > 0)
				{
					T* aux;
					aux = List[i];
					List[i] = List[j];
					List[j] = aux;
				}
	}
	void Sort(Compare* comparator) // sorteaza folosind un obiect de comparatie
	{
		for (int i = 0; i < Size - 1; i++)
			for (int j = i + 1; j < Size; j++)
				if (comparator->CompareElements(List[i], List[j]) > 0)
				{
					T* aux;
					aux = List[i];
					List[i] = List[j];
					List[j] = aux;
				}
	}
	// functii de cautare - returneaza pozitia elementului sau -1 daca nu exista
	int BinarySearch(T& elem) // cauta un element folosind binary search in Array
	{
		int st = -1, dr = Size, mij;
		while (dr - st > 1)
		{
			mij = (st + dr) / 2;
			if ((*List[mij]) < elem)
				st = mij;
			else dr = mij;
		}
		if (dr == Size || (*List[dr]) != elem)
			return -1;
		else return dr;
	}
	int BinarySearch(T& elem, int(*compare)(const T&, const T&))//  cauta un element folosind binary search si o functie de comparatie
	{
		int st = -1, dr = Size, mij;
		while (dr - st > 1)
		{
			mij = (st + dr) / 2;
			if (compare(*List[mij], elem) < 0)
				st = mij;
			else dr = mij;
		}
		if (dr == Size || (*List[dr]) != elem)
			return -1;
		else return dr;
	}
	int BinarySearch(T& elem, Compare* comparator)//  cauta un element folosind binary search si un comparator
	{
		int st = -1, dr = Size, mij;
		while (dr - st > 1)
		{
			mij = (st + dr) / 2;
			if (comparator->CompareElements(List[mij], &elem) < 0)
				st = mij;
			else dr = mij;
		}
		if (dr == Size || (*List[dr]) != elem)
			return -1;
		else return dr;
	}
	int Find(T& elem) // cauta un element in Array
	{
		for (int i = 0; i < Size; i++)
			if (List[i] == &elem)
				return i;
		return -1;
	}
	int Find(T& elem, int(*compare)(const T&, const T&))//  cauta un element folosind o functie de comparatie
	{
		for (int i = 0; i < Size; i++)
			if (compare(*List[i], elem) == 0)
				return i;
		return -1;
	}
	int Find(T& elem, Compare* comparator)//  cauta un element folosind un comparator
	{
		for (int i = 0; i < Size; i++)
			if (comparator->CompareElements(List[i], &elem) == 0)
				return i;
		return -1;
	}
	int GetSize() {
		return this->Size;
	}
	int GetCapacity() {
		return this->Capacity;
	}
	ArrayIterator<T> GetBeginIterator() {
		return ArrayIterator<T>(this->List, 0);
	}
	ArrayIterator<T> GetEndIterator() {
		return ArrayIterator<T>(this->List, Size);
	}
};