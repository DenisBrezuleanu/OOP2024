#pragma once
#include "Car.h"
class Ford :
    public Car
{
public:
    Ford();
    float GetCoverd();
    float GetSpeed(Weather vreme);
};