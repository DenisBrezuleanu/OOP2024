#pragma once
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

template <class T>
bool Compare(T a, T b)
{
	if (a < b)
		return true;
	return false;
}

template <class T>
bool Equal(T a, T b)
{
	if (a == b)
		return true;
	return false;
}

template <class T>
class Array {
	T* vector;
	int index, maxindex;
public:
	Array() {
		this->index = 0;
		this->maxindex = 100;
		this->vector = (T*)malloc(this->maxindex * sizeof(T));
	}
	void Push(T x)
	{
		if (this->index + 1 < this->maxindex)
			this->vector[this->index++] = x;
	}
	T Pop()
	{
		return this->vector[this->index - 1];

	}
	void Delete(int unde)
	{
		for (int i = unde; i < this->index - 1; i++)
			this->vector[i] = this->vector[i + 1];
		this->index--;
	}
	void Insert(T care, int unde)
	{
		if (this->index + 1 < this->maxindex)
		{
			for (int i = this->index; i > unde; i--)
				this->vector[i] = this->vector[i - 1];
			this->vector[unde] = care;
			this->index++;
		}
	}
	int Count() {
		return this->index;
	}
	void BubbleSort(bool (*Compare)(T, T))
	{
		T aux;
		if (Compare == nullptr)
		{
			for (int i = 0; i < this->index - 1; i++)
				for (int j = i + 1; j < this->index; j++)
					if (!(this->vector[i] < this->vector[j]))
					{
						aux = this->vector[i];
						this->vector[i] = this->vector[j];
						this->vector[j] = aux;
					}
		}
		else
		{
			for (int i = 0; i < this->index - 1; i++)
				for (int j = i + 1; j < this->index; j++)
					if (!Compare(this->vector[i], this->vector[j]))
					{
						aux = this->vector[i];
						this->vector[i] = this->vector[j];
						this->vector[j] = aux;
					}
		}

	}
	void Print() {
		for (int i = 0; i < this->index; i++)
			std::cout << this->vector[i] << ' ';
		std::cout << '\n';
	}
	T Get(int care)
	{
		if (care >= 0 && care < this->index)
			return this->vector[care];
	}
	void Set(int unde, T val)
	{
		if (unde >= 0 && unde < this->index)
			this->vector[unde] = val;
	}
	int firstIndexOf(T val, bool (*Equal)(T, T))
	{
		if (Equal == nullptr)
		{
			for (int i = 0; i < this->index; i++)
				if (this->vector[i] == val)
					return i;
		}
		else
		{
			for (int i = 0; i < this->index; i++)
				if (Equal(this->vector[i], val))
					return i;
		}
		return -1;//NU am gasit
	}
};