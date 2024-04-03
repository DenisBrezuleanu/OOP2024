#pragma once
class Number
{
	int val = 0;
	int baza;
	char* numar;
public:

	Number(const char* value, int base); // where base is between 2 and 16
	Number(int value);

	Number(const Number& obj);
	Number(Number&& obj);

	friend Number operator+(Number first, Number second);
	friend Number& operator+=(Number& first, Number second);
	friend Number operator-(Number first, Number second);
	friend Number& operator-=(Number& first, Number second);
	Number& operator=(Number second);
	Number& operator=(int value);
	Number& operator=(const char* second);

	bool operator>(Number second);
	bool operator>=(Number second);
	bool operator<=(Number second);
	bool operator<(Number second);
	bool operator==(Number second);

	char operator[] (int index);

	void operator--();
	void operator--(int val);

	void SwitchBase(int newBase);
	void Print();
	int  GetDigitsCount(); // returns the number of digits for the current number
	int  GetBase(); // returns the current base
};