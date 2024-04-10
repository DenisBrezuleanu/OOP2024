#pragma once
#include "Car.h"
class Mazda :
    public Car
{
public:
    Mazda();
    float GetCoverd();
    float GetSpeed(Weather vreme);
};
