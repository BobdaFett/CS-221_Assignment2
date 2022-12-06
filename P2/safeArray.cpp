//
// Created by Lucas Vas on 11/30/2022.
//

#include "safeArray.h"  // SafeArray header
#include <iostream>     // cout, endl
using std::cout;
using std::endl;

SafeArray::SafeArray(int smallest) : min(smallest),
                                     size(0),
                                     has_max(false),
                                     max(0),
                                     elements(new int[0]) {}

SafeArray::SafeArray(int smallest, int largest) : min(smallest),
                                                  max(largest),
                                                  size(0),
                                                  has_max(true),
                                                  elements(new int[0]) {}

SafeArray::SafeArray(int current_array[], int size) : size(size),
                                                      min(current_array[0]),
                                                      max(current_array[size - 1]),
                                                      has_max(true),
                                                      elements(current_array) {}

int SafeArray::get_size() const {
    return this->size;
}

void SafeArray::add(int e) {
    if((e < min) || (e > max)) throw min_max_error();

    if (size == 0) {
        delete[] elements;
        elements = new int[1];
        elements[0] = e;
        return;
    }

    int* temp = new int[size + 1];
    int index{};
    while (temp[index] != e) {
        temp[index] = elements[index];
        index++;
    }
    temp[index++] = e;
    for(index; index < size; index++)
        temp[index] = elements[index];

    delete[] elements;  // prevent memory leak
    elements = new int[size + 1];
    elements = temp;
    size += 1;
}

SafeArray::operator double() {
    int avg = 0;
    for (int i = 0; i < size; i++)
        avg += elements[i];
    return (double)avg / size;
}

int SafeArray::operator[](int index) {
    if((index < 0) || (index > size)) throw out_of_bounds();
    return elements[index];
}

void SafeArray::operator+=(SafeArray to_add) {
    if(to_add.get_size() != this->size) throw size_error();

    for (int i = 0; i < this->size; i++) {
        if ((has_max && (elements[i] + to_add[i]) < max && (elements[i] + to_add[i]) > min) ||
            (!has_max && (elements[i] + to_add[i]) > min)) {
            elements[i] += to_add[i];
        } else throw min_max_error();
    }
}

void SafeArray::operator+(int to_add) {
    for (int i = 0; i < size; i++) {
        if ((has_max && (elements[i] + to_add) < max && (elements[i] + to_add) > min) ||
            (!has_max && (elements[i] + to_add) > min)) {
            elements[i] += to_add;
        } else throw min_max_error();
    }
}

std::ostream& operator<<(std::ostream& out, SafeArray arr) {
    for (int i = 0; i < arr.get_size(); i++)
        out << "(" << i << ", " << arr[i] << ") ";
    return out;
}