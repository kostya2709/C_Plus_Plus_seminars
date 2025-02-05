#include <stdexcept>
#include <bitset>
#include <iostream>

void bad_bitset() {
    try {
        // throw std::invalid_argumnet("Hello!\n");
        std::bitset<4>{"012"}; // throws std::invalid_argument
    } catch (double x) {

    } catch ( const std::logic_error& ex) {
		std::cout << "Message logic_err: " << ex.what() << std::endl;
		// throw ex;
    } catch ( const std::invalid_argument& ex ) {
        std::cout << "Message invalid_arg: " << ex.what() << std::endl;
    } catch ( const std::exception& ex ) {
      std::cout << "Message exception: " << ex.what() << std::endl;
     } catch ( ... ) {
       std::cout << "Unexpected!\n";
    }
    
}

void bad_alloc() {
    // int* data_ptr = new int [100'000'000'000];
    int* data_ptr = new (std::nothrow) int [100'000'000'000];
    std::cout << "Data_ptr: " << data_ptr << std::endl;
}

int main() {
    // bad_bitset();
    bad_alloc();
}
