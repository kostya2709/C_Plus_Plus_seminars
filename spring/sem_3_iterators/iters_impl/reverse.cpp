#include <type_traits>
#include <cstddef>
#include <iterator>

template <typename Iter>
struct reverse_iterator {
private:
    Iter iter;
public:

    reverse_iterator( const Iter& iter): iter(iter) {}

    reverse_iterator<Iter>& operator++() {
        --iter;
        return *this;
    }

    Iter base() const {
        return iter;
    }

};

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
   
    using iterator = common_iterator<true>;
    using const_iterator = common_iterator<false>;


    using reverse_iterator = std::reverse_iterator<iterator>;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;

    iterator begin() const {
        return iterator( data);
    }

};

int main() {
    Vector<int> vec;
    auto iter = vec.begin();
    ++iter;
}

