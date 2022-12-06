//
// Created by Lucas Vas on 12/3/2022.
//

#include "stringMap.h"

template <typename T> StringMap<T>::StringMap() : total_size(0) {}

template <typename T> StringMap<T>::StringMap(string key, T value) {
    total_size = 0;
    set(key, value);
}

template <typename T> int StringMap<T>::count(string key) {
    Node* temp = linkedList[hashFunction(key)];
    int size{};
    while (temp != nullptr) {
        size++;
        temp = temp->next;
    }
    return size;
}

template <typename T> void StringMap<T>::erase(string key) {  // Capable of erasing elements.
    int index = hashFunction(key);
    Node* prev, temp = linkedList[index];
    while (temp != nullptr) {
        if (temp.key_value.first == key) {
            prev->next = temp->next;
            delete temp;
            total_size--;
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    throw std::out_of_range(nullptr);
}

template <typename T> void StringMap<T>::set(string key, T value) {  // Capable of adding elements.
    int index = hashFunction(key);
    Node* temp = linkedList[index];
    while (temp != nullptr) {
        if (temp->key_value.first == key) {
            temp->key_value.second = value;
            return;
        }
        temp = temp->next;
    }

    temp->next = new Node{pair(key, value), nullptr};
    total_size++;
}

template <typename T> int StringMap<T>::hashFunction(const string& key) const {
    int sum{};
    for (char c : key)
        sum += c;
    return sum;
}

template <typename T> T StringMap<T>::operator[](string key) {
    int index = hashFunction(key);
    Node* temp = linkedList(index);
    while (temp != nullptr) {
        if (temp->key_value.first == key) return temp->key_value.second;
    } throw std::out_of_range(nullptr);
}