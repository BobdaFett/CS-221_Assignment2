//
// Created by Lucas Vas on 12/3/2022.
//

#include "stringMap.h"

template <class T>
StringMap<T>::StringMap(string key, T value) {
    Node temp {pair(key, value), nullptr, nullptr};
    linkedList[hashFunction(key)] = temp;
}

template <class T>
int StringMap<T>::size() {
    int   size{};
    Node* temp;

    for (int i{}; i < 10; i++) {
        temp = linkedList[i];
        if (temp != nullptr) size++;  // TODO Make sure Node starts as a nullptr.
        while (temp->next != nullptr) {
            temp = temp->next;
            size++;
        }
    }
    return size;
}

template <class T>
int StringMap<T>::count(string key) {
    Node* temp = linkedList[hashFunction(key)];
    int size{};
    while (temp != nullptr) {
        size++;
        temp = temp->next;
    }
    return size;
}

template <class T>
void StringMap<T>::erase(string key) {
    int index = hashFunction(key);
    Node* prev;

    for (Node n : linkedList) {
        if (n.key_value.first == key) {
            prev->next = n->next;
            delete n;
            return;
        }
        prev = n;
        n = n->next;
    }
}

template <class T>
void StringMap<T>::set(string key, T value) {
    int index = hashFunction(key);
    for (Node n : linkedList) {
        if (n.key_value.first == key) {
            n.key_value.second = value;
            return;
        }
    }
    // Create an insert function.

}

template <class T>
int StringMap<T>::hashFunction(const string& key) const {
    int sum{};
    for (char c : key)
        sum += c;
    return sum;
}

template <class T>
T StringMap<T>::operator[](string key) {
    int index = hashFunction(key);
    return linkedList[index].key_value.second;
}