#define _CRT_SECURE_NO_WARNINGS
#include "Number.h"
#include <stdlib.h>
#include <stdio.h>
#include <cstring>

Number::Number(int value) {
	this->baza = 10;
	this->val = value;
	this->SwitchBase(10);
}

Number::Number(const Number& obj) {
	this->baza = obj.baza;
	this->val = obj.val;
	int dim = strlen(obj.numar) + 1;
	this->numar = (char*)malloc(dim * sizeof(char));
	memset(this->numar, 0, dim);
	if (this->numar != nullptr)
		memcpy(this->numar, obj.numar, dim);

}
Number::Number(Number&& obj) {
	this->baza = obj.baza;
	this->val = obj.val;
	int dim = strlen(obj.numar) + 1;
	this->numar = (char*)malloc(dim * sizeof(char));
	memset(this->numar, 0, dim);
	if (this->numar != nullptr)
		memcpy(this->numar, obj.numar, dim);
	obj.numar = nullptr;
	obj.baza = obj.val = 0;

}






Number::Number(const char* value, int base) {
	this->numar = (char*)malloc((strlen(value) + 1) * sizeof(char));
	this->baza = base;
	strcpy(this->numar, value);
	int lg = strlen(value);
	long long int p = 1;
	for (int i = lg - 1; i >= 0; i--)
	{
		if (this->numar[i] >= '0' && this->numar[i] <= '9')
			this->val += p * (this->numar[i] - '0');
		else
			this->val += p * ((this->numar[i] - 'A') + 10);
		p *= base;
	}
}


char Number::operator[](int index) {
	return this->numar[index];
}



void Number::SwitchBase(int newBase)
{
	int n1 = this->val, nrcifre = 0;
	while (n1)
	{
		nrcifre++;
		n1 /= newBase;
	}
	this->numar = (char*)realloc(this->numar, sizeof(char) * nrcifre);
	this->numar[nrcifre] = 0;
	nrcifre--;
	long long int p = 1;
	int n2 = this->val; this->val = 0;
	while (n2)
	{
		int cif = n2 % newBase;
		if (cif < 10)
			this->numar[nrcifre] = cif + '0';
		else
			this->numar[nrcifre] = (cif - 10) + 'A';
		this->val += p * cif;
		p *= newBase;
		nrcifre--;
		n2 /= newBase;
	}
	this->baza = newBase;
}



Number operator+(Number first, Number second) {
	Number a("0", 2);
	a.val = first.val + second.val;
	if (first.baza < second.baza)
		a.baza = second.baza;
	else a.baza = first.baza;
	a.SwitchBase(a.baza);
	return a;
}
Number operator-(Number first, Number second) {
	Number a("0", 2);
	a.val = first.val - second.val;
	if (first.baza < second.baza)
		a.baza = second.baza;
	else a.baza = first.baza;
	a.SwitchBase(a.baza);
	return a;
}
Number& operator+=(Number& first, Number second) {
	first.val += second.val;
	if (first.baza < second.baza)
		first.baza = second.baza;
	first.SwitchBase(first.baza);
	return first;
}
Number& operator-=(Number& first, Number second) {
	first.val -= second.val;
	if (first.baza < second.baza)
		first.baza = second.baza;
	first.SwitchBase(first.baza);
	return first;
}


Number& Number::operator=(Number second) {
	if (this->baza < second.baza)
		this->baza = second.baza;
	this->val = second.val;
	this->SwitchBase(this->baza);
	return *this;
}
Number& Number::operator=(int value) {
	this->val = value;
	this->SwitchBase(this->baza);
	return *this;
}
Number& Number::operator=(const char* second)
{
	int lg = strlen(second);
	this->numar = (char*)realloc(this->numar, sizeof(char) * (lg + 1));
	strcpy(this->numar, second);
	this->val = 0;
	long long int p = 1;
	for (int i = lg - 1; i >= 0; i--)
	{
		if (this->numar[i] >= '0' && this->numar[i] <= '9')
			this->val += p * (this->numar[i] - '0');
		else
			this->val += p * (this->numar[i] - 'A' + 10);
		p *= this->baza;
	}
	return *this;
}

bool Number::operator>(Number second) {
	if (this->val > second.val)
		return true;
	return false;
}
bool Number::operator>=(Number second) {
	if (this->val >= second.val)
		return true;
	return false;
}
bool Number::operator<(Number second) {
	if (this->val < second.val)
		return true;
	return false;
}
bool Number::operator<=(Number second) {
	if (this->val <= second.val)
		return true;
	return false;
}
bool Number::operator==(Number second) {
	if (this->val <= second.val)
		return true;
	return false;
}


void Number::operator--() {
	int lg = strlen(this->numar) - 1;
	int exp = this->baza;
	for (int i = 1; i < lg; i++)
		exp *= this->baza;
	if (this->numar[0] >= '0' && this->numar[0] <= '9')
		this->val -= (exp * (this->numar[0] - '0'));
	else
		this->val -= (exp * (this->numar[0] - 'A' + 10));
	for (int i = 0; i <= lg; i++)
		this->numar[i] = this->numar[i + 1];
}
void Number::operator--(int val) {
	this->val /= this->baza;
	this->SwitchBase(this->baza);

}

void Number::Print() {
	printf("%s\n", this->numar);
}
int  Number::GetDigitsCount() // returns the number of digits for the current number
{
	return strlen(this->numar);
}
int  Number::GetBase() // returns the current base
{
	return this->baza;
}