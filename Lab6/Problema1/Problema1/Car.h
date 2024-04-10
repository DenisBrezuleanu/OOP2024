#pragma once
#include "Weather.h"
class Car
{
protected:
	float capacitate, consum, speed;
public:
	char* tip;
	virtual float GetCoverd() = 0;/// va return distanta pe care o poate parcurge la capacitatea si consumul masinii
	virtual float GetSpeed(Weather vreme) = 0;
};
