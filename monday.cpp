#include <iostream>

// Функція розподілу динамічної пам'яті
int* allocateArray(int size) {
    if (size <= 0) {
        return nullptr;
    }
    return new int[size];
}

// Функція ініціалізації динамічного масиву
void initializeArray(int* array, int size, int value = 0) {
    for (int i = 0; i < size; ++i) {
        array[i] = value;
    }
}

// Функція друку динамічного масиву
void printArray(const int* array, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

// Функція видалення динамічного масиву
void deleteArray(int*& array) {
    delete[] array;
    array = nullptr;
}

// Функція додавання елемента в кінець масиву
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

// Функція вставки елемента за вказаним індексом
int* insertElement(int* array, int& size, int index, int value) {
    if (index < 0 || index > size) {
        std::cerr << "Index out of bounds" << std::endl;
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

// Функція видалення елемента за вказаним індексом
int* removeElement(int* array, int& size, int index) {
    if (index < 0 || index >= size) {
        std::cerr << "Index out of bounds" << std::endl;
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
