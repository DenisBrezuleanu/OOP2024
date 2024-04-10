#define _CRT_SECURE_NO_WARNINGS
#include "Mazda.h"
#include <stdlib.h>
#include <stdio.h>
#include <cstring>

Mazda::Mazda() {
	this->tip = (char*)malloc(20 * sizeof(char));
	strcpy(this->tip, "Mazda");
	this->capacitate = 100;
	this->consum = 1.1f;
	this->speed = 0;

}
float Mazda::GetCoverd()
{
	return this->capacitate / this->consum;
}
float Mazda::GetSpeed(Weather vreme) {
	switch (vreme)
	{
	case Sunny:
		this->speed = 110;
		break;
	case Rain:
		this->speed = 100;
		break;
	case Snow:
		this->speed = 90;
		break;
	}
	return this->speed;
}