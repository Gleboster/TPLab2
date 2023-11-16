
#ifndef LAB2_COMPARER_H
#define LAB2_COMPARER_H

#include <functional>

using namespace std;

template <typename T>
class Comparer{
private:
    function<bool(const T&, const T&)> comparerGreat;

public:
    explicit Comparer();

    template<class Comparable>
    Comparer(function<Comparable(const T &)> *converter);

    /// If a getLessEqual b - True else false
    bool lessEqual(const T& a, const T& b){
        return !comparerGreat(a, b);
    }

    bool great(const T& a,const T& b){
        return comparerGreat(a, b);
    }

    T& getGreat(const T& a,const T& b){
        return great(a, b) ? a : b;
    }

    T& getLessEqual(const T& a,const T& b){
        return lessEqual(a, b) ? a : b;
    }

private:
    void setComparer(function<bool(const T&,const T&)> comparer);
    void checkComparer();
};

template<typename T>
template<class Comparable>
Comparer<T>::Comparer(function<Comparable(const T &)> *converter) {
    setComparer([&converter](const T& a,const T& b) { return (*converter)(a) > (*converter)(b); });
}

template<typename T>
void Comparer<T>::setComparer(function<bool(const T&,const T&)> comparer) {
    this->comparerGreat = comparer;
    //checkComparer();
}

template<typename T>
Comparer<T>::Comparer() {
    setComparer([](const T& a,const T& b) { return a > b; });
}


template<typename T>
void Comparer<T>::checkComparer() {
    try {
        comparerGreat(T(), T());
    } catch (exception e){
        throw e;
    }
}


#endif //LAB2_COMPARER_H
