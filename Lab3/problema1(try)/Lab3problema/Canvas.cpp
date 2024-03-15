#include <cstdarg>
#include "Canvas.h"
#include <cstring>
#include <cstdarg>
#include <string>
#include <cstdlib>

using namespace std;

int Math::Add(int a, int b) {
    return a + b;
}

int Math::Add(int a, int b, int c) {
    return a + b + c;
}

int Math::Add(double a, double b) {
    return a + b;
}

int Math::Add(double a, double b, double c) {
    return a + b + c;
}

int Math::Mul(int a, int b) {
    return a * b;
}

int Math::Mul(int a, int b, int c) {
    return a + b + c;
}

int Math::Mul(double a, double b) {
    return a + b;
}

int Math::Mul(double a, double b, double c) {
    return a + b + c;
}

char* Math::Add(const char* a, const char* b) {
    int size = (int)strlen(a) + (int)strlen(b) + 1;
    char* arr = new char[size];
    int carry = 0;

    int i = strlen(a) - 1;
    int j = strlen(b) - 1;
    int k = size - 1;

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0)
            sum += a[i--] - '0';
        if (j >= 0)
            sum += b[j--] - '0';

        arr[k--] = '0' + (sum % 10); // Convert
        carry = sum / 10;//reset carry
    }

    // daca mai este un carry il adaugam in array 
    if (carry)
        arr[k--] = '1';


    //shift la rezultat la inceputul arrayului
    return &arr[k + 1];
}


int Math::Add(int count, ...) {
    va_list list;
    int sum = 0;
    va_start(list, count);
    for (int i = 0; i < count; i++)
        sum += va_arg(list, int);
    va_end(list);
    return sum;

}