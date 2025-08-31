#include <stdio.h>

/*
void receive_array( int input[]) {
	input++;    
	printf("size = %lu\n", sizeof( input));
}
*/

int main() {

    int int_array[10] = {};

    printf("array     = %p\n"
           "&array[0] = %p\n"
           "&array[1] = %p\n"
           "array + 1 = %p\n",
           int_array, &int_array[0], &int_array[1], int_array + 1);

   char str[] = "Hello, World";
   char* str_ptr = str;
   printf("%%p=%p; %%s=%s\n", str, str_ptr);
   
   printf("sizeof(str) = %lu\n", sizeof(str));
   printf("sizeof(str_ptr) = %lu\n", sizeof(str_ptr));



  //  receive_array( int_array);

    return 0;
}
