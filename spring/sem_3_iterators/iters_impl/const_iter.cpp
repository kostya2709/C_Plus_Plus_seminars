#include <type_traits>
#include <cstddef>

template <typename T>
class Vector {
    T* data;
    size_t size;
    size_t cap;

public:

    template <bool isConst>
    struct common_iterator {
    private:
        typename std::conditional<isConst, const T*, T*>::type ptr;
    public:
        common_iterator( T* ptr): ptr( ptr) {}

		common_iterator(const Vector<T>::common_iterator<false>& other) : ptr(ptr) {}

        typename std::conditional<isConst, const T&, T&>::type operator*() {
            return *ptr;
        }

        typename std::conditional<isConst, const T*, T*>::type operator->() {
            return ptr;
        }

        common_iterator& operator++() {
            ++ptr;
            return *this;
        }

    };

	/*
	template<typename Dummy>
	struct common_iterator<true, Dummy> : common_iterator<tru> {
		common_iterator(common_iterator<false> other) : ptr(other.ptr) {}
	};
*/
   
    using iterator = common_iterator<false>;
    using const_iterator = common_iterator<true>;

    iterator begin() const {
        return iterator( data);
    }
    
	const_iterator cbegin() const {
        return const_iterator( data);
    }

};

int main() {
    Vector<int> vec;
    auto iter = vec.begin();
    ++iter;
    
	auto const_iter = vec.cbegin();
    ++const_iter;
	// *const_iter = 0;
	
	Vector<int>::const_iterator const_iter2 = iter;
//	Vector<int>::iterator iter2 = const_iter;
}

