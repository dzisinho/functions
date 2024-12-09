#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int number) {
    if (number <= 1) return false;
    if (number == 2 || number == 3) return true;
    if (number % 2 == 0 || number % 3 == 0) return false;
    for (int i = 5; i * i <= number; i += 6) {
        if (number % i == 0 || number % (i + 2) == 0) return false;
    }
    return true;
}
int* removePrimes(int* array, int size, int& newSize) {
    int* newArray = new int[size];
    newSize = 0;
    for (int i = 0; i < size; ++i) {
        if (!isPrime(array[i])) {
            newArray[newSize++] = array[i];
        }
    }

    return newArray;
}
int main() {
    int size = 10;
    int array[] = { 10, 17, 4, 6, 13, 19, 8, 20, 23, 29 };
    cout << "Original array: ";
    for (int i = 0; i < size; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
    int newSize;
    int* newArray = removePrimes(array, size, newSize);
    cout << "Array after removing primes: ";
    for (int i = 0; i < newSize; ++i) {
        cout << newArray[i] << " ";
    }
    cout << endl;

    delete[] newArray;

    return 0;
}
