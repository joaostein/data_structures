
#ifndef heapsort_heap_h
#define heapsort_heap_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

#define HEAP_SIZE 10
#define TRUE 1
#define FALSE 0

typedef struct Heap {
    int length;
    int heap[HEAP_SIZE];
} Heap;

//Insert a new value to the Heap
int insert_value(Heap *, int);

// Increase the current key value based on given index
void increase_key(Heap *, int, int);

// Find and return the maximum key value of the heap
int get_max_value(Heap *);

// Find, remove and return the maximum value of the heap
int extract_max_value(Heap *);

// Check to see if given "node" respects max-heap condition
void max_heapify(Heap *, int);


// ==== Heapsort Functions ====

// Create a max-heap based on given random heap
void build_max_heap(Heap *);

// Sort given array using heapsort algorithm
void heap_sort(int *);


// ==== Utility Functions ====

// Swap values of two given positions in an Array
void swap_values(Heap *, int, int);

// Get index of the child of given Node
int get_child_index(int, char, int);

// Print all elements in the Heap
void print_heap(Heap *);

#endif
