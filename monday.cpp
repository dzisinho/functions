#include <iostream>
using namespace std;

int* allocateArray(int size) {
    if (size <= 0) {
        return nullptr;
    }
    return new int[size];
}

void initializeArray(int* array, int size, int value = 0) {
    for (int i = 0; i < size; ++i) {
        array[i] = value;
    }
}


void printArray(const int* array, int size) {
    for (int i = 0; i < size; ++i) {
        cout << array[i] << " ";
    }
    cout << std::endl;
}


void deleteArray(int*& array) {
    delete[] array;
    array = nullptr;
}


int* appendElement(int* array, int& size, int value) {
    int* newArray = allocateArray(size + 1);
    for (int i = 0; i < size; ++i) {
        newArray[i] = array[i];
    }
    newArray[size] = value;
    deleteArray(array);
    ++size;
    return newArray;
}


int* insertElement(int* array, int& size, int index, int value) {
    if (index < 0 || index > size) {
        cerr << "Index out of bounds" << endl;
        return array;
    }
    int* newArray = allocateArray(size + 1);
    for (int i = 0, j = 0; i < size + 1; ++i) {
        if (i == index) {
            newArray[i] = value;
        }
        else {
            newArray[i] = array[j++];
        }
    }
    deleteArray(array);
    ++size;
    return newArray;
}

int* removeElement(int* array, int& size, int index) {
    if (index < 0 || index >= size) {
        cerr << "Index out of bounds" << endl;
        return array;
    }
    int* newArray = allocateArray(size - 1);
    for (int i = 0, j = 0; i < size; ++i) {
        if (i != index) {
            newArray[j++] = array[i];
        }
    }
    deleteArray(array);
    --size;
    return newArray;
}

int main() {
    int size = 5;
    int* array = allocateArray(size);

    initializeArray(array, size, 1);
    printArray(array, size);

    array = appendElement(array, size, 10);
    printArray(array, size);

    array = insertElement(array, size, 2, 99);
    printArray(array, size);

    array = removeElement(array, size, 3);
    printArray(array, size);

    deleteArray(array);
    return 0;
}
