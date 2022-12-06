//
// Created by Lucas Vas on 12/6/2022.
//

#include <iostream>
#include "stringMap.h"
using namespace std;

int main() {

    StringMap<int> testing1 = StringMap<int>("something", 1);
    StringMap<char> testing2 ("something else", 'c');

    cout << "testing1 size: " << testing1.size() << endl;
    cout << "testing2 size: " << testing2.size() << endl;

    testing1.set("something new", 12);
    testing1.set("everything", 426);
    testing1.set("fba;skdjhg", 957162394);

    testing1.count("everything");

    testing1.erase("everything");
    cout << "testing1 size after delete: " << testing1.size() << endl;

    return 0;
}