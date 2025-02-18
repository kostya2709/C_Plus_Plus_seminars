#include <algorithm>
#include <iostream>
#include <list>
#include <vector>


template <typename Container>
class back_insert_iterator {
    Container& container;
public:
    back_insert_iterator( Container& container): container(container) {}

    back_insert_iterator<Container>& operator++() {
        return *this;
    }
    
    back_insert_iterator<Container>& operator*() {
        return *this;
    }
    
    back_insert_iterator<Container>& operator=(const typename Container::value_type& elem) {
        container.push_back(elem);
		return *this;
    }

};

struct isEven {
    bool operator()( int x) const {
        return x % 2 == 0;
    }
};

int main() {

    std::list<int> seq = {1, 2, 3, 4, 5};
    std::vector<int> vec;
    std::copy_if( seq.begin(), seq.end(), back_insert_iterator(vec), isEven());

	for (int elem : vec) {
		std::cout << elem << '\n';
	}
}
