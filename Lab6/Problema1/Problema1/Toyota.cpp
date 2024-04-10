#define _CRT_SECURE_NO_WARNINGS
#include "Toyota.h"
#include <stdlib.h>
#include <stdio.h>
#include <cstring>

Toyota::Toyota() {
	this->tip = (char*)malloc(20 * sizeof(char));
	strcpy(this->tip, "Toyota");
	this->capacitate = 100;
	this->consum = 1.2f;
	this->speed = 0;

}
float Toyota::GetCoverd()
{
	return this->capacitate / this->consum;
}
float Toyota::GetSpeed(Weather vreme) {
	switch (vreme)
	{
	case Sunny:
		this->speed = 142;
		break;
	case Rain:
		this->speed = 95;
		break;
	case Snow:
		this->speed = 90;
		break;
	}
	return this->speed;
}