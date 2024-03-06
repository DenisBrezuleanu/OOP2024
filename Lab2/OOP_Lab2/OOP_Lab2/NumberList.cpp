#include <stdlib.h>
#include <stdio.h>
#include "NumberList.h"
void NumberList::Init() {
    this->count = 0;
}
bool NumberList::Add(int x) {
    if (this->count >= 10)
        return false;
    numbers[this->count++] = x;
    return true;

}
void NumberList::Sort()
{
    int i, j, aux;
    for (i = 0; i < count - 1; i++)
        for (j = i + 1; j < count; j++)
            if (numbers[i] > numbers[j])
            {
                aux = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = aux;
            }
}
void NumberList::Print() {
    int i;
    for (i = 0; i < count; i++)
        printf("%d ", numbers[i]);
    printf("\n");
}