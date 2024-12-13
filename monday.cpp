#include <iostream>
#include <iomanip>
using namespace std;
void countPosNegZero(int* arr, int size, int* positive, int* negative, int* zero) {

    *positive = 0;

    *negative = 0;

    *zero = 0;

    for (int i = 0; i < size; i++) {

        if (*(arr + i) > 0) {

            (*positive)++;

        }
        else if (*(arr + i) < 0) {

            (*negative)++;

        }
        else {

            (*zero)++;

        }

    }

}