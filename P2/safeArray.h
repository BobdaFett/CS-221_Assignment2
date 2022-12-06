//
// Created by Lucas Vas on 11/30/2022.
//

#ifndef CS_221_ASSIGNMENT2_SAFEARRAY_H
#define CS_221_ASSIGNMENT2_SAFEARRAY_H

#include <exception>
#include <iostream>
using std::exception;

/**
 * Represents a "safe" integer array, in which the sub operator is overloaded to prevent index under and overflow.
 */
class SafeArray {
public:

    /**
     * Thrown when value is over maximum or under minimum accepted values.
     */
    struct min_max_error : public exception {
        const char *what() const noexcept {
            return "Value is outside of accepted minimum or maximum values.";
        }
    };

    /**
     * Thrown when SafeArray used as argument in operator+= does not match size of current SafeArray.
     */
    struct size_error : public exception {
        const char* what() const noexcept {
            return "Supplied SafeArray does not match the size of the current SafeArray.";
        }
    };

    /**
     * Thrown when attempting to access an index that does not exist.
     */
    struct out_of_bounds : public exception {
        const char* what() const noexcept {
            return "Supplied index is out of bounds.";
        }
    };

    /**
     * Creates a SafeArray with only the minimum bound specified. Note: no elements are added initially.
     * @param smallest The smallest possible value accepted by the SafeArray.
     */
    explicit SafeArray(int smallest);

    /**
     * Creates a SafeArray with the minimum and maximum bounds. Note: no elements are added initially.
     * @param smallest The smallest possible value accepted by the SafeArray.
     * @param largest The largest possible value accepted by the SafeArray.
     */
    SafeArray(int smallest, int largest);

    /**
    * Creates a SafeArray from an existing and sorted int[] array from minimum to maximum. Assumes that the min and max are
    * the first and last values, respectively.
    * @param current_array The int[] array to construct from.
    * @param size The size of current_array.
    */
    SafeArray(int current_array[], int size);

    /**
     * @return The size of the SafeArray.
     */
    int get_size() const;

    /**
     * Inserts an element to the list while sorted, maintaining sorting.
     * @param e The int to add.
     */
    void add(int e);

    /**
     * @return A double value containing the average of all elements in the SafeArray.
     */
    explicit operator double();

    /**
     * Returns the value at the specified index, so long as the index is within acceptable SafeArray size bounds.
     * @param index The index of the requested value.
     * @return The request value, if the index is acceptable.
     */
    int operator[](int index);

    /**
     * Adds the elements of two SafeArrays of equal size. Results in a SafeArray with the same number of elements.
     * This will only add elements when the result is within the bounds of the original SafeArray.
     * @param to_add SafeArray to add. NOTE: *Must* be of equal size.
     */
    void operator+=(SafeArray to_add);

    /**
     * Adds a number to every element of the SafeArray, within the bounds of the min and max values.
     * @param to_add The number to add.
     */
    void operator+(int to_add);

    friend std::ostream& operator<<(std::ostream& out, SafeArray arr);

private:
    int  size;      ///< The current size of the SafeArray.
    int  min;       ///< The minimum value accepted by the SafeArray.
    int  max;       ///< The maximum value accepted by the SafeArray.
    int* elements;  ///< The array of all elements in the array.
    bool has_max;   ///< Determines if the SafeArray was created with a maximum value in mind.
};

#endif //CS_221_ASSIGNMENT2_SAFEARRAY_H
