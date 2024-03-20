#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cmath>
#include "Math.h"
using namespace std;
int main() {
    Math math;
    char *  result = math.Add("15000000000000", "3500000000000000");
    cout << "Adunarea cu char: " << result << endl;
    cout << "Suma listei: " << math.Add(5, 1, 2, 3, 4, 5) << std::endl;
}