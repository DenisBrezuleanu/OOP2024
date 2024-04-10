#pragma once
#include "Car.h"
class Circuit
{
	float lcircuit;
	Weather wcircuit;
	Car** masini;
	float* timpi;
	int crt, maxindex;
public:
	Circuit();
	void SetLength(float cat);
	void SetWeather(Weather cum);
	void AddCar(Car* nou);
	void Race();
	void ShowFinalRanks(); // it will print the time each car needed to finish the circuit sorted from the fastest car to the   slowest.
	void ShowWhoDidNotFinis(); // it is possible that some cars don't have enough fuel to finish the circuit
};
