#include <iterator>
#include <type_traits>
#include <iostream>

namespace spec {

    template <typename Iter, typename IterCategory>
    void advance_helper( Iter& iter, int n, IterCategory) {
        for ( int i = 0; i < n; ++iter, ++i );
    }
    
    template <typename Iter>
    void advance_helper( Iter& iter, int n, std::random_access_iterator_tag) {
        iter += n;
    }


    template <typename Iter>
    void advance( Iter& iter, int n) {
        advance_helper( iter, n, typename std::iterator_traits<Iter>::iterator_category());
    }


};

