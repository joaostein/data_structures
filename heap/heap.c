
#include "heap.h"

/* --------------------------------- *
 *
 *   Insert a new value to the Heap
 *
 *   @param {Heap *} heap (required) - Pointer to Heap structure
 *     @property {int} length
 *     @property {int[]} heap
 *
 *   @param {int} value (required) - Value to be inserted to Heap
 *   @return {boolean}
 *
 * --------------------------------- */

int insert_value(Heap *heap, int value) {
    int length = heap->length;
    
    if (length == HEAP_SIZE) {
        printf("Heap is full my boy...\n");
        return FALSE;
    }
    
    if (length == 0) {
        heap->heap[length] = value;
    } else {
        heap->heap[length] = INT_MIN;
        increase_key(heap, heap->length, value);
    }
    
    heap->length += 1;
    return TRUE;
}

/* --------------------------------- *
 *
 *   Increase the current key value based on given index
 *
 *   @param {Heap *} heap (required) - Pointer to Heap structure
 *     @property {int} length
 *     @property {int[]} heap
 *
 *   @param {int} index (required) - Index position of element to be increased
 *   @param {int} increase_value (required) - New value to be increased
 *
 * --------------------------------- */

void increase_key(Heap *heap, int index, int increase_value) {
    int parent_index = floor(index / 2);
    
    if (increase_value < heap->heap[index]) {
        return;
    }
    
    heap->heap[index] = increase_value;
    
    if (heap->heap[parent_index] < increase_value) {
        swap_values(heap, parent_index, index);
        increase_key(heap, parent_index, increase_value);
    }
}

/* --------------------------------- *
 *
 *   Find and return the maximum key value of the heap
 *
 *   @param {Heap *} heap (required) - Pointer to Heap structure
 *     @property {int} length
 *     @property {int[]} heap
 *
 *   @return {int} - Max value of the heap or FALSE (0);
 *
 * --------------------------------- */

int get_max_value(Heap *heap) {
    if (heap->length == 0) {
        printf("Heap is empty my boy...\n");
        return FALSE;
    }
    
    return heap->heap[0];
}

/* --------------------------------- *
 *
 *   Find, remove and return the maximum value of the heap
 *
 *   @param {Heap *} heap (required) - Pointer to Heap structure
 *     @property {int} length
 *     @property {int[]} heap
 *
 *   @return {int} - Max value of the heap or FALSE (0);
 *
 * --------------------------------- */

int extract_max_value(Heap *heap) {
    if (heap->length == 0) {
        printf("Heap is empty my boy...\n");
        return FALSE;
    }
    
    int max_value = heap->heap[0];
    swap_values(heap, 0, heap->length - 1);
    heap->length -= 1;
    max_heapify(heap, 0);
    
    return max_value;
}

/* --------------------------------- *
 *
 *   Check to see if given "node" respects max-heap condition
 *
 *   @param {Heap *} heap (required) - Pointer to Heap structure
 *     @property {int} length
 *     @property {int[]} heap
 *
 *   @param {int} index (required) - Index position of element to be checked
 *
 * --------------------------------- */

void max_heapify(Heap *heap, int index) {
    int left_child_index = get_child_index(index, 'l', heap->length);
    int right_child_index = get_child_index(index, 'r', heap->length);
    int max = index;
    
    if (left_child_index != -1 && left_child_index <= heap->length - 1 && heap->heap[max] <= heap->heap[left_child_index]) {
        max = left_child_index;
    }
    
    if (right_child_index != -1 && right_child_index < heap->length - 1 && heap->heap[max] < heap->heap[right_child_index]) {
        max = right_child_index;
    }
    
    if (max != index) {
        swap_values(heap, max, index);
        max_heapify(heap, max);
    }
}

/* --------------------------------- *
 *
 *   Create a max-heap based on given random heap (not respecting max-heap conditions)
 *
 *   @param {Heap *} heap (required) - Pointer to Heap structure
 *     @property {int} length
 *     @property {int[]} heap
 *
 * --------------------------------- */

void build_max_heap(Heap *heap) {
    for (int i = floor((heap->length -1) / 2); i >= 0; i--) {
        max_heapify(heap, i);
    }
}

/* --------------------------------- *
 *
 *   Sort given array using heapsort algorithm
 *
 *   @param {int[]} array (required) - Array to be sorted
 *
 * --------------------------------- */

void heap_sort(int array[HEAP_SIZE]) {
    // Create a new Heap
    Heap *heap = (Heap*) malloc(sizeof(Heap));
    
    // Initialize heap->heap with given raw data
    memcpy(heap->heap, (array), sizeof heap->heap);
    
    // Force Heap length to reflect new heap data
    heap->length = HEAP_SIZE;
    
    build_max_heap(heap);
    
    for (int i = 0; i < HEAP_SIZE; i++) {
        array[i] = extract_max_value(heap);
    }
}

/* --------------------------------- *
 *
 *   Utility function to swap values of two given positions in an Array
 *
 *   @param {Heap *} heap (required) - Pointer to Heap structure
 *     @property {int} length
 *     @property {int[]} heap
 *
 *   @param {int} first_index (required) - Index position of first element
 *   @param {int} second_index (required) - Index position of second element
 *
 * --------------------------------- */

void swap_values(Heap *heap, int first_index, int second_index) {
    int tmp = heap->heap[first_index];
    heap->heap[first_index] = heap->heap[second_index];
    heap->heap[second_index] = tmp;
}

/* --------------------------------- *
 *
 *   Utility function to get index of the child of given Node
 *
 *   @param {int} index (required) - Index position of element to check child nodes
 *   @param {char} direction (required) - Represents the direction of child ('r' => 'right', 'l' => 'left')
 *
 * --------------------------------- */

int get_child_index(int index, char direction, int length) {
    int root = FALSE;
    
    if (index == 0) {
        root = TRUE;
        index = 1;
    }
    
    if (direction == 'l') {
        index = index * 2;
    } else {
        index = (index * 2) + 1;
    }
    
    if (index > length) {
        return -1;
    }
    
    if (root) {
        return --index;
    } else {
        return ++index;
    }
}

/* --------------------------------- *
 *
 *   Utility function to print all elements in the Heap
 *
 *   @param {Heap *} heap (required) - Pointer to Heap structure
 *     @property {int} length
 *     @property {int[]} heap
 *
 * --------------------------------- */

void print_heap(Heap *heap) {
    printf("\nStart printing Heap: \n\n");
    printf("(Heap length) -> %d\n\n", heap->length);
    for (int i = 0; i < heap->length; i++) {
        printf("(value) -> %d (index) -> %d\n", heap->heap[i], i);
    }
}
