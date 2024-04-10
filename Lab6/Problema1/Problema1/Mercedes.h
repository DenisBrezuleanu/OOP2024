#pragma once
#include "Car.h"
class Mercedes :
    public Car
{
public:
    Mercedes();
    float GetCoverd();
    float GetSpeed(Weather vreme);
};
