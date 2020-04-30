#include<stdio.h>
#include<stdlib.h>

#define EPSILON 0.001
#define LEARNING_RATE 0.05

// This buffer will be added to a vector when it is full
#define BUFFER 4

#define VEC_MATH_ERROR_STR "Incorrect application of vector function\n"
#define MEM_ERR_STR "Insufficient memory to perform operation\n"

struct vector_t {
    // Actual array of values in the vector
    float * values;
    // Length of the vector
    int length;
    // The size of vector space allocated to the element
    // Size measured in 'floats'
    int size;
};

struct vector_t vec_null = {NULL, 0, 0};
typedef struct vector_t vector;

void print_vector(vector v);
void push_into(vector * v, float val);
vector zeroes(int len);
vector add(vector v1, vector v2);

int main() {
    return 0;
}


void print_vector(vector v) {
    int i = 0;
    int len = v.length;
    printf("[");
    for(int i = 0; i < len; i++) {
        printf("%0.3f, ", v.values[i]);
    }
    printf("\b]\n");
    printf("Length of vector = %d\n", len);
    printf("Memory allocated: %d floats\n", v.size);
}

void push_into(vector * v, float val) {
    if (v->size == v->length) {
        // If vector is full
        int size = v->size;
        // Allocate for a new array
        float * new_vals = malloc(sizeof(float) * (size + BUFFER));
        if (new_vals == NULL) {
            fprintf(stderr, MEM_ERR_STR);
        }
        // Copy all old values
        for(int i = 0; i < size; i++) {
            new_vals[i] = v->values[i];
        }
        // Insert new value
        new_vals[size] = val;
        // Update metadata
        v->size = size + BUFFER;
        v->length += 1;
        // Return old memory
        free(v->values);
        // Assign new values
        v->values = new_vals;
    } else {
        // If the vector has sufficient space
        int ind = v->length;
        v->values[ind] = val;
        v->length += 1;
    }
}

vector zeroes(int len) {
    int size = len + BUFFER;
    vector retv;
    retv.length = len;
    retv.size = size;
    for(int i = 0; i < len; i++) {
        retv.values[i] = 0;
    }
    return retv;
}

vector add(vector v1, vector v2) {
    vector retv;
    if(v1.length != v2.length) {
        // If both the vectors dont have same length
        // Raise error and return a NULL vector
        fprintf(stderr, VEC_MATH_ERROR_STR);
        retv.values = NULL;
        retv.length = 0;
        retv.size = 0;
    } else {
        // Add vectors with standard procedure
        int len = v1.length;
        retv.values = malloc(sizeof(float) * (v1.length + BUFFER));
        if (retv.values == NULL) {
            fprintf(stderr, MEM_ERR_STR);
        }
        for(int i = 0; i < len; i++) {
            retv.values[i] = v1.values[i] + v2.values[i];
        }
        retv.size = v1.size;
        retv.length = v1.length;
    }
    return retv;
}

