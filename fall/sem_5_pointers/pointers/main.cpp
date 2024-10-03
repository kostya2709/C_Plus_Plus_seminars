#include <stdio.h>

char global_char;

int main() {
    
	int local_int = 27;

	printf("&global_char = %p;\n"
           "&local_int   = %p\n", &local_int, &global_char);

	int int_val = -1;
	unsigned int unsigned_val = 1;
	long int long_val = 3'000'000;
	float float_val = 2.73;
	double double_val = 3.1415926;
	printf("hello %d %u world %ld %g %lg\n", int_val, unsigned_val, long_val, float_val, double_val);  


	scanf( "%d", &local_int);
	printf( "%d\n", local_int);

   return 0;
}
