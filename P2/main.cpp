//
// Created by Lucas Vas on 11/30/2022.
//

#include "safeArray.h"
#include <iostream>
using namespace std;

int main() {
    try {
        int testing[5] = {1, 4, 5, 7, 8};
        SafeArray array1 = SafeArray(testing, 5);
        SafeArray array2 = SafeArray(-1);
        SafeArray array3 = SafeArray(-3, 10);

        cout << "array1: " << array1 << endl;
        array1 + 1;
        cout << "array1 updated: " << array1 << endl;
        cout << "array2 size: " << array2.get_size() << endl;
        array2.add(12);
        cout << "array2 updated size: " << array2.get_size() << endl;
        array2 + 1;
        cout << "array2: " << array2 << endl;
        cout << "array2 average: " << (double)array2 << endl;
        array3 += array2; // Throws exception
    } catch (exception& e) {
        cout << "Error: " << e.what() << endl;
        cout << "Exiting..." << endl;
    }

    return 0;
}