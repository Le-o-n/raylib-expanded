#include "data_structures/array.h"
#include <string.h> // For memcpy

void Array_Dynamic_init(
    Array_Dynamic* array,
    size_t capacity,
    size_t elementSize,
    float growth_rate,
    float growth_threshold
) {
    if (array == NULL) return;

    array->capacity = capacity;
    array->size = 0;
    array->growth_rate = growth_rate;
    array->growth_threshold = growth_threshold;
    array->elementSize = elementSize;
    array->_array = malloc(capacity * elementSize);
}

void Array_Dynamic_unload(
    Array_Dynamic* array
) {
    if (array == NULL) return;
    free(array->_array);
}

bool Array_Dynamic_append(
    Array_Dynamic* array, 
    const void* element
) {
    if (array == NULL) return false;

    if (array->size >= (size_t)(array->capacity * array->growth_threshold)) {
        size_t newCapacity = (size_t)(array->capacity * array->growth_rate);
        void* newArray = realloc(array->_array, newCapacity * array->elementSize);
        if (newArray == NULL) return false; // Allocation failed
        array->_array = newArray;
        array->capacity = newCapacity;
    }

    memcpy(
        (char*)array->_array + array->size * array->elementSize, 
        element, 
        array->elementSize
    );
    array->size++;
    return true;
}

bool Array_Dynamic_get(const Array_Dynamic* array, size_t index, void* outElement) {
    if (array == NULL || index >= array->size) return false;

    memcpy(outElement, (char*)array->_array + index * array->elementSize, array->elementSize);
    return true;
}

bool Array_Dynamic_set(Array_Dynamic* array, size_t index, const void* element) {
    if (array == NULL || index >= array->size) return false;

    memcpy((char*)array->_array + index * array->elementSize, element, array->elementSize);
    return true;
}

bool Array_Dynamic_pop(Array_Dynamic* array, void* outElement) {
    if (array == NULL || array->size == 0) return false;

    memcpy(
        outElement, 
        (char*)array->_array + (array->size - 1) * array->elementSize,
        array->elementSize
    );
    array->size--;
    return true;
}

size_t Array_Dynamic_size(const Array_Dynamic* array) {
    return (array != NULL) ? array->size : 0;
}

bool Array_Dynamic_isEmpty(const Array_Dynamic* array) {
    return (array == NULL || array->size == 0);
}
