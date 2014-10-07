
#include "heap.h"

int main(int argc, const char * argv[]) {
    
    // Create a new Heap
    Heap *heap = (Heap*) malloc(sizeof(Heap));
    // Initialize it's length to zero. Question: Is there a way in C to initialize it to zero on the "construction" of the struct?
    heap->length = 0;
    
    // Insert some dummy values
    insert_value(heap, 4);
    insert_value(heap, 1);
    insert_value(heap, 3);
    insert_value(heap, 2);
    insert_value(heap, 16);
    insert_value(heap, 9);
    insert_value(heap, 10);
    insert_value(heap, 14);
    insert_value(heap, 8);
    insert_value(heap, 7);
    
    // Print Heap to make sure it's a max-heap
    print_heap(heap);
    
    // Feel free to uncomment these lines to check that it's working. Question: Is there a way to unit test in C?
    // printf("\n== (Extracted) -> %d\n", extract_max_value(heap));
    // printf("\n== (Max Value) -> %d\n", get_max_value(heap));
    
    return 1;
}
