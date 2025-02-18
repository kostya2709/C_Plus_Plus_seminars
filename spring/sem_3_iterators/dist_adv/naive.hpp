#include <iterator>
#include <type_traits>

namespace naive {

    template <typename Iter>
    void advance( Iter& iter, int n) {
        if ( std::is_same<typename std::iterator_traits<Iter>::iterator_category, std::random_access_iterator_tag>::value ) {
            iter += n;
        } else {
            for ( int i = 0; i < n; ++i, ++iter );
        }
    }

};

