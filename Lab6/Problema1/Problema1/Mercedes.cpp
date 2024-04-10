#define _CRT_SECURE_NO_WARNINGS
#include "Mercedes.h"
#include <stdlib.h>
#include <stdio.h>
#include <cstring>

Mercedes::Mercedes() {
	this->tip = (char*)malloc(20 * sizeof(char));
	strcpy(this->tip, "Mercedes");
	this->capacitate = 100;
	this->consum = 0.75f;
	this->speed = 0;

}
float Mercedes::GetCoverd()
{
	return this->capacitate / this->consum;
}
float Mercedes::GetSpeed(Weather vreme) {
	switch (vreme)
	{
	case Sunny:
		this->speed = 150;
		break;
	case Rain:
		this->speed = 120;
		break;
	case Snow:
		this->speed = 100;
		break;
	}
	return this->speed;
}