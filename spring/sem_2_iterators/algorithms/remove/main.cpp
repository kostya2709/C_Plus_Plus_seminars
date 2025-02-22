#include <iostream>
#include <string>
#include <algorithm>

template <typename ForwardIt, typename T>
ForwardIt remove(ForwardIt first, ForwardIt last, T& value)
{
    first = std::find(first, last, value);
    if ( first != last ) {
        for ( ForwardIt i = first; ++i != last ; ) {
            if ( !(*i == value) ) {
                *(first++) = *i;
            }
        }
    }
    return first;
}

int main() {

    std::string str("Some basic  str ing");
    std::string::iterator end = remove( str.begin(), str.end(), ' ');

    for ( std::string::iterator it = str.begin(); it != end; ++it ) {
        std::cout << *it;
	}

	std::cout << "\n\nThe whole string: " << str << '\n';
}
