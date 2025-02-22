#include <iostream>
#include <list>

template<typename InputIt, typename T>
InputIt find( InputIt first, InputIt last, const T& value) {
    for ( ; first != last; ++first ) {
        if ( *first == value ) {
            return first;
        }
    }
    return last;
}

int main() {

    std::list<int> seq;
    seq.push_back( 4);
    seq.push_back( 7);
    seq.push_back( 5);


    std::list<int>::iterator it = my_find( seq.begin(), seq.end(), 5);

    if ( it != seq.end() ) {
        std::cout << "Found!\n";
    } else {
        std::cout << "Not Found!\n";
    }

}
