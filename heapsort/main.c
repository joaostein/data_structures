
#include "heap.h"

int main(int argc, const char * argv[]) {
    
    // Unordered array
    int array[HEAP_SIZE] = { 4, 1, 3, 2, 16, 9, 10, 14, 8, 7 };
    
    // Send array to heap_sort to be ordered
    heap_sort(array);
    
    // Print ordered array elements
    for (int i = 0; i < HEAP_SIZE; i++) {
        printf("%d - ", array[i]);
    }
    
    return 1;
}
