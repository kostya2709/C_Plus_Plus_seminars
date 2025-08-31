#include <stdio.h>
#include <stdlib.h>

int main()
{
    size_t array_size = 1000;
    int* mem = (int*)malloc( array_size * sizeof( int));
    printf( "PTR: %p\n", mem);
    printf( "ptr array size: %p\n", &array_size);
    free( mem);
    // *mem = 2;
}
