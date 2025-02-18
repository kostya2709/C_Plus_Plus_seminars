#include <iterator>
#include <type_traits>

namespace constexpr_sol {

    template <typename Iter>
    void advance( Iter& iter, int n) {
        if constexpr (std::is_same_v<typename std::iterator_traits<Iter>::iterator_category, std::random_access_iterator_tag> ) {
            iter += n;
        } else {
            for ( int i = 0; i < n; ++i, ++iter );
        }
    }

};

