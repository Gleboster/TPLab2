
#ifndef LAB2_SORTEDLIST_H
#define LAB2_SORTEDLIST_H

#include <functional>
#include <iostream>
#include <string>
#include "Comparer.h"
#include "mathSorting.h"

using namespace std;

template<typename T>
class SortedList {
private:
    T *base;
    int count;
    int capacity;

    Comparer<T> *comparer;
public:
    SortedList(const T *array, const int length, Comparer<T> *comparer);

    T get(int index) const;

    void insert(const T &value);

    T remove(int index);

    bool isEmpty() const {
        return count == 0;
    };

    int getCount() const {
        return count;
    };

    int getCapacity() const {
        return capacity;
    }

private:
    void checkSize();

    void expand();

    void fillBase(const T *from, const int length);

    void sort();

    int findIndexInsert(const T value, int i_from, int i_to) const;

    void shiftElementsRight(int i_from, int i_to);
    void shiftElementsLeft(int i_from, int i_to);

    string to_string() const {
        string result = "";
        for (int i = 0; i < count; i++)
            result += std::to_string(base[i]) + " ";
        return result;
    }
};

template<typename T>
T SortedList<T>::get(int index) const {
    return base[index];
}

template<typename T>
SortedList<T>::SortedList(const T *array, const int length, Comparer<T> *comparer) {
    count = length;
    capacity = roundToPowerOfTwo(length);
    base = new T[capacity];
    fillBase(array, length);

    this->comparer = comparer;

    sort();
}

template<typename T>
void SortedList<T>::insert(const T &value) {
    checkSize();
    int indexForInsert = findIndexInsert(value, 0, count - 1);

    shiftElementsRight(indexForInsert, count - 1);
    base[indexForInsert] = value;
    count++;
}


template<typename T>
T SortedList<T>::remove(int index) {
    T result = base[index];
    shiftElementsLeft(index + 1, count - 1);
    count--;

    return result;
}

template<typename T>
void SortedList<T>::checkSize() {
    if (count + 1 == capacity)
        expand();
}

template<typename T>
void SortedList<T>::expand() {
    T *oldBase = base;
    base = new T[capacity * 2];
    capacity *= 2;

    fillBase(oldBase, count);

    delete oldBase;
}

template<typename T>
void SortedList<T>::fillBase(const T *from, const int length) {
    for (int i = 0; i < capacity; ++i) {
        if (i < count)
            base[i] = from[i];
        else
            base[i] = T();
    }
}

template<typename T>
void SortedList<T>::sort() {
    for (int i = 0; i < count; i++) {
        T value = base[i];
        int indexForInsert = findIndexInsert(value, 0, i);

        shiftElementsRight(indexForInsert, i - 1);
        base[indexForInsert] = value;
        int a = 0;
    }
}

template<typename T>
int SortedList<T>::findIndexInsert(const T value, int i_from, int i_to) const {
    for (int i = i_from; i <= i_to; ++i)
        if (comparer->less(value, base[i]))
            return i;
    return 0;
}

template<typename T>
void SortedList<T>::shiftElementsRight(int i_from, int i_to) {
    for (int i = i_to; i >= i_from; --i)
        base[i + 1] = base[i];
}

template<typename T>
void SortedList<T>::shiftElementsLeft(int i_from, int i_to) {
    for (int i = i_from; i <= i_to; ++i)
        base[i - 1] = base[i];
}

#endif //LAB2_SORTEDLIST_H
