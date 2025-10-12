#include <stdio.h>

int main() {
	const char* str = "Hello, world!\n";
	const char* world_ptr = str + sizeof("Hello, ");
	printf("world_ptr: %s\n", world_ptr);
	printf("world_ptr[-1]: %c\n", world_ptr[-1]);

	const char* test = "abc";
	char test_arr[] = "abc";
	char* test_ptr = test_arr;

	printf("sizeof(test) = %ld\n", sizeof(test));
	printf("sizeof(\"abc\") = %ld\n", sizeof("abc"));
	printf("sizeof(test_arr) = %ld\n", sizeof(test_arr));
}
