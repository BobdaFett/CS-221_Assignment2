//
// Created by Lucas Vas on 12/3/2022.
//

#ifndef CS_221_ASSIGNMENT2_STRINGMAP_H
#define CS_221_ASSIGNMENT2_STRINGMAP_H

#include <string>
#include <vector>
#include <stdexcept>
using std::string;
using std::pair;
using std::vector;

/**
 * A map implemented by a hash table with a string used for keys and a template type for the values.
 * Should use open hashing with an array/vector of linked lists.
 * @tparam T The type of value to store.
 */
template <typename T>
class StringMap {
public:
    /**
     * A functor that simply compares the length of two keys.
     */
    struct KeyLength {
        /**
         * @return A boolean value if key a is larger than key b.
         * @param a The first key to check.
         * @param b The second key to check.
         */
        bool operator()(string a, string b) {
            return a.length() > b.length();
        }
    };

    /**
     * Creates an empty StringMap object.
     */
    StringMap();

    /**
     * Creates a StringMap with a key-value pair already created.
     * @param key The new key to use.
     * @param value The new value to use.
     */
    StringMap(string key, T value);

    /**
     * @return The size of the StringMap.
     */
    int size() { return total_size; };

    /**
     * @return The number of elements with the specified key.
     * @param key The key to count.
     */
    int count(string key);

    /**
     * Sets the specified key to have the passed value. This will overwrite the current value that is at the key.
     * @param key The key to change.
     * @param value The value to change to.
     */
    void set(string key, T value);

    /**
     * Removes the specified key-value pair.
     * @param key The key to remove.
     */
    void erase(string key);

    /**
     * @return A KeyLength functor that compares the length of two keys.
     */
    KeyLength* key_compare() {
        return new KeyLength();
    };

    /**
     * Hash function that runs the hash table.
     * @param key The key to find.
     * @return The index of the key-value pair in the stored linked list.
     */
    int hashFunction(const string& key) const;

    /**
     * @return The value at the specified key.
     * @param key The key to check.
     */
    T operator[](string key);

private:
    /**
     * Implementation of a linked list.
     */
    struct Node {
        pair<string, T> key_value{};  ///< Stores a std::pair which will keep track of a key-value pair for the hashed table.
        Node*           next;         ///< A Node pointer to the next Node in the list.
    };

    vector<Node> linkedList;  ///< A vector to keep track of the hashed indexes for the StringMap.
    int          total_size;  ///< To store the number of Nodes in the hash table.
};


#endif //CS_221_ASSIGNMENT2_STRINGMAP_H
