
#ifndef LAB2_COMPARER_H
#define LAB2_COMPARER_H

#include <functional>

using namespace std;

template <typename T, typename Comparable = short>
class Comparer{
private:
    function<bool(T, T)> comparerGreat;
public:
    explicit Comparer();

    explicit Comparer(function<Comparable(T)> converter);

    /// If a getLess b - True else false
    bool less(T a, T b){
        return !comparerGreat(a, b);
    }

    bool great(T a, T b){
        return comparerGreat(a, b);
    }

    T& getGreat(T a, T b){
        return great(a, b) ? a : b;
    }

    T& getLess(T a, T b){
        return less(a, b) ? a : b;
    }

private:
    void setComparer(function<bool(T, T)> comparer);

    void checkComparer();
};

template<typename T, typename Comparable>
void Comparer<T, Comparable>::setComparer(function<bool(T, T)> comparer) {
    this->comparerGreat = comparer;
    checkComparer();
}

template<typename T, typename Comparable>
Comparer<T, Comparable>::Comparer() {
    setComparer([](T a, T b) { return a > b; });
}

template<typename T, typename Comparable>
Comparer<T, Comparable>::Comparer(function<Comparable(T)> converter) {
    setComparer([&converter](T a, T b) { return converter(a) > converter(b); });
}

template<typename T, typename Comparable>
void Comparer<T, Comparable>::checkComparer() {
    try {
        comparerGreat(T(), T());
    } catch (exception e){
        throw e;
    }
}


#endif //LAB2_COMPARER_H
