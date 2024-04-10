#define _CRT_SECURE_NO_WARNINGS
#include "Ford.h"
#include <stdlib.h>
#include <stdio.h>
#include <cstring>

Ford::Ford() {
	this->tip = (char*)malloc(20 * sizeof(char));
	strcpy(this->tip, "Ford");
	this->capacitate = 100;
	this->consum = 0.8f;
	this->speed = 0;

}
float Ford::GetCoverd()
{
	return this->capacitate / this->consum;
}
float Ford::GetSpeed(Weather vreme) {
	switch (vreme)
	{
	case Sunny:
		this->speed = 145;
		break;
	case Rain:
		this->speed = 120;
		break;
	case Snow:
		this->speed = 110;
		break;
	}
	return this->speed;
}