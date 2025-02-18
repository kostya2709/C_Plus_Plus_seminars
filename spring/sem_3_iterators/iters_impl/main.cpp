
#include <cstddef>

template <typename T>
class Vector {
    T* data;
    size_t size;
    size_t cap;

public:

    struct iterator {
    private:
        T* ptr;
    public:
        iterator( T* ptr): ptr( ptr) {}

        T& operator*() {
            return *ptr;
        }

        T* operator->() {
            return ptr;
        }

        iterator& operator++() {
            ++ptr;
            return *this;
        }

    };
    
    iterator begin() const {
        return iterator( data);
    }

};

int main() {
    Vector<int> vec;
    auto iter = vec.begin();
    ++iter;
}
