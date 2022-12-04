//
// Created by Lucas Vas on 12/4/2022.
//

#ifndef CS_221_ASSIGNMENT2_KEYLENGTH_H
#define CS_221_ASSIGNMENT2_KEYLENGTH_H

#include <string>
using std::string;

/**
 * A functor returned only through the StringMap class. Compares two keys and outputs a boolean value.
 */
class KeyLength {
public:
    /**
     * Creates the KeyLength object - this object has no fields.
     */
    KeyLength() = default;

    /**
     * @return A boolean value if key a is larger than key b.
     * @param a The first key to check.
     * @param b The second key to check.
     */
    bool operator()(string a, string b) {
        return a.length() > b.length();
    }
};

#endif //CS_221_ASSIGNMENT2_KEYLENGTH_H
