#pragma once

#include<stdlib.h>

#ifndef TYPE
#define TYPE float
#endif

#define VEC_MATH_ERROR_STR "Incorrect application of vector function\n"
#define MEM_ERR_STR "Insufficient memory to perform operation\n"

struct vector_t {
    // Actual array of values in the vector
    TYPE * values;
    // Length of the vector
    int length;
    // The size of vector space allocated to the element
    // Size measured in 'floats'
    int size;
};

struct vector_t vec_null = {NULL, 0, 0};
typedef struct vector_t vector;

// Print the vector on a line along with capacity of container and length
void print_vector(vector v);
// Push value of given type into vector
// NOTE: only shallow copy is created
void push_into(vector * v, TYPE val);
// Push an array of values into vector
// NOTE: Only shallow copies are created
void push_array(vector * v, TYPE * arr, int size);
// Generate a vector of FP 0s 
vector zeroes(int len);
// Add two vectors of equal length
// NOTE: Undefined behavious for non numeric inputs
vector add(vector v1, vector v2);
// Dot product of two vectors
// NOTE: beahviour on non numeric types in undefined
float dot_product(vector v1, vector v2);
// Normalises a vector of numbers
// NOTE: Undefined behavious on non numeric inputs
float normalize(vector v);
// Demonstrative scalar function that takes input as a vector and dimensions
float scalar_field(vector v, int dim);
// Negates a vector of numbers
// NOTE: Behavious undefined with non numeric types
void negate(vector * v);
// Delete the contents of the vector
// NOTE: vector itself is not deleted
void delete_contents(vector * v);