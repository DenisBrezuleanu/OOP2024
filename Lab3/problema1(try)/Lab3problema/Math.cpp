#include <cstdarg>
#include "Math.h"
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
    int len_a = strlen(a);
    int len_b = strlen(b);
    int size = len_a + len_b + 1;

    char* result = new char[size];
    int carry = 0;
    int i = len_a - 1;
    int j = len_b - 1;
    int k = size - 1;
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';
        result[k--] = '0' + (sum % 10); // Convert
        carry = sum / 10;
    }
    if (carry) result[k--] = '1';
    return &result[k + 1];
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