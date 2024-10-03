#include <iostream>
#include <cstdio>

void test_sync_stdio() {
    std::ios::sync_with_stdio( false);
    
	std::cout << "cout output\n"; // << std::endl;
    std::printf( "printf output\n");
    std::cout << "cout output again\n";
	
    std::ios::sync_with_stdio( true);
}

void test_cin_tie() {
    std::cin.tie(0);
	
	int x = 0;
	std::cout << "cout: Hello world\n";
	std::cin >> x;
	
}

int main()
{
	test_sync_stdio();
	test_cin_tie();
            
}
