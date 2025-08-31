#include <stdio.h>
#include <stdlib.h>

char* get_str( const char* str) {
    // char* new_str = (char*)calloc(100, sizeof(char));
    char new_str[100] = {};
    new_str[0] = '!';
    for ( int i = 1; *str; ++i )
    {
        new_str[i] = *str;
        ++str;
    }
    char* str_ptr = &new_str[0];
    
    // free(str_ptr);
    return str_ptr;

}


int main() {
    char str_hello[] = "Hello, ";
    char str_world[] = "world!";

    char* str_one = get_str( str_hello);
    printf("str_one: %s\n", str_one);
    char* str_two = get_str( str_world);
    printf("str_one: %s, str_two: %s\n", str_one, str_two);
    printf("str_one_ptr: %p, :%p %d\n", str_one, str_two, str_one == str_two);

    // free( str_one);    
	return 0;
}
