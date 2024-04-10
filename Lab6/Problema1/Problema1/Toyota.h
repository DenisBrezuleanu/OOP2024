#pragma once
#include "Car.h"
class Toyota :
    public Car
{
public:
    Toyota();
    float GetCoverd();
    float GetSpeed(Weather vreme);
};
