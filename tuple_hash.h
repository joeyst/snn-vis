
#include <boost/functional/hash.hpp>

// SOURCE: https://stackoverflow.com/a/10405129 
template <typename Container> // we can make this generic for any container [1]
struct container_hash {
    std::size_t operator()(Container const& c) const {
        return boost::hash_range(c.begin(), c.end());
    }
};
