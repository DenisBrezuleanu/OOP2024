#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
float operator"" _Kelvin(unsigned long long int x)
{
    return (float)(x - 273.15);
}
float operator"" _Fahrenheit(unsigned long long int x)
{
    return (float)((x - 32) / 1.8f);
}
int main() {
    float a = 300_Kelvin;
    float b = 120_Fahrenheit;
    printf("Echivalentul din Celsius pentru Kelvin este:%.3f\n", a);
    printf("Echivalentul din Celsius pentru Fahrenheit este:%.3f\n", b);
    return 0;

}