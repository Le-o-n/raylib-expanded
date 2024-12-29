#ifndef ARRAY_H
#define ARRAY_H

#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    void* _array;         // Pointer to the data (contiguous memory block)
    size_t capacity;      // Allocated capacity
    size_t size;  
    size_t elementSize;        // Current number of elements
    float growth_rate;    // Growth rate for resizing (e.g., 1.5 means 50% growth)
    float growth_threshold; // Threshold for triggering growth/shrinkage (e.g., 0.75 for 75%)
} Array_Dynamic;

// Function declarations

// Initializes a new dynamic array.
// Parameters:
// - array: Pointer to the Array_Dynamic struct to initialize.
// - capacity: Initial capacity of the array (can be 0 for default).
// - size: Initial size of the array (must not exceed capacity).
// - growth_rate: Growth multiplier when resizing (e.g., 1.5 means 50% growth).
// - growth_threshold: Fraction of capacity at which to grow/shrink (e.g., 0.75 for 75%).
void Array_Dynamic_init(
    Array_Dynamic* array,
    size_t capacity,
    size_t elementSize,
    float growth_rate,
    float growth_threshold
);

// Frees the memory allocated for the dynamic array.
// Parameters:
// - array: Pointer to the Array_Dynamic struct to deinitialize.
void Array_Dynamic_unload(Array_Dynamic* array);

// Appends an element to the dynamic array, resizing if necessary.
// Parameters:
// - array: Pointer to the Array_Dynamic struct.
// - element: Pointer to the element to append.
// Returns true if the element was added successfully, false otherwise.
bool Array_Dynamic_append(Array_Dynamic* array, const void* element);

// Gets an element at the specified index.
// Parameters:
// - array: Pointer to the Array_Dynamic struct.
// - index: Index of the element to retrieve.
// - outElement: Pointer to the memory where the element will be copied.
// Returns true if the index is valid, false otherwise.
bool Array_Dynamic_get(const Array_Dynamic* array, size_t index, void* outElement);

// Sets an element at the specified index.
// Parameters:
// - array: Pointer to the Array_Dynamic struct.
// - index: Index of the element to set.
// - element: Pointer to the element to set.
// Returns true if the index is valid, false otherwise.
bool Array_Dynamic_set(Array_Dynamic* array, size_t index, const void* element);

// Removes the last element from the dynamic array.
// Parameters:
// - array: Pointer to the Array_Dynamic struct.
// Returns true if an element was removed, false otherwise (e.g., if empty).
bool Array_Dynamic_pop(Array_Dynamic* array, void* outElement);

// Gets the number of elements in the array.
// Parameters:
// - array: Pointer to the Array_Dynamic struct.
// Returns the number of elements.
size_t Array_Dynamic_size(const Array_Dynamic* array);

// Checks if the dynamic array is empty.
// Parameters:
// - array: Pointer to the Array_Dynamic struct.
// Returns true if the array is empty, false otherwise.
bool Array_Dynamic_isEmpty(const Array_Dynamic* array);

#endif // ARRAY_DYNAMIC_H
