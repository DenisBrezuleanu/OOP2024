#include "Canvas.h"
#include <iostream>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>

using namespace std;
int main() {

    Canvas a(100, 100);
    a.SetPoint(0, 0, 254);
    a.FillCircle(12, 12, 5, 254);
    a.DrawCircle(70, 70, 5, 254);
    a.DrawRect(30, 20, 40, 30, 254);
    a.FillRect(1, 60, 20, 64, 254);
    a.DrawLine(80, 80, 95, 95, 254);
    //a.Clear();
    a.Print();
    return 0;
}