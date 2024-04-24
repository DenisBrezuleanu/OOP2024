#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Car.h"
#include "Circuit.h"
#include "Mazda.h"
#include "Mercedes.h"
#include "Toyota.h"
#include "Ford.h"

int main()
{
	Circuit c;
	c.SetLength(100);
	c.SetWeather(Weather::Snow);
	c.AddCar(new Toyota());
	c.AddCar(new Mercedes());
	c.AddCar(new Ford());
	c.AddCar(new Mazda());
	c.Race();
	c.ShowFinalRanks(); // it will print the time each car needed to finish the circuit sorted from the fastest car to the   slowest.
	c.ShowWhoDidNotFinis(); // it is possible that some cars don't have enough fuel to finish the circuit
	return 0;

}